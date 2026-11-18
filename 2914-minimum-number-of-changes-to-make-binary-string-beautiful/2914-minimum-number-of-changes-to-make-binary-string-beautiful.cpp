class Solution {
public:
    int minChanges(string s) {
        int count=0;
        int n=s.size();
        if(s[n-1]!=s[n-2])count++;
        for(int i=0;i<s.size()-2;i+=2){
            if(s[i]=='0'){
                if(s[i+1]=='0')continue;
                else
                count++;
            }
            else
            {
                if(s[i+1]=='1')continue;
                else
                count++;
            }
        }
        return count;
        
    }
};