class Solution {
public:
    string frequencySort(string s) {
        //get frequency of every character
        map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }

        //stores char and their frequency in vector to sort them later
        vector<pair<char, int>> temp(mp.begin(), mp.end());
        sort(temp.begin(), temp.end(), [](const pair<char, int>& a, const pair<char, int>& b){
            if(a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

        //store elemenst in a result vec
        string result;
        for(const auto& ele : temp){
            int i = 0;
            while(i < ele.second){
                result += ele.first;
                i++;
            }
        }

        return result;
    }
};