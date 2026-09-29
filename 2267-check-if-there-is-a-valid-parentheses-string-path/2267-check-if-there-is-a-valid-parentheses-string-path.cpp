class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        // dp[j][balance] = can we reach current row's cell j
        vector<vector<bool>> dp(n, vector<bool>(m + n, false));

        // Starting cell must be '('
        if (grid[0][0] == ')')
            return false;

        dp[0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                vector<bool> cur(m + n, false);

                for (int balance = 0; balance <= m + n - 1; balance++) {

                    int prevBalance = balance - change;

                    if (prevBalance < 0)
                        continue;

                    // Come from top
                    if (i > 0 && dp[j][prevBalance])
                        cur[balance] = true;

                    // Come from left
                    if (j > 0 && dp[j - 1][prevBalance])
                        cur[balance] = true;
                }

                dp[j] = cur;
            }
        }

        // We need balance = 0 at bottom-right
        return dp[n - 1][0];
    }
};