class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<array<long long,4>> a(n);

        for(int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end());

        // next[i] = first interval whose start > a[i].end
        vector<int> next(n);

        for(int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;

            while(lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if(a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        // dp[i][k] = best score starting from i, choosing at most k
        vector<vector<long long>> dp(n + 1,
                                     vector<long long>(5, 0));

        vector<vector<vector<int>>> ans(
            n + 1,
            vector<vector<int>>(5)
        );

        for(int i = n - 1; i >= 0; i--) {

            for(int k = 1; k <= 4; k++) {

                // Skip
                dp[i][k] = dp[i + 1][k];
                ans[i][k] = ans[i + 1][k];

                // Take
                long long score =
                    a[i][2] + dp[next[i]][k - 1];

                vector<int> candidate = ans[next[i]][k - 1];
                candidate.push_back(a[i][3]);

                sort(candidate.begin(), candidate.end());

                if(score > dp[i][k] ||
                   (score == dp[i][k] &&
                    candidate < ans[i][k])) {

                    dp[i][k] = score;
                    ans[i][k] = candidate;
                }
            }
        }

        return ans[0][4];
    }
};