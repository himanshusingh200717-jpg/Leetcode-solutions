class Solution {
public:
void solve(string &s,int leftextra,int rightextra,int balance,int index,unordered_set<string>&ans){
    if(index==s.size()){
        if(leftextra==0&&rightextra==0&&balance==0){
            ans.insert(s);
        }
        return;
    }
    char ch=s[index];
    if(ch=='('&&leftextra>0){
        string temp=s;
        temp.erase(index,1);
        solve(temp,leftextra-1,rightextra,balance,index,ans);
    }
    if(ch==')'&&rightextra>0){
        string temp=s;
        temp.erase(index,1);
        solve(temp,leftextra,rightextra-1,balance,index,ans);
    }
    if(ch=='('){
        solve(s,leftextra,rightextra,balance+1,index+1,ans);
    }
    else if(ch==')'){
        if(balance>0){
        solve(s,leftextra,rightextra,balance-1,index+1,ans);
        }
    }
    else
    {
        solve(s,leftextra,rightextra,balance,index+1,ans);

    }
    
}
    vector<string> removeInvalidParentheses(string s) {
        int leftextra=0;
        int rightextra=0;
        for(char ch:s){
            if(ch=='('){
                leftextra++;
            }
            else if(ch==')'){
                if(leftextra>0){
                    leftextra--;
                }
                else
            rightextra++;
            }
        }
        unordered_set<string>ans;
        solve(s,leftextra,rightextra,0,0,ans);
        return vector<string>(ans.begin(),ans.end());
    }
};