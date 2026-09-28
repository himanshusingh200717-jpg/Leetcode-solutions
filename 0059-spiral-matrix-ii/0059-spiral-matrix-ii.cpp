class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int dir=0;
         vector<vector<int>>mat(n,vector<int>(n));
        int left=0;
        int top=0;
        int down=n-1;
        int right=n-1;
        vector<int>ans;
        int count=1;
        while(top<=down&&left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    mat[top][i]=count++;
                }
                top++;
            }
            if(dir==1){
                for(int i=top;i<=down;i++){
                     mat[i][right]=count++;
                }
                right--;
            }
            if(dir==2){
                for(int i=right;i>=left;i--){
                   
                    mat[down][i]=count++;
                }
                down--;
            }
            if(dir==3){
                for(int i=down;i>=top;i--){
                 
                       mat[i][left]=count++;
                }
                left++;
            }
            dir++;
            if(dir==4){
                dir=0;
            }
        } 
        return mat;       
    
    }
};