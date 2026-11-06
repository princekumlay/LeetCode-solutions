class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // Step 1: Pair queries with their original indices and sort by query time
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // Step 2: Sort logs by time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int i = 0, j = 0;
        int logsSize = logs.size();
        unordered_map<int, int> serverCount;
        
        // Step 3: Process each query using sliding window pointers
        for (auto& qPair : sortedQueries) {
            int qTime = qPair.first;
            int originalIdx = qPair.second;
            int windowStart = qTime - x;
            int windowEnd = qTime;
            
            // Include logs up to windowEnd
            while (j < logsSize && logs[j][1] <= windowEnd) {
                serverCount[logs[j][0]]++;
                j++;
            }
            
            // Exclude logs older than windowStart
            while (i < logsSize && logs[i][1] < windowStart) {
                serverCount[logs[i][0]]--;
                if (serverCount[logs[i][0]] == 0) {
                    serverCount.erase(logs[i][0]);
                }
                i++;
            }
            
            // Servers with zero requests = total servers - servers with requests
            ans[originalIdx] = n - serverCount.size();
        }
        
        return ans;
    }
};