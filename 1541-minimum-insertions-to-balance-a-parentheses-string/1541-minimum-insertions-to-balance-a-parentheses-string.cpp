class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int insertion = 0, open = 0;

        for(int i = 0; i < n; i++){
            
            if(s[i] == '(') open++;

            else{
                //check if we have pair "))"
                if(i + 1 < n && s[i + 1] == ')'){
                    i++; //skip second ')'
                }
                else{
                    insertion++; //need to insert ')' to make pair "))"
                }

                //balance with opening bracket '('
                if(open > 0){
                    open--;
                }
                else{
                    insertion++; //need to insert '(' to balance "))"
                }
            }
        }

        return insertion + open * 2;
    }
};