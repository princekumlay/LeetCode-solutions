class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(const string& op: operations){
            if(op[1] == '+'){
                x++;
            }
            else{
                x--;
            }

            //ternary operator
            // x += (op[1] == '+') ? 1 : -1;
        }
        return x;
    }
};