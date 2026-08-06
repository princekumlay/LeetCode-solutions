class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int product = 1;
            int tempNumber = n;

            while(tempNumber > 0){
                product *= (tempNumber % 10);
                tempNumber /= 10;
            }

            if(product % t == 0){
                return n;
            }
            n++;
        }
    }
};