class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        vector<vector<int>>orig=mat;
        for(int i=0;i<n;i++){
            if(i%2==0)
            rotate(mat[i].rbegin(),mat[i].rbegin()+k,mat[i].rend());
            else
            rotate(mat[i].begin(),mat[i].begin()+k,mat[i].end());
        }
        return mat==orig;
        
    }
};