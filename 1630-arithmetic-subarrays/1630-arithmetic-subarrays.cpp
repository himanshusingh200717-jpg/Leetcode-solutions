class Solution {
public:
bool check(vector<int>&arr){
    int m=arr.size();
    int mx=INT_MIN;
    int mn=INT_MAX;
    unordered_set<int>st;
    for(int &num:arr){
        mx=max(mx,num);
        mn=min(mn,num);
        st.insert(num);
    }
    int d=(mx-mn)/(m-1);
    if((mx-mn)%(m-1)!=0)return false;
    int curr=mn;
    while(curr<mx){
    if(st.find(curr)==st.end())return false;
    curr+=d;
    }
    return true;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=l.size();
        vector<bool>ans;
        for(int i=0;i<n;i++){
            int start=l[i];
            int end=r[i];
            vector<int>arr(nums.begin()+start,nums.begin()+end+1);         
            bool isAP=check(arr);
            ans.push_back(isAP);
        }
        return ans;
        
    }
};