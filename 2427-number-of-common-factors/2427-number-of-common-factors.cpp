class Solution {
public:
    int commonFactors(int a, int b) {
        int n=a>b?b:a;
        int count=1;
        for(int i=2;i<=n;i++){
            if(a%i==0&&b%i==0)
            count++;
        }
        return count;
        
    }
};