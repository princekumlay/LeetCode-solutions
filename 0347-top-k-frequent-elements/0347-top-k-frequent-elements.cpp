class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> frequency;
        int n = nums.size();
        for(int n: nums){
            frequency[n]++;
        }

        //hash table + sort approach
        //copy frequency to vector
        // vector<pair<int, int>> entries(frequency.begin(), frequency.end());

        // //sort entries based on frequency
        // sort(entries.begin(), entries.end(), [](const pair<int , int>& a, const pair<int, int>& b){
        //     return a.second > b.second;
        // });

        // vector<int> result;
        // for(int i = 0; i < k; i++){
        //     result.push_back(entries[i].first);
        // }


        //optimized approach bucket sort
        vector<vector<int>> bucket(n + 1);
        for(const auto& [num, freq]: frequency){
            bucket[freq].push_back(num);
        }

        vector<int> result;
        for(int f = n; f >= 1; f--){
            for(int num: bucket[f]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};