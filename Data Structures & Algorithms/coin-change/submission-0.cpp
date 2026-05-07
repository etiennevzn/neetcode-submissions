class Solution {
private:
    unordered_map<int,int> mem;
    int dfs(vector<int>& coins, int amount){
        if(amount < 0) return INT_MAX;
        if(amount == 0) return 0;

        if(mem.count(amount)) return mem[amount];

        int mini = INT_MAX;
        for(int c : coins){
            int res = dfs(coins, amount-c);
            if(res != INT_MAX) mini = min(mini, 1+res);
        }

        mem[amount] = mini;
        return mem[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int res = dfs(coins, amount);
        return res == INT_MAX ? -1 : res;
    }
};
