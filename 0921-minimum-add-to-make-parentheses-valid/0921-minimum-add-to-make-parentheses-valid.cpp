class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int countb=0;
        for(char ch:s){
           
            if(ch=='(')count++;
            else{
            count--;
             if(count<0){
                countb++;
                count=0;
            }}
        }
        return count+countb;
    }
};