#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int max_energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1, start_c = -1;
        int litter_cnt = 0;
        
        // Map litter coordinates to bit positions 0..K-1
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_r = i;
                    start_c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_cnt++;
                }
            }
        }
        
        int target_mask = (1 << litter_cnt) - 1;
        
        // max_energy_seen[r][c][mask]
        vector<vector<vector<int>>> max_energy_seen(
            m, vector<vector<int>>(n, vector<int>(1 << litter_cnt, -1))
        );
        
        // Queue stores {r, c, mask, current_energy, steps}
        queue<tuple<int, int, int, int, int>> q;
        
        q.push({start_r, start_c, 0, max_energy, 0});
        max_energy_seen[start_r][start_c][0] = max_energy;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [r, c, mask, e, steps] = q.front();
            q.pop();
            
            if (mask == target_mask) return steps;
            if (e == 0) continue; // Out of energy to move further
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                // Out of bounds or obstacle check
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }
                
                int next_e = e - 1;
                int next_mask = mask;
                char cell = classroom[nr][nc];
                
                if (cell == 'R') {
                    next_e = max_energy; // Reset energy
                } else if (cell == 'L' && litter_id[nr][nc] != -1) {
                    next_mask |= (1 << litter_id[nr][nc]);
                }
                
                // Pruning check
                if (next_e > max_energy_seen[nr][nc][next_mask]) {
                    max_energy_seen[nr][nc][next_mask] = next_e;
                    q.push({nr, nc, next_mask, next_e, steps + 1});
                }
            }
        }
        
        return -1;
    }
};