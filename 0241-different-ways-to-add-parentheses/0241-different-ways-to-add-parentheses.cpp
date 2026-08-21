class Solution {
public:
    vector<int> solve(string expression) {

        vector<int> result;

        for (int i = 0; i < expression.length(); i++) {

            char op = expression[i];

            // If it is an operator, split the expression
            if (op == '+' || op == '-' || op == '*') {

                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftResults = solve(left);
                vector<int> rightResults = solve(right);

                // Combine every possible left result
                // with every possible right result
                for (int a : leftResults) {
                    for (int b : rightResults) {

                        if (op == '+') {
                            result.push_back(a + b);
                        }
                        else if (op == '-') {
                            result.push_back(a - b);
                        }
                        else {
                            result.push_back(a * b);
                        }
                    }
                }
            }
        }

        // If there was no operator, expression is just a number
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};