class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<tuple<int,int,int>>q;
        vector<vector<vector<bool>>>vis(m,vector<vector<bool>>(n,vector<bool>(1024,false)));
        q.push({0,0,grid[0][0]});
        vis[0][0][grid[0][0]]=1;
        int dr[2]={0,1};
        int dc[2]={1,0};
        while(!q.empty()){
            auto [r,c,xr]=q.front();
            q.pop();
            for(int k=0;k<2;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=m||nc>=n)continue;
                int nx=xr^grid[nr][nc];
                while(!vis[nr][nc][nx]){
                    vis[nr][nc][nx]=1;
                    q.push({nr,nc,nx});
                }

            }
        }
        for(int x=0;x<1024;x++){
            if(vis[m-1][n-1][x]){
                return x;
            }
        }
        
        return -1;
    }
};