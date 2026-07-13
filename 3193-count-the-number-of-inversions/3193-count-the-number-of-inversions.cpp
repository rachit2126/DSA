class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {

        vector<int> req(n, -1);
        int maxInv = 0;

        for (auto &r : requirements) {
            req[r[0]] = r[1];
            maxInv = max(maxInv, r[1]);
        }

        vector<vector<int>> dp(n, vector<int>(maxInv + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {

            for (int inv = 0; inv <= maxInv; inv++) {

                long long ways = 0;

                for (int add = 0; add <= min(i, inv); add++) {
                    ways += dp[i - 1][inv - add];
                    ways %= MOD;
                }

                dp[i][inv] = ways;
            }

            if (req[i] != -1) {
                for (int inv = 0; inv <= maxInv; inv++) {
                    if (inv != req[i])
                        dp[i][inv] = 0;
                }
            }
        }

        if (req[n - 1] != -1)
            return dp[n - 1][req[n - 1]];

        long long ans = 0;

        for (int inv = 0; inv <= maxInv; inv++)
            ans = (ans + dp[n - 1][inv]) % MOD;

        return ans;
    }
};