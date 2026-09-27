class SummaryRanges {
public:
unordered_set<int>st;
    SummaryRanges() {
        st.clear();
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int>nums(st.begin(),st.end());
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int left=nums[i];
        while(i<n-1&&nums[i]+1==nums[i+1]){
            i++;
        }
        ans.push_back({left,nums[i]});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */