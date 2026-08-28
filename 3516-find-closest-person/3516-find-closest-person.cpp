class Solution {
public:
    int findClosest(int x, int y, int z) {
        int steps_x=abs(x-z);
        int steps_y=abs(y-z);
        if(steps_x<steps_y){
            return 1;
        }
        else if(steps_x>steps_y){
            return 2;
        }
        else
        return 0;
        
    }
};