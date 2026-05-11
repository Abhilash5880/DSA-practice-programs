class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return trav(dp, 0, 0, m, n);
    }

private:
    int trav(vector<vector<int>>& dp, int i, int j, int m, int n) {

        // ❌ Out of bounds → no valid path
        if (i >= m || j >= n) return 0;

        // 🎯 Reached destination → one valid path
        if (i == m - 1 && j == n - 1) return 1;

        // 🔁 Already computed → reuse result
        if (dp[i][j] != -1) return dp[i][j];

        // ⚡ Recursive relation
        int right = trav(dp, i, j + 1, m, n);
        int down  = trav(dp, i + 1, j, m, n);

        // 🧠 Store result
        dp[i][j] = right + down;

        return dp[i][j];
    }
};