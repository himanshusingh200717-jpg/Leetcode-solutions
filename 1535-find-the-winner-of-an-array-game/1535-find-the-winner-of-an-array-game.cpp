class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int mx=*max_element(arr.begin(),arr.end());
        if(k>=n)return mx;
        int winner=arr[0];
        int countwin=0;
        for(int i=1;i<n;i++){
            if(arr[i]>winner){
                winner=arr[i];
                countwin=1;
            }else
            countwin++;
             if(winner==mx||countwin==k)return winner;
        }
       
        return winner;
    }
};