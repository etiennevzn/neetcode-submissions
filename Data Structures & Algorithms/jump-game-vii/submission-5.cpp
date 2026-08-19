class Solution {
private:
    vector<int> memo;

    bool dfs(int i, const string& s, int minJump, int maxJump){
        if(s[i] == '1') return memo[i] = false;
        if(i == s.size() - 1) return true;
        if(memo[i] != -1) return memo[i];

        for(int jump = maxJump; jump >= minJump; --jump){
            int arrival = i + jump;
            if(arrival > s.size() - 1) continue;
            if(dfs(arrival, s, minJump, maxJump)) return memo[i] = true;
        }
        
        return memo[i] = false;
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size() - 1] == '1') return false;
        memo.resize(s.size(), -1);
        return dfs(0, s, minJump, maxJump);
    }
};