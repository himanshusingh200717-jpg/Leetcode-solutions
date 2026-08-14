class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>ans;
        for(int x=0;x<operations.size();x++){
            if(operations[x]=="C")
            ans.pop();
            else if(operations[x]=="D")
            ans.push(ans.top()*2);
            else if(operations[x]=="+"){
                int first=ans.top();
                ans.pop();
                int second=ans.top();
                ans.push(first);
                ans.push(first+second);
            }
            else
            ans.push(stoi(operations[x]));

        }
        int sum=0;
        while(!ans.empty()){
            sum+=ans.top();
            ans.pop();
        }
        return sum;
        
    }
};