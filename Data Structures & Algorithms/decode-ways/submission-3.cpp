class Solution {
private:
    vector<int> mem;
    int dfs(const string& s, int i){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(mem[i] != -1) return mem[i];
        
        string two = "";
        two += s[i];
        two += s[i+1];
        if(i < s.size()-1 && stoi(two) <= 26){
            mem[i] = dfs(s, i+1) + dfs(s, i+2);
        }else{
            mem[i] = dfs(s, i+1);
        }

        return mem[i];
    }
public:
    int numDecodings(string s) {
        mem.resize(s.size(), -1);
        return dfs(s,0);
    }
};
