class Solution {
public:
    bool judgeCircle(string moves) {
        
        int x = 0;//tracks left and right co-ordinates
        int y = 0;//tracks up and down co-ordinates

        for(char c: moves){
            if(c == 'U') y++;
            else if(c == 'D') y--;
            else if(c == 'R') x++;
            else if(c == 'L') x--;
        }

        return (x == 0 && y == 0);
    }
};