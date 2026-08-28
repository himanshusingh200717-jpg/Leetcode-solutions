class Solution {
public:
char midchar='#';
int halflen=0;
string result="";
bool solve(string &curr,vector<int>&count,string &target,int i,bool greater){
    if(curr.length()==halflen){
        string candidate=curr;
        string righthalf=curr;
        reverse(righthalf.begin(),righthalf.end());
        if(midchar!='#'){
            candidate+=midchar;
        }
        candidate+=righthalf;
        if(candidate>target){
            result=candidate;
            return true;
        }
        return false;
    }
    for(char c='a';c<='z';c++){
        if(count[c-'a']==0)continue;
        if(!greater&&c<target[i])continue;
         curr.push_back(c);
    count[c-'a']--;
    bool isgreater=greater||c>target[i];
    if(solve(curr,count,target,i+1,isgreater))return true;
    curr.pop_back();
    count[c-'a']++;
    
    }
    return false;
   
}
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        vector<int>count(26,0);
        for(char &ch:s){
            count[ch-'a']++;
        }
        int oddlength=0;
        for(int c=0;c<26;c++){
            if(count[c]%2==1){
            oddlength++;
            midchar=c+'a';
            }

        }
        if(oddlength>1)return "";
        for(int c=0;c<26;c++){
            count[c]/=2;
        }
        halflen=n/2;
        string curr;
        solve(curr,count,target,0,false);
        return result;
        
    }
};