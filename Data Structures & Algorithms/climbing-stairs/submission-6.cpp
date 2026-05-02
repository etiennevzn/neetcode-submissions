class Solution {
private:
int dfs(int i, int n, vector<int>& cache){
    if(i == n) return 1;
    if(i > n) return 0;
    if(cache[i] != -1) return cache[i];
    cache[i] = dfs(i+1,n,cache) + dfs(i+2,n,cache);
    return cache[i];
}
public:
    int climbStairs(int n) {
        vector<int> cache(n, -1);
        return dfs(0, n, cache);
    }
};
