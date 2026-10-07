class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        // len(A) = a, len(B) = b, let a <= b
        // avg(A) = avg(B)
        // sum(A) / a = sum(B) / b = sum(nums) / n
        // sum(A) / a = avg => sum(A) = a * avg
        // sum(A) = a * sum(nums) / n
        // Find if any subset exists with a * sum(nums) / n
        // a is in the range [1, (n//2)]

        vector<vector<vector<int>>> memo(n + 1,
            vector<vector<int>>(n / 2 + 1, vector<int>(total + 1, -1)));

        function<bool(int, int, int)> dfs = [&](int i, int a, int s) -> bool {
            if (a == 0) return s == 0;
            if (i == n || s < 0 || a < 0) return false;
            if (memo[i][a][s] != -1) return memo[i][a][s];

            bool res = dfs(i + 1, a, s) || dfs(i + 1, a - 1, s - nums[i]);
            memo[i][a][s] = res;
            return res;
        };

        for (int a = 1; a <= n / 2; ++a) {
            if ((total * a) % n == 0) {
                int target = (total * a) / n;
                if (dfs(0, a, target)) return true;
            }
        }

        return false;
    }
};