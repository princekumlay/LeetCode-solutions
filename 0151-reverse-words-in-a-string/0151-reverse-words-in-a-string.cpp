class Solution {
public:
    string reverseWords(string s) {
        //O(N) space approach
        // int right = s.length() - 1;
        // string result = "";

        // while(right >= 0){
        //     //skip spaces
        //     while(right >= 0 && s[right] == ' ') right--;
        //     if(right < 0) break;

        //     //find start and length of word
        //     int j = right;
        //     while(right >= 0 && s[right] != ' ') right--;

        //     //append word
        //     if(!result.empty()) result += " ";
        //     result += s.substr(right + 1, j - right);

        // }

        // return result;


        //O(1) space approach
        int n = s.length();
        int i = 0, j = 0;

        //remove spaces in place using two pointers
        while(j < n){

            while(j < n && s[j] == ' ') j++; //skip spaces
            while(j < n && s[j] != ' ') s[i++] = s[j++]; //keep word
            while(j < n && s[j] == ' ') j++; // skip space

            if(j < n) s[i++] = ' '; //single space after word
        }

        s.resize(i); //resize the string with word and valid spaces

        reverse(s.begin(), s.end());//reverse entire string

        //reverse word by word
        int start = 0;
        for(int end = 0; end <= s.length(); end++){
            if(end == s.length() || s[end] == ' '){
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};