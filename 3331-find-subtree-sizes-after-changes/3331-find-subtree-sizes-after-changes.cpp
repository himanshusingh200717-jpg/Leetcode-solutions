class Solution {
public:
unordered_map<int,vector<int>>adj;
vector<int>resultsize;
vector<int>last;
void dfs(int currnode,string &s,vector<int>& parent){
    int c=s[currnode]-'a';
    int nearancestor=last[c];
    last[c]=currnode;
    for(int child:adj[currnode]){
        dfs(child,s,parent);
    }
    last[c]=nearancestor;
    int newparent=parent[currnode];
    if(currnode!=0){
        int newparent=parent[currnode];
    if(nearancestor!=-1){
        newparent=nearancestor;
    }
    parent[currnode]=newparent;
    resultsize[newparent]+=resultsize[currnode];
    }


}
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        for(int i=1;i<n;i++){
            int u=parent[i];
            int v=i;
            adj[u].push_back(v);
        }
        resultsize.assign(n,1);
        last.assign(26,-1);
        dfs(0,s,parent);
        return resultsize;
    }
};