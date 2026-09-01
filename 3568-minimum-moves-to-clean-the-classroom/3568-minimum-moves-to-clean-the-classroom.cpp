class Solution {
public:
using VB=vector<bool>;
using VVB=vector<VB>;
using VVVB=vector<VVB>;
using VVVVB=vector<VVVB>;
vector<vector<int>>directions={{0,-1},{0,1},{-1,0},{1,0}};
struct state{
    int row;
    int col;
    int energyleft;
    int collectedmask;
};
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int maxenergy=energy;
        int litterbit[20][20];
        int littercount=0;
        int startr=0;
        int startc=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                litterbit[r][c]=-1;
                if(classroom[r][c]=='S'){
                    startr=r;
                    startc=c;
                }else if(classroom[r][c]=='L'){
                    litterbit[r][c]=littercount;
                    littercount++;
                }
            }
        }
        int allcollected=(1<<littercount)-1;
        if(littercount==0)return 0;
        VVVVB visited(m,VVVB(n,VVB(maxenergy+1,VB(1<<littercount,false))));
queue<state>q;
q.push({startr,startc,maxenergy,0});
visited[startr][startc][maxenergy][0]=true;
int moves=0;
while(!q.empty()){
    int size=q.size();
    while(size--){
        state curr=q.front();
        q.pop();
        if(curr.collectedmask==allcollected){
            return moves;
        }
        if(curr.energyleft==0){
            continue;
        }
        for(auto &dir:directions){
            int nextrow=curr.row+dir[0];
            int nextcol=curr.col+dir[1];
            if(nextrow<0||nextrow>=m||nextcol<0||nextcol>=n)continue;
            char cell=classroom[nextrow][nextcol];
            if(cell=='X')continue;
            int nextenergy=curr.energyleft-1;
            int nextcollectedmask=curr.collectedmask;
            if(cell=='R'){
                nextenergy=maxenergy;
            }else if(cell=='L'){
                nextcollectedmask|=(1<<litterbit[nextrow][nextcol]);
            }
            if(!visited[nextrow][nextcol][nextenergy][nextcollectedmask]){
                visited[nextrow][nextcol][nextenergy][nextcollectedmask]=true;
                q.push({nextrow,nextcol,nextenergy,nextcollectedmask});

            }
        }
    }
    moves++;
}return -1;

        
    }
};