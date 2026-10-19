class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>onerow(m,0);
        vector<int>onecol(n,0);
        vector<int>zerorow(m,0);
        vector<int>zerocol(n,0);
        vector<vector<int>>diff(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)onerow[i]++;
            }
        }
        for(int a=0;a<m;a++){
            zerorow[a]=m-onerow[a];
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(grid[i][j]==1)onecol[j]++;
            }
        }
       
        for(int b=0;b<n;b++){
            zerocol[b]=n-onecol[b];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j]=onerow[i]+onecol[j]-zerorow[i]-zerocol[j];
            }
        }
        return diff;
    }
};