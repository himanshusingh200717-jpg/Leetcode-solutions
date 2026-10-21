class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(),s.end()))return 0;
        int n=s.size();
        if(n==2)return -1;
        char maxchar=*max_element(s.begin(),s.end());
        char minchar=*min_element(s.begin(),s.end());
        if(s[0]==minchar||s[n-1]==maxchar)return 1;
        char maxmid=*max_element(s.begin()+1,s.end()-1);
        char minmid=*min_element(s.begin()+1,s.end()-1);
        if(s[0]>maxmid&&s[n-1]<minmid){
            return 3;
        }
        else
        return 2;

    }
};