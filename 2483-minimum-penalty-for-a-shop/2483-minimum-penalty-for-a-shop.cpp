class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int penalty=count(customers.begin(),customers.end(),'Y');
        int minpenalty=penalty;
        int minhour=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y')penalty--;
            else
            {
                penalty++;
            }
            if(penalty<minpenalty){
                minpenalty=penalty;
                minhour=i+1;
            }
        }
        return minhour;
        
    }
};