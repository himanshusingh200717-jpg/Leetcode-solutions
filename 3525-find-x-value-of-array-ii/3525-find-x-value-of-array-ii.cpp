struct Node{
    int count[5]={0};
    int prod=0;
    
};
class Segmenttree{
    public:
      int n;
      int k;
      vector<Node>segtree;
      Segmenttree(vector<int>&nums,int k){
        this->k=k;
        this->n=nums.size();
        segtree.resize(4*n,Node());
        build(0,0,n-1,nums);
      }
      void build(int i,int l,int r,vector<int>&nums){
        if(l==r){
            leafNode(i,nums[l]);
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,nums);
        build(2*i+2,mid+1,r,nums);
        segtree[i]=mergenodes(segtree[2*i+1],segtree[2*i+2]);

      }
      void leafNode(int i,int val){
        for(int x=0;x<k;x++){
            segtree[i].count[x]=0;
        }
        int r=val%k;
        segtree[i].count[r]=1;
        segtree[i].prod=r;
      }
      Node mergenodes(const Node& left,const Node& right){
        Node result;
        result.prod=(left.prod*right.prod)%k;
        for(int x=0;x<k;x++){
            result.count[x]=left.count[x];
        }
        for(int x=0;x<k;x++){
            int newremain=(left.prod*x)%k;
            result.count[newremain]+=right.count[x];
        }
        return result;


      }
      void segtreeupdate(int i,int l,int r,int idx,int val){
        if(l==r){
            leafNode(i,val);
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            segtreeupdate(2*i+1,l,mid,idx,val);
        }else{
            segtreeupdate(2*i+2,mid+1,r,idx,val);
        }
        segtree[i]=mergenodes(segtree[2*i+1],segtree[2*i+2]);

      }
      void update(int idx,int val){
        segtreeupdate(0,0,n-1,idx,val);
      }
      Node segtreequery(int start,int end,int i,int l,int r){
        if(l>=start&&r<=end){
            return segtree[i];
        }
        int mid=l+(r-l)/2;
        if(end<=mid){
            return segtreequery(start,end,2*i+1,l,mid);
        }
        if(start>mid){
            return segtreequery(start,end,2*i+2,mid+1,r);

        }
        Node left=segtreequery(start,end,2*i+1,l,mid);
        Node right=segtreequery(start,end,2*i+2,mid+1,r);
           return mergenodes(left,right);
      }
      Node query(int start,int end){
        return segtreequery(start,end,0,0,n-1);
      }
   
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        Segmenttree segtree(nums,k);
        vector<int>result;
        for(auto &q:queries){
            int idx=q[0];
            int val=q[1];
            int start=q[2];
            int x=q[3];
            segtree.update(idx,val);
        Node resultnode=segtree.query(start,n-1);
        result.push_back(resultnode.count[x]);
        }
        
            return result;
        
    }

};