class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int resultedservers=0;
        vector<int>indexrowcount(m);
        vector<int>indexcolcount(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    indexrowcount[i]++;
                    indexcolcount[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&(indexrowcount[i]>1||indexcolcount[j]>1)){
                    resultedservers++;
                }
            }
        }
        return resultedservers;
    }
};