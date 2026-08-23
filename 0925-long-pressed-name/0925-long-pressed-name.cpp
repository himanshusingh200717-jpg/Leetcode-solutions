class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;
        int j=0;
        int n=name.size();
        int m=typed.size();
        while(j<m){
            if(i<n&&name[i]==typed[j])
            {
                i++;j++;
            }
            else if(j>0&&typed[j]==typed[j-1])j++;
            else
            return false;
        }
        return i==n;
        
    }
};