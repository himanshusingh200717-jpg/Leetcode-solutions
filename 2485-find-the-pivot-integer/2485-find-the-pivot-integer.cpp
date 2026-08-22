class Solution {
public:
    int pivotInteger(int n) {
        int rightsum=0;
        if(n==1)return 1;
        int totalsum=(n*(n+1))/2;
        for(int i=n;i>0;i--){
            rightsum+=i;
            if((totalsum-i)==rightsum+i-1)
            return i-1;
            else
            totalsum-=i;
        }
        return -1;
        
    }
};