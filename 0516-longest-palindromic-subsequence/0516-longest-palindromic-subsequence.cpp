class Solution {
public:
int n;
int t[1001][1001];
int solve(int i,int j,string &s){
    if(i>j)return 0;
    if(i==j)return 1;
    if(t[i][j]!=-1)return t[i][j];
    if(s[i]==s[j]){
        return t[i][j]=2+solve(i+1,j-1,s);
    }
    else
    {
        return t[i][j]=max(solve(i+1,j,s),solve(i,j-1,s));
    }
    return -1;
}
    int longestPalindromeSubseq(string s) {
        n=s.size();
        memset(t,-1,sizeof(t));
        return solve(0,n-1,s);
    }
};