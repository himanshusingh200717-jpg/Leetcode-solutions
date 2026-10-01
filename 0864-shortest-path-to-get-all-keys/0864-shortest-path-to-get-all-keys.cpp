class Solution {
public:
vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<vector<int>>q;
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    q.push({i,j,0,0});
                }else if(grid[i][j]>='a'&&grid[i][j]<='f'){
                    count++;
                }

            }
        }
        int final_key_status_decimal=pow(2,count)-1;
        int visited[m][n][final_key_status_decimal+1];
        memset(visited,0,sizeof(visited));
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int i=temp[0];
            int j=temp[1];
            int steps=temp[2];
            int current_key_status_decimal=temp[3];
            if(current_key_status_decimal==final_key_status_decimal)return steps;
            for(auto &d:dir){
                int n_i=i+d[0];
                int n_j=j+d[1];
                if(n_i>=0&&n_i<m&&n_j>=0&&n_j<n&&grid[n_i][n_j]!='#'){
                    char ch=grid[n_i][n_j];
                    if(ch>='A'&&ch<='F'){
                        if(visited[n_i][n_j][current_key_status_decimal]==0&&((current_key_status_decimal>>(ch-'A'))&1==1)){
                            visited[n_i][n_j][current_key_status_decimal]=1;
                             q.push({n_i,n_j,steps+1,current_key_status_decimal});
                        }

                    }else if(ch>='a'&&ch<='f'){
                        int new_key_status_decimal=current_key_status_decimal|(1<<(ch-'a'));
                        if(visited[n_i][n_j][new_key_status_decimal]==0){
                            visited[n_i][n_j][new_key_status_decimal]=1;
                             q.push({n_i,n_j,steps+1,new_key_status_decimal});
                        }
                        
                    }else{
                        if(visited[n_i][n_j][current_key_status_decimal]==0){
                            visited[n_i][n_j][current_key_status_decimal]=1;
                            q.push({n_i,n_j,steps+1,current_key_status_decimal});
                        }
                    }
                }
            }
        }

        return -1;

        
    }
};