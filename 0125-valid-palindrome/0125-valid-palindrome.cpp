class Solution {
public:
    bool isPalindrome(string s) {
        string result;
        for(char &c : s){
            if((c >= 'A' && c <= 'Z')){
                result.push_back(c + 32);
            }
            else if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                result += c;
            }
        }

        int i = 0, j = result.length() - 1;
        while(i < j){
            if(result[i] != result[j]){
                return false;
            }
           i++;
           j--;
        }

        return true;
    }
};   