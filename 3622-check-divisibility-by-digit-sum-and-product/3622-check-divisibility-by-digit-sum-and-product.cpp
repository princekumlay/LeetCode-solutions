class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int digit_to_divide = n;
        while(n){
            sum += n % 10;
            product *= n % 10;
            n /= 10;
        }
        if((digit_to_divide % (sum + product)) == 0) return true;
        return false;
    }
};