#include <vector>
#include <queue>
#include <unordered_set>
#include <numeric>

class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        // Step 1: Build graph
        std::vector<std::vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        // Step 2: Find all suspicious methods via BFS/DFS
        std::vector<bool> isSuspicious(n, false);
        std::queue<int> q;
        
        q.push(k);
        isSuspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!isSuspicious[neighbor]) {
                    isSuspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Check if any non-suspicious method invokes a suspicious method
        for (const auto& inv : invocations) {
            int u = inv[0], v = inv[1];
            if (!isSuspicious[u] && isSuspicious[v]) {
                // Cannot remove suspicious methods; return all methods
                std::vector<int> allMethods(n);
                std::iota(allMethods.begin(), allMethods.end(), 0);
                return allMethods;
            }
        }

        // Step 4: Collect all remaining non-suspicious methods
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!isSuspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};