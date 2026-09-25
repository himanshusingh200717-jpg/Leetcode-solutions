class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        vector<int>prev=points[0];
        int count=1;
        for(int i=1;i<n;i++){
            int currsp=points[i][0];
            int currep=points[i][1];
            int prevsp=prev[0];
            int prevep=prev[1];
            if(currsp>prevep){
                count++;
                prev=points[i];

            }else{
                prev[0]=max(prevsp,currsp);
                prev[1]=min(prevep,currep);
            }
        }
        return count;
    }
};