class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        //coordinate of 1's from both matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) ones1.push_back({i, j});
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        //store frequency of each shift vector
        unordered_map<string, int> shift_count;
        int max_overlap = 0;

        for(auto p1 : ones1){
            for(auto p2 : ones2){
                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;

                //unique key for offset vector
                string key = to_string(dr) + "," + to_string(dc);

                shift_count[key]++;
                max_overlap = max(max_overlap, shift_count[key]);
            }
        }

        return max_overlap;
    }
};