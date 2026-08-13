class Solution {
public:
struct node{
    int pre=0;
    int suf=0;
    int mxlen=0;
    char leftch=0;
    char rightch=0;
};
int n;
vector<node>segtree;
node merge(const node&l,const node&r,int leftlen,int rightlen){
    node res;
    res.leftch=l.leftch;
    res.rightch=r.rightch;
    res.pre=l.pre;
    if(l.pre==leftlen&&l.rightch==r.leftch){
        res.pre=l.pre+r.pre;
    }
    res.suf=r.suf;
    if(r.suf==rightlen&&l.rightch==r.leftch){
        res.suf=l.suf+r.suf;
    }
      res.mxlen = max(l.mxlen, r.mxlen);
    if(l.rightch==r.leftch){
        res.mxlen=max(res.mxlen,l.suf+r.pre);
    }
    return res;
}
void buildsegtree(int i,int l,int r,string &s){
    if(l==r){
        segtree[i]={1,1,1,s[l],s[l]};
        return;
    }
    int mid=l+(r-l)/2;
    buildsegtree(2*i+1,l,mid,s);
    buildsegtree(2*i+2,mid+1,r,s);
    segtree[i]=merge(segtree[2*i+1],segtree[2*i+2],mid-l+1,r-mid);
}
void update(int  i,int l,int r,int pos,char ch){
    if(l==r){
        segtree[i]={1,1,1,ch,ch};
        return;
    }
    int mid=l+(r-l)/2;
    if(pos<=mid){
        update(2*i+1,l,mid,pos,ch);
    }else{
        update(2*i+2,mid+1,r,pos,ch);
    }
     segtree[i]=merge(segtree[2*i+1],segtree[2*i+2],mid-l+1,r-mid);
}
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n=s.size();
        segtree.assign(4*n,node());
        buildsegtree(0,0,n-1,s);
        int k=queryIndices.size();
        vector<int>result(k);
        for(int i=0;i<k;i++){
            int pos=queryIndices[i];
            char ch=queryCharacters[i];
            update(0,0,n-1,pos,ch);
            result[i]=segtree[0].mxlen;
        }
        return result;
        
    }
};