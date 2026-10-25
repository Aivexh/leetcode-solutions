class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark as water/visited to avoid infinite loops
        grid[r][c] = 1;
        
        // Check 4-directional neighbors
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        // Fast I/O for LeetCode
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        // 1. Flood-fill all land (0) touching the outer boundary edges
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(grid, r, c, rows, cols);
                }
            }
        }
        
        // 2. Count remaining unvisited land (0), which are guaranteed closed islands
        int count = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    count++;
                    dfs(grid, r, c, rows, cols);
                }
            }
        }
        
        return count;
    }
};
