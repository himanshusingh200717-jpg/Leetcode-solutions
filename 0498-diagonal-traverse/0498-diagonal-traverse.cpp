class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto &it:mp){
            if(it.first%2==0){
                reverse(it.second.begin(),it.second.end());
            }
            for(int x:it.second){
                ans.push_back(x);
            }
        }
        return ans;
        
    }
};