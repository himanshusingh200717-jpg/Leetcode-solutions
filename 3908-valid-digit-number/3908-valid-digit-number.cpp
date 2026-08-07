class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        char ch=x+'0';
        return s[0]!=ch&&s.find(ch)!=string::npos;
    }
};