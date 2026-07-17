class Solution {
public:
    int romanToInt(string s) {
        //quick array lookup for ASCII values of Roman characters
        int roman[128];
         roman['I'] = 1;
         roman['V'] = 5;
         roman['X'] = 10;
         roman['L'] = 50;
         roman['C'] = 100;
         roman['D'] = 500;
         roman['M'] = 1000;

        int total = 0;
        int n = s.length();

        for(int i = 0; i < n; i ++){
            //if current value is less then next then subtract it
            if(i < n - 1 && roman[s[i]] < roman[s[i + 1]]){
                total -= roman[s[i]];
            }
            else{
                total += roman[s[i]];
            }
        }
        return total;
    }
};