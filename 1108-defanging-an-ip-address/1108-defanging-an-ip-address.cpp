class Solution {
public:
    string defangIPaddr(string address) {
        int originalLen = address.length();
        int countDot = 0;
        
        for(char c: address){
            if(c == '.'){
                countDot++;
            }
        }

        int newLen = originalLen + countDot * 2;
        address.resize(newLen);//it will resize the string address
        int i = originalLen - 1;//read index 
        int j = newLen - 1;//write index

        while(i >= 0){
            if(address[i] == '.'){
                address[j--] = ']';
                address[j--] = '.';
                address[j--] = '[';
            }
            else{
                address[j--] = address[i];
            }
            i--;
        }

        return address;
    }
};