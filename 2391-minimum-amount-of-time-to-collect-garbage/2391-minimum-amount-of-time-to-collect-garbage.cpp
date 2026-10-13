class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time=0;
        int n=garbage.size();
        int p_index=0;
        int g_index=0;
        int m_index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<garbage[i].size();j++){
                if(garbage[i][j]=='P')p_index=i;
                else if(garbage[i][j]=='G')g_index=i;
                else
                m_index=i;
                time++;
            }
        }
        for(int i=1;i<travel.size();i++){
            travel[i]+=travel[i-1];
        }
        time+=p_index>0?travel[p_index-1]:0;
        time+=g_index>0?travel[g_index-1]:0;
        time+=m_index>0?travel[m_index-1]:0;
        return time;

        
    }
};