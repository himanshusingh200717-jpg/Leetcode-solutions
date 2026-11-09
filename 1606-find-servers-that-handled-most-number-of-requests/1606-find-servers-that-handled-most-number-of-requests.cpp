class Solution {
public:
typedef pair<int,int> P;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>availableservers;
        for(int i=0;i<k;i++){
            availableservers.insert(i);
        }
        priority_queue<P,vector<P>,greater<P>>busyservers;
        vector<int>countrequests(k,0);
        for(int i=0;i<arrival.size();i++){
            int time=arrival[i];
            while(!busyservers.empty()&&busyservers.top().first<=time){
                int server=busyservers.top().second;
                busyservers.pop();
                availableservers.insert(server);
            }
            int target=i%k;
            auto it=availableservers.lower_bound(target);
            if(it==availableservers.end()){
                it=availableservers.begin();
            }
            if(availableservers.empty())continue;
            int targetservers=*it;
            availableservers.erase(it);
            busyservers.push({time+load[i],targetservers});
            countrequests[targetservers]++;
        }
        vector<int>result;
        int maxnumberofrequests=*max_element(countrequests.begin(),countrequests.end());
        for(int i=0;i<k;i++){
            if(countrequests[i]==maxnumberofrequests){
                result.push_back(i);
            }
        }
        return result;

    }
};