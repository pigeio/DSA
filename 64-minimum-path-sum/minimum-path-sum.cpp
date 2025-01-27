class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& t) {
        // Base case: if we are at the bottom-right cell
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        // Out-of-bound check
        if (i >= m || j >= n) {
            return INT_MAX; // Treat as infinite cost
        }

        // Check memoization table
        if (t[i][j] != -1) {
            return t[i][j];
        }

        // Recursive calls for right and down paths
        int right = solve(grid, i, j + 1, m, n, t);
        int down = solve(grid, i + 1, j, m, n, t);

        // Store the minimum path sum in the memoization table
        return t[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        // Memoization table of size m x n initialized with -1
        vector<vector<int>> t(m, vector<int>(n, -1));

        // Start solving from the top-left corner
        return solve(grid, 0, 0, m, n, t);
    }
};
