class Solution {
public:
    int compress(vector<char>& chars) {
        vector<pair<char,int>> charStack;

        for(const char& c : chars){
            if(!charStack.empty() && charStack.back().first == c){
                charStack.back().second++;
            }else{
                charStack.emplace_back(c, 1); 
            }
        }

        int insertPos = 0;
        for(const auto& p : charStack){
            chars[insertPos++] = p.first;
            if(p.second > 1){
                string count = to_string(p.second);
                for(const char& c : count){
                    chars[insertPos++] = c;
                }
            }
        }

        return insertPos;
    }
};