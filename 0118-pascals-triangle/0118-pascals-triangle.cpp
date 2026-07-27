class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++) {
            // Initialize row i with (i + 1) elements, all set to 1
            vector<int> row(i + 1, 1);

            // Calculate intermediate elements from the previous row
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(row);
        }

        return result;
    }
};