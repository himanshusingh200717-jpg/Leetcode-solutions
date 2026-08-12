class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0;
        int right=0;
        int dash=0;
        int ans=0;
        for(char ch:moves){
            if(ch=='L')
            left++;
            else if(ch=='R')
            right++;
            else
            dash++;

        }
        if(left>right)ans=left+dash-right;
        else if(right>left)ans=right+dash-left;
        else
        ans=dash;
        return ans;
    }
};