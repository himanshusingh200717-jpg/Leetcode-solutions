class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int>mp;
        while(n>0){
            int rem=n%10;
            mp[rem]+=1;
            n/=10;
        }
        int mnfreq=INT_MAX;
        int mnelement=INT_MAX;
        for(auto &it:mp){
            mnfreq=min(mnfreq,it.second);
        }
        for(auto &it:mp){
            if(it.second==mnfreq)
            mnelement=min(mnelement,it.first);

        }
        return mnelement;
        
    }
};