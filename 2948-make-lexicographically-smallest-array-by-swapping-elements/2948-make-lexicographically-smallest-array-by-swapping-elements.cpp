class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>arr=nums;
        vector<int>result(n);
        sort(arr.begin(),arr.end());
        int groupnum=0;
        unordered_map<int,int>group;
        group[arr[0]]=groupnum;
        unordered_map<int,list<int>>list;
        list[groupnum].push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])>limit){
                groupnum+=1;
            }
            group[arr[i]]=groupnum;
            list[groupnum].push_back(arr[i]);
        }
        for(int i=0;i<n;i++){
            int num=nums[i];
            int grp=group[num];
            result[i]=*(list[grp].begin());
            list[grp].pop_front();
        }
        return result;

        
    }
};