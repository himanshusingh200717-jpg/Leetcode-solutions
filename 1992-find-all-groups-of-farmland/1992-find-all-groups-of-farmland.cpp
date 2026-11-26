class Solution {
public:
int n,m;
void dfs(vector<vector<int>>& land,int i,int j,int &r2,int &c2){
    land[i][j]=0;
    r2=max(r2,i);
    c2=max(c2,j);
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&land[nx][ny]==1){
            dfs(land,nx,ny,r2,c2);
        }
    }

}
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    int r1=i;
                    int c1=j;
                    int r2=-1;
                    int c2=-1;
                    dfs(land,i,j,r2,c2);
                    ans.push_back({r1,c1,r2,c2});

                }
                
               
            }
        }
        return ans;
    }
};