class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>result;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            result.push_back(nums[row][col]);
            if(col==0&&row+1<nums.size()){
                q.push({row+1,col});
            }
            if(col+1<nums[row].size()){
                q.push({row,col+1});
            }
        }
        return result;
    }
};