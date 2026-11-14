class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>t(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    t[i][j]=i+j;
                }
                else if(word1[i-1]==word2[j-1]){
                    t[i][j]=t[i-1][j-1];
                }
                else
                {
                    t[i][j]=1+min({t[i][j-1],t[i-1][j],t[i-1][j-1]});
                }
            }
        }
        return t[n][m];
        
    }
};