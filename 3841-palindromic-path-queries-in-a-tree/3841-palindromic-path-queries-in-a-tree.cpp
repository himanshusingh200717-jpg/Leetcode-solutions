
class Solution {
    int n, LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit, val;

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    void updateBIT(int idx, int x) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] ^= x;
        }
    }

    int queryBIT(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx) {
            ans ^= bit[idx];
        }
        return ans;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n,
                                vector<vector<int>>& edges,
                                string s,
                                vector<string>& queries) {
        this->n = n;
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        timer = 0;
        adj.assign(n, {});

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, 0));
        bit.assign(n + 2, 0);
        val.assign(n, 0);

        dfs(0, 0);

        for (int u = 0; u < n; u++) {
            val[u] = 1 << (s[u] - 'a');
            updateBIT(tin[u], val[u]);
            updateBIT(tout[u] + 1, val[u]);
        }

        vector<bool> ans;

        for (string &q : queries) {
            string type, extra;
            int u;

            stringstream ss(q);
            ss >> type >> u >> extra;

            if (type == "update") {
                char c = extra[0];
                int newVal = 1 << (c - 'a');
                int delta = val[u] ^ newVal;

                updateBIT(tin[u], delta);
                updateBIT(tout[u] + 1, delta);

                val[u] = newVal;
            } else {
                int v = stoi(extra);
                int w = lca(u, v);

                int maskU = queryBIT(tin[u]);
                int maskV = queryBIT(tin[v]);

                int pathMask = maskU ^ maskV ^ val[w];

                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
