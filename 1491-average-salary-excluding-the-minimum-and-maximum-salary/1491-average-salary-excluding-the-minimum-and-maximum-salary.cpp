class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        int sum=0;
        sort(salary.begin(),salary.end());
        for(int i=1;i<n-1;i++){
            sum+=salary[i];
        }
        return (double)sum/(n-2);
        
    }
};