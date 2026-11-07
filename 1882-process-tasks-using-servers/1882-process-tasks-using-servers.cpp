class Solution {
public:
typedef pair<int,int>  P;
typedef tuple<long,int,int> T;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        priority_queue<P,vector<P>,greater<P>>freeservers;
        priority_queue<T,vector<T>,greater<T>>busyservers;
        for(int i=0;i<n;i++){
            freeservers.push({servers[i],i});
        }
        vector<int>result(m);
        for(int i=0;i<m;i++){
            while(!busyservers.empty()&&get<0>(busyservers.top())<=i){
                auto [fintime,wt,idx]=busyservers.top();
                busyservers.pop();
                freeservers.push({wt,idx});
            }
            if(freeservers.empty()){
                auto [fintime,wt,idx]=busyservers.top();
                busyservers.pop();
                result[i]=idx;
                busyservers.push({fintime+tasks[i],wt,idx});
            }else{
                auto[wt,idx]=freeservers.top();
                freeservers.pop();
                result[i]=idx;
                busyservers.push({i+tasks[i],wt,idx});
            }
        }
        return result;
    }
};