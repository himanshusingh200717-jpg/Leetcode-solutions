class Solution {
public:
int mod=1e9+7;
int t[1001];
int solve(int day, int delay, int forget){
    if(day==1)return 1;
    if(t[day]!=-1)return t[day];
    int result=0;
    for(int d=day-forget+1;d<=day-delay;d++){
        if(d>0)
        result=(result+solve(d,delay,forget))%mod;
    }
    return t[day]=result;
}
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(t,-1,sizeof(t));
        int total=0;
        for(int d=n-forget+1;d<=n;d++){
            if(d>0)
            total=(total+solve(d,delay,forget))%mod;
        }
        return total;

    }
};