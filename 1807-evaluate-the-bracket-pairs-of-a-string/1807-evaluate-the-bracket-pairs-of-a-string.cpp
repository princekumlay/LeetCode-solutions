class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;
        for(const auto& pair : knowledge){
            mp[pair[0]] = pair[1];
        }

        string res = "";
        int n = s.length();
        int i = 0;

        while(i < n){
            if(s[i] == '('){
                i++; //skip '('
                string key = "";
                while(i < n && s[i] != ')'){
                    key += s[i];
                    i++;
                }
                i++; //skip ")"

                auto it = mp.find(key);
                if(it != mp.end()){
                    res += it->second;
                }
                else{
                    res += '?';
                }
            }
            else{
                res += s[i];
                i++;
            }
        }

        return res;
    }
};