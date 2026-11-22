class Solution {
public:
    bool checkString(string s) {
        int na=0;
        for(char ch:s){
            if(ch=='a'){
                na++;
            }
        }
        for(char ch:s){
            if(ch=='a'){
                na--;
            }
            else if(ch=='b'&&na!=0){
                return false;

            }

        }
        return true;
        
    }
};