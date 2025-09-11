class Solution {
public:
    int rows, cols;
    int t[71][71][71];

    int solve(vector<vector<int>>& grid, int r, int c1, int c2) {
        if (r >= rows) return 0;

        if (t[r][c1][c2] != -1) return t[r][c1][c2];

        // collect cherries
        int cherries = grid[r][c1];
        if (c1 != c2) {
            cherries += grid[r][c2];
        }

        int ans = 0;
        // try all 9 moves (robot1: -1,0,1), (robot2: -1,0,1)
        for (int dc1 = -1; dc1 <= 1; dc1++) {
            for (int dc2 = -1; dc2 <= 1; dc2++) {
                int newC1 = c1 + dc1;
                int newC2 = c2 + dc2;
                if (newC1 >= 0 && newC1 < cols && newC2 >= 0 && newC2 < cols) {
                    ans = max(ans, solve(grid, r + 1, newC1, newC2));
                }
            }
        }

        return t[r][c1][c2] = cherries + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        memset(t, -1, sizeof(t));

        return solve(grid, 0, 0, cols - 1);
    }
};
