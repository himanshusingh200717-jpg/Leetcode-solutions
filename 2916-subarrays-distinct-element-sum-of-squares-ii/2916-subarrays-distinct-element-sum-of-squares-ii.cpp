class Solution {
public:
typedef long long ll;
    int MOD=1e9+7;
    int n;
        vector<ll>sqsumsegtree;
        vector<ll>sumsegtree;
        vector<ll>lazytree;
        void lazyaddition(int i,int l,int r,int val){
            int len=(r-l+1);
            sqsumsegtree[i]+=2*val*sumsegtree[i]+len*val*val;
            sumsegtree[i]+=(len*val);
        }
        void updaterange(int start,int end,int i,int l,int r,int val){
            if(lazytree[i]!=0){
                lazyaddition(i,l,r,lazytree[i]);
                if(l!=r){
                    lazytree[2*i+1]+=lazytree[i];
                    lazytree[2*i+2]+=lazytree[i];

                }
                lazytree[i]=0;
            }
            if(l>end||r<start||l>r)return;
            if(l>=start&&r<=end){
                lazyaddition(i,l,r,val);
                if(l!=r){
                    lazytree[2*i+1]+=val;
                    lazytree[2*i+2]+=val;

                }
                return;

            }
            int mid=l+(r-l)/2;
            updaterange(start,end,2*i+1,l,mid,val);
            updaterange(start,end,2*i+2,mid+1,r,val);
            sumsegtree[i]=sumsegtree[2*i+1]+sumsegtree[2*i+2];
            sqsumsegtree[i]=sqsumsegtree[2*i+1]+sqsumsegtree[2*i+2];

        }
    int sumCounts(vector<int>& nums) {
        n=nums.size();
        sqsumsegtree.assign(4*n,0);
        sumsegtree.assign(4*n,0);
        lazytree.assign(4*n,0);
        vector<int>lastseenidx(100001,-1);
        ll result=0;
        for(int i=0;i<n;i++){
            int start=lastseenidx[nums[i]]+1;
            int end=i;
            updaterange(start,end,0,0,n-1,1);
            result=(result+sqsumsegtree[0])%MOD;
            lastseenidx[nums[i]]=i;


        }
        return result;

       


    }
};