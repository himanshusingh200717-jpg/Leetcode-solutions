class Solution {
public:
using ll=long long;
    long long countCommas(long long n) {
        ll lower=1000;
        ll comma=1;
        ll cnt=0;
        while(lower<=n){
            ll upper=lower*1000-1;
            if(upper>n)upper=n;
            ll countno=upper-lower+1;
            cnt+=countno*comma;

            lower*=1000;
            comma++;
            

        }
        return cnt;
        
        
    }
};