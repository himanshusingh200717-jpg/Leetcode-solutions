class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int i=0;
        int n=s.size();
        string temp;
        unordered_map<string,string>mp;
        for(auto &it:knowledge){
            mp[it[0]]=it[1];
        }
        string result="";
        while(i<n){
            if(isalpha(s[i])){
                result.push_back(s[i]);
            }else{
                temp="";
                i++;
                while(s[i]!=')'){
                temp.push_back(s[i]);
                i++;
                }
                result+=mp.count(temp)?mp[temp]:"?";
            }
            i++;
        }
        return result;
    }
};