class Solution {
public:
int n;
int t[1001][1001];
bool check(int i,int j,string &s){
    if(i>j)return 1;
    if(t[i][j]!=-1)return t[i][j];
    if(s[i]==s[j]){
        return check(i+1,j-1,s);
    }
    return t[i][j]=0;

}
    int countSubstrings(string s) {
        n=s.size();
        int count=0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s)){
                    count++;
                }
            }
        }
        return count;
        
    }
};