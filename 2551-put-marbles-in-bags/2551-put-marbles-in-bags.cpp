class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        int m=n-1;
        vector<int>pairsum(m,0);
        for(int i=0;i<m;i++){
            pairsum[i]=weights[i]+weights[i+1];
        }
        sort(pairsum.begin(),pairsum.end());
        long long mxsum=0;
        long long mnsum=0;
        for(int i=0;i<k-1;i++){
            mxsum+=pairsum[m-i-1];
            mnsum+=pairsum[i];
        }
        return mxsum-mnsum;

        
    }
};