class Solution {
public:
int n;
  bool solve(vector<vector<int>>& grid,int i,int j,int num){
    if(num==n*n-1)return true;
    int dr[8]={2,2,-2,-2,1,1,-1,-1};
    int dc[8]={1,-1,1,-1,2,-2,2,-2};
    for(int x=0;x<8;x++){
        int nr=i+dr[x];
        int nc=j+dc[x];
        if(nr>=0&&nr<n&&nc>=0&&nc<n){
            if(grid[nr][nc]==num+1){
                if(solve(grid,nr,nc,num+1))
                return true;
            }
        }
    }
    return false;
  }
    bool checkValidGrid(vector<vector<int>>& grid) {
        n=grid.size();
        if(grid[0][0]!=0)return false;
        return solve(grid,0,0,0);
    }
};