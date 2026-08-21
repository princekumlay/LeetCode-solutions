class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        // //brute force pairwise approach
        // int n = strs.size();
        // vector<bool> visited(n, false);
        // if(strs.empty()) return result;

        // for(int i = 0; i < n; ++i){
        //     if(visited[i]) continue;

        //     vector<string> group = {strs[i]};
        //     visited[i] = true;
            
        //     string sorted_i = strs[i];
        //     sort(sorted_i.begin(), sorted_i.end());

        //     for(int j = i + 1; j < n; ++j){
        //         if(visited[j]) continue;

        //         string sorted_j = strs[j];
        //         sort(sorted_j.begin(), sorted_j.end());

        //         if(sorted_i == sorted_j){
        //             group.push_back(strs[j]);
        //             visited[j] = true;
        //         }
        //     }

        //     result.push_back(group);
        // }


        //optimized signature map apporach
        unordered_map<string, vector<string>> group;
        for(const string& word: strs){
            string sig = word;
            sort(sig.begin(), sig.end());
            group[sig].push_back(word);
        }

        result.reserve(group.size());
        for(auto& pair: group){
            result.push_back(move(pair.second));
        }

        return result;
    }
};