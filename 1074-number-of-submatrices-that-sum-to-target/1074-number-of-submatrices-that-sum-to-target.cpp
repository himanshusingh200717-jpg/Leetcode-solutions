class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int row=0;row<rows;row++){
            for(int col=1;col<cols;col++){
                matrix[row][col]+=matrix[row][col-1];
            }
        }
        int result=0;
        for(int startcol=0;startcol<cols;startcol++){
            for(int j=startcol;j<cols;j++){
                unordered_map<int,int>mp;
                mp.insert({0,1});
                int currsum=0;
                for(int row=0;row<rows;row++){
                    currsum+=matrix[row][j]-(startcol>0?matrix[row][startcol-1]:0);
                    if(mp.find(currsum-target)!=mp.end()){
                        result+=mp[currsum-target];
                    }
                    mp[currsum]++;
                }
            }
        }
        return result;

    }
};