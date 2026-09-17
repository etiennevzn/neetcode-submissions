class Solution {
private:
    vector<string> res;
    void dfs(int i, int curVal, int nPts, string& curIp, const string& s){
        if(curVal > 255) return;

        if(i == s.size()){
            if(nPts == 3) res.push_back(curIp);
            return;
        }

        if(curIp.empty() || curIp.back() != '0' || curVal > 0){
            curVal *= 10;
            curVal += s[i] - '0';
            curIp.push_back(s[i]);
            dfs(i + 1, curVal, nPts, curIp, s);
            curIp.pop_back();
        }

        if(!curIp.empty() && curIp.back() != '.'){
            curIp.push_back('.');
            curVal = 0;
            dfs(i, curVal, nPts + 1, curIp, s);
            curIp.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return {};
        string curIp;
        dfs(0, 0, 0, curIp, s);
        return res;
    }
};