class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int>pos;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
            pos.push_back(i);
        }
    if(pos.size()<k)return "";
        string ans="";
        for(int i=0;i+k-1<pos.size();i++){
            int l=pos[i];
            int r=pos[i+k-1];
            string curr=s.substr(l,r-l+1);
             if(curr.size()<ans.size()||ans.empty()||(ans.size()==curr.size()&&curr<ans))
        ans=curr;

        }
       

        return ans;
        
    }
};