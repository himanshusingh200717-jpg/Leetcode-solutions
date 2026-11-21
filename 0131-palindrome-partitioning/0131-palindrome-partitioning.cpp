class Solution {
public:
int n;
bool ispalindrome(string &s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void backtrack(int idx,string &s,vector<string>&curr,vector<vector<string>>&result){
    if(idx==n){
        result.push_back(curr);
        return;
    }
    for(int i=idx;i<n;i++){
        if(ispalindrome(s,idx,i)){
            curr.push_back(s.substr(idx,i-idx+1));
            backtrack(i+1,s,curr,result);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<string>>result;
        vector<string>curr;
        backtrack(0,s,curr,result);
        return result;

        
    }
};