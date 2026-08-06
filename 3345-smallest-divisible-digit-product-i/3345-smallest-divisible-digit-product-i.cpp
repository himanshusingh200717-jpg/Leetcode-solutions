class Solution {
public:
int product(int n){
    int digit=1;
    while(n>0){
        int rem=n%10;
        digit*=rem;
        n/=10;

    }
    return digit;
}
    int smallestNumber(int n, int t) {
        while(true){
            if(product(n)%t==0)
            return n;
            n++;
        }
    }
};