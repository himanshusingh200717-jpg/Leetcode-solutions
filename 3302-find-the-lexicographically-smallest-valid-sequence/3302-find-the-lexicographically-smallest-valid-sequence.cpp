class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        // prevPos[i][c] = i se pehle character c ka latest index
        vector<array<int, 26>> prevPos(n + 1);

        for (int c = 0; c < 26; c++)
            prevPos[0][c] = -1;

        for (int i = 0; i < n; i++) {
            prevPos[i + 1] = prevPos[i];
            prevPos[i + 1][word1[i] - 'a'] = i;
        }

        // exact[i] = word2[i...] ko exactly match karne
        // ka latest possible starting index
        vector<int> exact(m, -1);

        // one[i] = word2[i...] ko at most 1 mismatch ke
        // saath match karne ka latest possible starting index
        vector<int> one(m, -1);

        // Last character
        int p = prevPos[n][word2[m - 1] - 'a'];

        exact[m - 1] = p;
        one[m - 1] = n - 1;   // last position ko mismatch bhi kar sakte hain

        for (int i = m - 2; i >= 0; i--) {

            // -------------------------
            // Exact suffix
            // -------------------------
            if (exact[i + 1] != -1) {
                exact[i] =
                    prevPos[exact[i + 1]][word2[i] - 'a'];
            }

            // -------------------------
            // At most one mismatch
            // -------------------------

            // Case 1:
            // current character exact hai,
            // remaining suffix mein 1 mismatch allowed
            int takeExact = -1;

            if (one[i + 1] != -1) {
                takeExact =
                    prevPos[one[i + 1]][word2[i] - 'a'];
            }

            // Case 2:
            // current character mismatch hai,
            // remaining suffix EXACT hona chahiye
            int takeMismatch = -1;

            if (exact[i + 1] != -1) {
                takeMismatch = exact[i + 1] - 1;

                if (takeMismatch >= 0) {
                    takeMismatch =
                        exact[i + 1] - 1;
                }
            }

            // We need latest position before exact[i+1]
            // whose character is DIFFERENT from word2[i]
            if (exact[i + 1] != -1) {

                int bound = exact[i + 1];

                takeMismatch = bound - 1;

                if (takeMismatch >= 0 &&
                    word1[takeMismatch] == word2[i]) {

                    // Find latest different character
                    for (int c = 0; c < 26; c++) {
                        if (c != word2[i] - 'a') {
                            takeMismatch =
                                max(takeMismatch,
                                    prevPos[bound][c]);
                        }
                    }
                } else if (takeMismatch >= 0) {
                    // already different
                } else {
                    takeMismatch = -1;
                }
            }

            one[i] = max(takeExact, takeMismatch);
        }

        // -------------------------
        // Greedy answer
        // -------------------------

        vector<int> ans;

        int prev = -1;
        bool usedMismatch = false;

        for (int i = 0; i < m; i++) {

            bool found = false;

            for (int p = prev + 1; p < n; p++) {

                // Current exact match.
                // Remaining part can use the one mismatch.
                if (word1[p] == word2[i]) {

                    if (i == m - 1 || one[i + 1] > p) {

                        ans.push_back(p);
                        prev = p;
                        found = true;
                        break;
                    }
                }

                // Current character is the one mismatch.
                // Remaining part must be exact.
                if (!usedMismatch &&
                    word1[p] != word2[i]) {

                    if (i == m - 1 || exact[i + 1] > p) {

                        ans.push_back(p);
                        prev = p;
                        usedMismatch = true;
                        found = true;
                        break;
                    }
                }
            }

            if (!found)
                return {};
        }

        return ans;
    }
};