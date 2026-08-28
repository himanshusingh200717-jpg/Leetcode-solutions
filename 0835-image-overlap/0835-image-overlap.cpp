class Solution {
public:
int countoverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,int rowoff,int coloff){
    int n=img1.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int new_i=i+rowoff;
            int new_j=j+coloff;
            if(new_i<0||new_i>=n||new_j<0||new_j>=n)continue;
            if(img1[i][j]==1&&img2[new_i][new_j]==1)count++;

        }
    }
    return count;
}
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxoverlap=0;
        for(int rowoff=-n+1;rowoff<n;rowoff++){
            for(int coloff=-n+1;coloff<n;coloff++){
                int count=countoverlaps(img1,img2,rowoff,coloff);
                maxoverlap=max(maxoverlap,count);
            }
        }
        return maxoverlap;
        
    }
};