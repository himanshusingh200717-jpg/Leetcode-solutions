class Solution {
public:
bool evensum(int num){
    int sum=0;
    while(num>0){
        int rem=num%10;
        sum+=rem;
        num/=10;
    }
    return sum%2==0;
}

    int countEven(int num) {
        int ans=0;
        for(int i=2;i<=num;i++){
            if(evensum(i)){
                ans++;
            }

        }
        return ans;
        
    }
};