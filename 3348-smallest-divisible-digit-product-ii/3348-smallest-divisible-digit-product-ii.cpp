class Solution {
public:
    int p2arr[10], p3arr[10];
    vector<vector<int>> f;

    void buildTable(int a, int b) {
        f.assign(a + 1, vector<int>(b + 1, 0));
        vector<pair<int,int>> digs = {{1,0},{0,1},{2,0},{1,1},{3,0},{0,2}}; // digits 2,3,4,6,8,9
        for (int x = 0; x <= a; x++) {
            for (int y = 0; y <= b; y++) {
                if (x == 0 && y == 0) { f[x][y] = 0; continue; }
                int best = INT_MAX;
                for (auto &pr : digs) {
                    int nx = max(0, x - pr.first), ny = max(0, y - pr.second);
                    if (nx == x && ny == y) continue;
                    best = min(best, 1 + f[nx][ny]);
                }
                f[x][y] = best;
            }
        }
    }

    inline bool feasible(long long remLen, int na, int nb, long long nc, long long nd) {
        if (remLen < nc + nd) return false;
        long long freeLen = remLen - nc - nd;
        return freeLen >= f[na][nb];
    }

    string buildSuffix(long long len, int a, int b, long long c, long long d) {
        string res(len, '1');
        int curA = a, curB = b; long long curC = c, curD = d;
        for (long long pos = 0; pos < len; pos++) {
            long long remaining = len - pos - 1;
            for (int v = 1; v <= 9; v++) {
                int na = max(0, curA - p2arr[v]);
                int nb = max(0, curB - p3arr[v]);
                long long nc = max(0LL, curC - (v == 5 ? 1 : 0));
                long long nd = max(0LL, curD - (v == 7 ? 1 : 0));
                if (feasible(remaining, na, nb, nc, nd)) {
                    res[pos] = char('0' + v);
                    curA = na; curB = nb; curC = nc; curD = nd;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        p2arr[1]=0;p2arr[2]=1;p2arr[3]=0;p2arr[4]=2;p2arr[5]=0;p2arr[6]=1;p2arr[7]=0;p2arr[8]=3;p2arr[9]=0;
        p3arr[1]=0;p3arr[2]=0;p3arr[3]=1;p3arr[4]=0;p3arr[5]=0;p3arr[6]=1;p3arr[7]=0;p3arr[8]=0;p3arr[9]=2;

        int a = 0, b = 0; long long c = 0, d = 0;
        long long tt = t;
        while (tt % 2 == 0) { tt /= 2; a++; }
        while (tt % 3 == 0) { tt /= 3; b++; }
        while (tt % 5 == 0) { tt /= 5; c++; }
        while (tt % 7 == 0) { tt /= 7; d++; }
        if (tt != 1) return "-1";

        buildTable(a, b);

        int n = num.size();
        vector<int> P2(n + 1, 0), P3(n + 1, 0);
        vector<long long> C5(n + 1, 0), C7(n + 1, 0);
        int z = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') { z = i; break; }
            int v = num[i] - '0';
            P2[i+1] = P2[i] + p2arr[v];
            P3[i+1] = P3[i] + p3arr[v];
            C5[i+1] = C5[i] + (v == 5 ? 1 : 0);
            C7[i+1] = C7[i] + (v == 7 ? 1 : 0);
        }

        if (z == n) {
            if (P2[n] >= a && P3[n] >= b && C5[n] >= c && C7[n] >= d) return num;
        }

        int maxI = min(z, n - 1);
        int foundI = -1, foundV = -1;
        for (int i = maxI; i >= 0; i--) {
            int lo = (i < z) ? (num[i] - '0' + 1) : 1;
            for (int v = lo; v <= 9; v++) {
                int na = max(0, a - (P2[i] + p2arr[v]));
                int nb = max(0, b - (P3[i] + p3arr[v]));
                long long nc = max(0LL, c - (C5[i] + (v == 5 ? 1 : 0)));
                long long nd = max(0LL, d - (C7[i] + (v == 7 ? 1 : 0)));
                long long remaining = n - 1 - i;
                if (feasible(remaining, na, nb, nc, nd)) { foundI = i; foundV = v; break; }
            }
            if (foundI != -1) break;
        }

        if (foundI != -1) {
            string ans = num.substr(0, foundI);
            ans += char('0' + foundV);
            int na = max(0, a - (P2[foundI] + p2arr[foundV]));
            int nb = max(0, b - (P3[foundI] + p3arr[foundV]));
            long long nc = max(0LL, c - (C5[foundI] + (foundV == 5 ? 1 : 0)));
            long long nd = max(0LL, d - (C7[foundI] + (foundV == 7 ? 1 : 0)));
            long long suffixLen = n - 1 - foundI;
            ans += buildSuffix(suffixLen, na, nb, nc, nd);
            return ans;
        }

        long long minLen = c + d + f[a][b];
        long long L = max((long long)(n + 1), minLen);
        return buildSuffix(L, a, b, c, d);
    }
};