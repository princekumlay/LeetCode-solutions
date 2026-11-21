class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> lastSeen(26, -1);

        // DFS 1: Find the closest matching ancestor for every node
        auto findNewParents = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            if (lastSeen[c] != -1) {
                newParent[u] = lastSeen[c];
            }

            int prev = lastSeen[c];
            lastSeen[c] = u;

            for (int v : adj[u]) {
                self(self, v);
            }

            // Backtrack so this node doesn't affect other branches
            lastSeen[c] = prev;
        };

        findNewParents(findNewParents, 0);

        // Rebuild adjacency list with the updated parent pointers
        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; ++i) {
            newAdj[newParent[i]].push_back(i);
        }

        // DFS 2: Calculate subtree sizes on the final tree
        vector<int> ans(n, 1);
        auto countSizes = [&](auto& self, int u) -> int {
            for (int v : newAdj[u]) {
                ans[u] += self(self, v);
            }
            return ans[u];
        };

        countSizes(countSizes, 0);
        return ans;
    }
};