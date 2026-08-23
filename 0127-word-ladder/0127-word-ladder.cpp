class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>word(wordList.begin(),wordList.end());
    unordered_set<string>visited;
    queue<string>q;
    string collection="qwertyuiopasdfghjklzxcvbnm";
    int count=1;
    visited.insert(beginWord);
    q.push(beginWord);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            string curr=q.front();
            q.pop();
            if(curr==endWord)
            return count;
            for(char ch:collection){
                for(int j=0;j<curr.length();j++){
                    string neigh=curr;
                    neigh[j]=ch;
                    if(visited.find(neigh)==visited.end()&&word.find(neigh)!=word.end()){
                        visited.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
        }
        count++;
    }
    return 0;
        
    }
};