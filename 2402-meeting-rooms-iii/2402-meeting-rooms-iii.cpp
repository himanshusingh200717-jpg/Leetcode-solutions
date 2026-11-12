class Solution {
public:
typedef pair<long long,int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int>roomusedcount(n,0);
        priority_queue<P,vector<P>,greater<P>>usedrooms;
        priority_queue<int,vector<int>,greater<int>>availablerooms;
        for(int room=0;room<n;room++){
            availablerooms.push(room);
        }
        for(vector<int>meet:meetings){
            int start=meet[0];
            int end=meet[1];
            int duration=end-start;
            while(!usedrooms.empty()&&usedrooms.top().first<=start){
                int room=usedrooms.top().second;
                usedrooms.pop();
                availablerooms.push(room);
            }
            if(!availablerooms.empty()){
                int room=availablerooms.top();
                availablerooms.pop();
                usedrooms.push({end,room});
                roomusedcount[room]++;
            }else{
                int room=usedrooms.top().second;
                long long endtime=usedrooms.top().first;
                usedrooms.pop();
                usedrooms.push({endtime+duration,room}); 
                roomusedcount[room]++;
            }
        }
        int resultroom=-1;
        int maxuse=0;
        for(int room=0;room<n;room++){
            if(roomusedcount[room]>maxuse){
                maxuse=roomusedcount[room];
                resultroom=room;
            }
        }
        return resultroom;
    }
};