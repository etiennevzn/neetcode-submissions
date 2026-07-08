class Solution {
private:
    vector<string> res;

    unordered_map<char,string> digitsMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    void backtrack(int i, string& cur, string& digits){
        if(cur.size() == digits.size()){
            res.push_back(cur);
            return;
        }

        for(const char& c : digitsMap[digits[i]]){
            cur.push_back(c);
            backtrack(i+1, cur, digits);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.empty()) return res;
        string cur;
        backtrack(0, cur, digits);
        return res;
    }
};
