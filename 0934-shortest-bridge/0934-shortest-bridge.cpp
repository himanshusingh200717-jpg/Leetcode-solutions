class Solution {
public:
int n;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
    queue<pair<int,int>>q;
void dfs(int x,int y,vector<vector<int>>& grid){
    if(x>=n||x<0||y>=n||y<0||grid[x][y]!=1)return;

    grid[x][y]=7;
    q.push({x,y});
    for(int i=0;i<4;i++){
        dfs(x+dx[i],y+dy[i],grid);
    }
}
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        int dist=0;
        bool found=false;
        for(int i=0;i<n&&!found;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                        found=true;
                        break;
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=n||nx<0||ny>=n||ny<0)continue;
                         if(grid[nx][ny]==1)return dist;
                    if(grid[nx][ny]==0){
                        grid[nx][ny]=7;
                        q.push({nx,ny});
                    }
                }
            }
            dist++;
        }
        return -1;


    }
};