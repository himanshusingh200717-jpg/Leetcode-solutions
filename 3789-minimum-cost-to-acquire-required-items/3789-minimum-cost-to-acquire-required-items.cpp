class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long case1=1LL*cost1*need1+1LL*cost2*need2;
        long long case2=min((1LL*costBoth*max(need2,need1)),(need2>need1)?1LL*costBoth*need1+1LL*(need2-need1)*cost2:1LL*costBoth*need2+1LL*cost1*(need1-need2));
        
        return min(case1,case2);
    }
};