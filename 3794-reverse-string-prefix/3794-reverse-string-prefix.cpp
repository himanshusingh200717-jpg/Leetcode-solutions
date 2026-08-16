class Solution {
public:
    string reversePrefix(string s, int k) {
        int i=0;
        int j=k-1;
        while(i<k/2){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
        
    }
};