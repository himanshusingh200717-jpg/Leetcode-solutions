class Solution {
public:
string s;
int n;
int idx=0;
set<string>getunit(){
    set<string>result;
    if(s[idx]=='{'){
        idx++;
        result=performunion();

    }else{
        result={string(1,s[idx])};
    }
    idx++;
    return result;
}
set<string>performcat(){
    set<string>result={""};

    while(idx<n&&(s[idx]=='{'||isalpha(s[idx]))){
        set<string>temp=getunit();
        set<string>concatresult;
        for(const string &left:result){
            for(const string &right:temp){
                concatresult.insert(left+right);

            }
        }
        result=concatresult;
    }
    return result;
}
set<string>performunion(){
    set<string>result;
    while(true){
        set<string>temp=performcat();
         result.insert(temp.begin(),temp.end());
    if(idx<n&&s[idx]==',')idx++;
    else
    break;

    }
    return result;
   
}
    vector<string> braceExpansionII(string expression) {
        n=expression.size();
        s=expression;
        idx=0;
        set<string>st=performunion();
        vector<string>result(st.begin(),st.end());
        return result;
        
    }
};