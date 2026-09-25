class Solution {
public:

    set<string> combine(set<string>& A, set<string>& B) {
        set<string> result;

        for (string a : A) {
            for (string b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    set<string> parse(string& expression, int& i) {

        set<string> result;
        set<string> current;

        while (i < expression.size() && expression[i] != '}') {

            if (expression[i] == ',') {
                // Union current into result
                for (auto& word : current)
                    result.insert(word);

                current.clear();
                i++;
            }

            else if (expression[i] == '{') {

                i++; // skip '{'

                set<string> inside = parse(expression, i);

                i++; // skip '}'

                if (current.empty()) {
                    current = inside;
                } 
                else {
                    current = combine(current, inside);
                }
            }

            else {
                // lowercase letter
                string letter(1, expression[i]);
                i++;

                set<string> single = {letter};

                if (current.empty()) {
                    current = single;
                } 
                else {
                    current = combine(current, single);
                }
            }
        }

        // Add last concatenation component
        for (auto& word : current)
            result.insert(word);

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};