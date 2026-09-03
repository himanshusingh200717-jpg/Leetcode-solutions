class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int dist=0;
        while(mainTank>=5&&additionalTank>0){
            mainTank-=5;
            dist+=50;
            mainTank+=1;
            additionalTank-=1;

        }
        return dist+mainTank*10;
        
        
    }
};