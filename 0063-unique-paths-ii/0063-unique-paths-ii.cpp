class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<vector<int>>ways(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        ways[0][0]=1;
        q.push({0,0});
        int dr[]={1,0};
        int dc[]={0,1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<2;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr<m&&nc<n&&obstacleGrid[nr][nc]==0){
                    if(ways[nr][nc]==0)
                    q.push({nr,nc});
                    ways[nr][nc]+=ways[r][c];
                }
            }

        }
        return ways[m-1][n-1];
        
    }
};