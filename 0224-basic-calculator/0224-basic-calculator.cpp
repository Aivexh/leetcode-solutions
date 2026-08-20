class Solution {
public:
    int calculate(string s) {
        int i = 0;

        function<long long()> solve = [&]() {
            long long result = 0;
            long long num = 0;
            int sign = 1;

            while (i < s.length()) {

                if (isdigit(s[i])) {
                    num = 0;

                    while (i < s.length() && isdigit(s[i])) {
                        num = num * 10 + (s[i] - '0');
                        i++;
                    }

                    result += sign * num;
                }

                else if (s[i] == '+') {
                    sign = 1;
                    i++;
                }

                else if (s[i] == '-') {
                    sign = -1;
                    i++;
                }

                else if (s[i] == '(') {
                    i++;
                    result += sign * solve();
                }

                else if (s[i] == ')') {
                    i++;
                    return result;
                }

                else {
                    i++;   // space
                }
            }

            return result;
        };

        return (int)solve();
    }
};