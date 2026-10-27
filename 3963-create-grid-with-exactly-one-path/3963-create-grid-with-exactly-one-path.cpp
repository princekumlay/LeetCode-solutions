class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Initialize an m x n grid filled with '#' (obstacles)
        vector<string> grid(m, string(n, '#'));
        
        // Fill the first row with '.' (moving all the way right)
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        
        // Fill the last column with '.' (moving all the way down)
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};