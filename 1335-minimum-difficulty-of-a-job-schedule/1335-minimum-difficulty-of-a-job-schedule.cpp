class Solution {
public:
int n;
int t[301][11];
int solve(int i,int d,vector<int>& jobDifficulty){
    int maxd=INT_MIN;
    if(d==1){
        for(int k=i;k<n;k++){
            maxd=max(maxd,jobDifficulty[k]);
        }
        return maxd;
    }
    int ans=INT_MAX;
    if(t[i][d]!=-1)return t[i][d];
    for(int k=i;k<=n-d;k++){
         maxd=max(maxd,jobDifficulty[k]);
        int sum=maxd+solve(k+1,d-1,jobDifficulty);
        ans=min(ans,sum);
    }
    return t[i][d]=ans;


}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(n<d)return -1;
        memset(t,-1,sizeof(t));
        return solve(0,d,jobDifficulty);
        
    }
};