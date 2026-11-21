class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    queue<pair<int,int>>q;
                    count++;
                    q.push({i,j});
                    vis[i][j]=1;
                     while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]=='1'&&!vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
                }
            }
            
        }
       
        return count;

    }
};