class Solution {
public:
vector<int>buildlps(vector<int>&p){
    int n=p.size();
    vector<int>lps(n,0);
    int len=0;
    for(int i=1;i<n;){
        if(p[i]==p[len]){
            lps[i++]=++len;
        }
        else if(len>0){
            len=lps[len-1];
        }
        else
        lps[i++]=0;
    }
    return lps;
}
bool isrotation(vector<int>a,vector<int>&b){
    int k=a.size();
    vector<int>lps=buildlps(a);
    int i=0,j=0;
    while(i<2*k-1){
        if(b[i%k]==a[j]){
            i++;
            j++;
            if(j==k)return true;
        }else if(j>0){
            j=lps[j-1];
        }else
        i++;
    }
    return false;
}
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        int ans=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0)continue;
            bool valid=true;
            for(int i=0;i<n;i+=k){
                vector<int>a(nums.begin()+i,nums.begin()+i+k);
                vector<int>b(sorted.begin()+i,sorted.begin()+i+k);
                if(!isrotation(a,b)){
                    valid=false;
                    break;
                }
            }
            if(valid)ans+=k;
        }
        
        return ans;
    }
};