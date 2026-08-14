class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int mxdist=0;
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[0]){
                mxdist=max(mxdist,i);

            }
            if(colors[i]!=colors[n-1]){
                mxdist=max(mxdist,abs(i-(n-1)));
            }
        }
        return mxdist;
    }
};