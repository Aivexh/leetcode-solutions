class Solution {
public:

    vector<string> ans;

    void solve(string s, int start, int lastRemove, char open, char close) {

        int balance = 0;

        for (int i = start; i < s.size(); i++) {

            if (s[i] == open)
                balance++;
            else if (s[i] == close)
                balance--;

            // Too many closing brackets
            if (balance < 0) {

                for (int j = lastRemove; j <= i; j++) {

                    // Don't remove duplicate ')' at the same level
                    if (s[j] == close &&
                        (j == lastRemove || s[j - 1] != close)) {

                        string next = s.substr(0, j) +
                                      s.substr(j + 1);

                        solve(next, i, j, open, close);
                    }
                }

                return;
            }
        }

        // No extra ')' found.
        // Now check the opposite direction.
        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        if (open == '(') {

            solve(reversed, 0, 0, ')', '(');

        } else {

            // Both directions are valid
            ans.push_back(reversed);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        solve(s, 0, 0, '(', ')');

        return ans;
    }
};