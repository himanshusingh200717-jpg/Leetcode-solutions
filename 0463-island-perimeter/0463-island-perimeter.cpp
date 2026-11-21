class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        queue<pair<int,int>>q;
        int peri=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    break;
                }
            }
            if(!q.empty())break;
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]==0){
                    peri++;
                }else if(!vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});

                }
            }


        }
        return peri;
    }
};