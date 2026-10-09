class Solution {
public:
    int minInsertions(string s) {
        int count=0;
        int ans=0;
        for(char ch:s){
            if(ch=='('){
                count+=2;
                if(count%2==1){
                    count--;
                    ans++;
                }
            }
            else
            {
                count--;
                if(count<0)
                {
                    ans++;
                    count=1;
                }
            }
        }
        return count+ans;
    }
};