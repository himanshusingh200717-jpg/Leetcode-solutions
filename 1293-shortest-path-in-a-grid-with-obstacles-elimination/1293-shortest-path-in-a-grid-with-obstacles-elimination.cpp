class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1&&n==1)return 0;
        queue<tuple<int,int,int>>q;
        q.push({0,0,k});
        vector<vector<vector<bool>>>visited(m,vector<vector<bool>>(n,vector<bool>(k+1,false)));
        visited[0][0][k]=true;
        int steps=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [r,c,rem]=q.front();
                q.pop();
                if(r==m-1&&c==n-1)return steps;
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr<0||nr>=m||nc<0||nc>=n)continue;
                    int newrem=rem-grid[nr][nc];
                    if(newrem<0)continue;
                    if(visited[nr][nc][newrem])continue;
                    visited[nr][nc][newrem]=true;
                    q.push({nr,nc,newrem});


                }
                
            }
            steps++;
        }
        return -1;

        
    }
};