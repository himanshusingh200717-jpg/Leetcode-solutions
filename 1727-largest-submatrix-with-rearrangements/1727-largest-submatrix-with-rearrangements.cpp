class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxarea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1&&i>0){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
            vector<int>heights=matrix[i];
            sort(heights.begin(),heights.end(),greater<int>());
            for(int i=0;i<n;i++){
                int base=i+1;
                int height=heights[i];
                maxarea=max(maxarea,base*height);

            }

        }
        return maxarea;
    }
};