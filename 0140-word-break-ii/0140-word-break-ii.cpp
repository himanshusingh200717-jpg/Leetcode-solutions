class Solution {
public:
vector<string>result;
unordered_set<string>st;
void solve(int i,string currsentence,string &s){
    if(i>=s.size()){
        result.push_back(currsentence);
        return ;
    }
    for(int j=i;j<s.size();j++){
        string tempword=s.substr(i,j-i+1);
        if(st.count(tempword)){
            string tempsentence=currsentence;
            if(!currsentence.empty()){
                currsentence+=" ";
            }
            currsentence+=tempword;
            solve(j+1,currsentence,s);
            currsentence=tempsentence;  
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict){
            st.insert(word);
        }
        string currsentence="";
        solve(0,currsentence,s);
        return result;
        
    }
};