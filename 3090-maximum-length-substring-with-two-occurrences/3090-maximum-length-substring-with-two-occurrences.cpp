class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0;
        int len=0;
        for(int j=0;j<s.length();j++){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;

            }
            len=max(len,j-i+1);
        }
        return len;
        
    }
};