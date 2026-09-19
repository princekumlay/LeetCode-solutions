class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        //point on/inside rect nearest to circle center
        //clamp finds the closest point to the center point
        int closestX = clamp(xCenter, x1, x2);
        int closestY = clamp(yCenter, y1, y2);

        //difference between closest points and center of circle
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        //check for squared distance satisfies the condition(dx^2 + dy^2 <= radius^2)
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};