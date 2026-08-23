class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankset(bank.begin(),bank.end());
        queue<string>q;
        unordered_set<string>visited;
        q.push(startGene);
        visited.insert(startGene);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==endGene)
                return level;
                for(char ch:"ACGT"){
                    for(int i=0;i<curr.length();i++){
                        string neigh=curr;
                        neigh[i]=ch;
                        if(visited.find(neigh)==visited.end()&&bankset.find(neigh)!=bankset.end())
                        {
                            visited.insert(neigh);
                            q.push(neigh);
                        }
                    }
                }
            }
            level++;

        }
        return -1;
    }
};