class Solution {
public:

    string digitSum(string s, int k) {
        
        while(k<s.size()){
            string ans="";
        for(int i=0;i<s.size();i+=k){
            int temp=0;
            for(int j=i;j<min((int)s.size(),i+k);j++){
                temp+=s[j]-'0';
            }
            ans+=to_string(temp);
        }
        s=ans;
        }

        return s;
    }
};