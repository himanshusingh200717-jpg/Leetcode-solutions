class Solution {
public:
int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>t(n+1);
        int count=0;
        t[1]=1;
        for(int day=2;day<=n;day++){
             if(day-delay>0)
            count=(count+t[day-delay])%mod;
            if(day-forget>0)
            count=(count-t[day-forget]+mod)%mod; 
            t[day]=count;
        }
        int result=0;
        for(int day=n-forget+1;day<=n;day++){
            if(day>0)
            result=(result+t[day])%mod;
        }
        return result;

    }
};