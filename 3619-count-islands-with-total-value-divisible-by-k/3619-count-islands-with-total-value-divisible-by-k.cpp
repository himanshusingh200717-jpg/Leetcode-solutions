class Solution {
public:
int m,n;
long long dfs(vector<vector<int>>& grid,int i,int j){
    m=grid.size();
    n=grid[0].size();
    if(i>=m||i<0||j>=n||j<0||grid[i][j]==0)return 0;
    long long sum=grid[i][j];
    grid[i][j]=0;
    sum+=dfs(grid,i,j-1);
    sum+=dfs(grid,i-1,j);
    sum+=dfs(grid,i,j+1);
    sum+=dfs(grid,i+1,j);
    return sum;

}
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
    n=grid[0].size();
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!=0&&dfs(grid,i,j)%k==0){
                count++;
            }
        }
    }
    return count;
    }
};