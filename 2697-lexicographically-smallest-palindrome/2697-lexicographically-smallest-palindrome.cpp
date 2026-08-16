class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            char x=min(s[i],s[j]);
            s[i]=x;
            s[j]=x;
            i++;
            j--;
        }
        return s;
        
    }
};