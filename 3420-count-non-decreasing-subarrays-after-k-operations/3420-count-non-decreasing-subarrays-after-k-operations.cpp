class Solution {
public:
typedef long long ll;
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll>currsum(n);
        currsum[0]=nums[0];
        for(int i=1;i<n;i++){
            currsum[i]=nums[i]+currsum[i-1];
        }
        auto rangesum=[&](int i,int j)->long long{
            if(i>j)return 0;
            return currsum[j]-((i>0)?currsum[i-1]:0);
        };
        vector<int>ngr(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                ngr[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        vector<ll>operations(n+1,0);
        for(int i=n-1;i>=0;i--){
            int m=ngr[i];
            ll segmentoprns=(1LL*nums[i]*(m-i))-rangesum(i,m-1);
            operations[i]=segmentoprns+operations[m];

        }
        deque<int>deq;
        ll result=0;
        int i=0,j=0;
        while(j<n){
            while(!deq.empty()&&nums[deq.back()]<nums[j]){
                deq.pop_back();
            }
            deq.push_back(j);
            while(i<=j){
                int m=deq.front();
                ll oprns=(operations[i]-operations[m])+(1LL*nums[m]*(j-m+1))-rangesum(m,j);
                if(oprns<=k){
                    break;
                }
                i++;
                if(deq.front()<i){
                    deq.pop_front();
                }
            }
            result+=(j-i+1);
            j++;
        }
        return result;
    }
};