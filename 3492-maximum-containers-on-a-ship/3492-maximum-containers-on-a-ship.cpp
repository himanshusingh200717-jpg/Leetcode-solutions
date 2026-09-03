class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int num=n*n;
        int cnt=0;
        while(maxWeight>=w){
            maxWeight-=w;
            cnt++;
        }
        if(num>cnt)return cnt;
        else
        return num;
    }
};