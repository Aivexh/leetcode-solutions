
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                // Check whether we have a pair of ')'
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    // Insert ')' to complete the pair
                    insertions++;
                }

                if (open > 0) {
                    open--;
                } 
                else {
                    // Insert '(' to match this closing pair
                    insertions++;
                }
            }
        }

        // Each unmatched '(' needs two ')'
        insertions += 2 * open;

        return insertions;
    }
};