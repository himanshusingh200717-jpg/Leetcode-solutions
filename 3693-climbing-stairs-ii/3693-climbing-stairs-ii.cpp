class Solution {
public:
int t[100001];
int solve(int i,int n,vector<int>& costs){
    if(i==n)return 0;
    if(t[i]!=-1)return t[i];
    int cost=INT_MAX;
    int j=i+1;
    if(j<=n){
        cost=solve(j,n,costs)+costs[j-1]+(j-i)*(j-i);
    
    }
    j=i+2;
    if(j<=n){
        cost=min(cost,solve(j,n,costs)+costs[j-1]+(j-i)*(j-i));
    
    }
    j=i+3;
    if(j<=n){
        cost=min(cost,solve(j,n,costs)+costs[j-1]+(j-i)*(j-i));
    
    }
    return t[i]=cost;
}
    int climbStairs(int n, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        return solve(0,n,costs);
    }
};