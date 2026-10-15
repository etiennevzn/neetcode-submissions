class Solution {
public:
    int compress(vector<char>& chars) {
        int insertPos = 0, i = 0, n = chars.size();
        
        while(i < n){
            chars[insertPos++] = chars[i];

            int j = i + 1;
            while(j < n && chars[j] == chars[j - 1]){
                j++;
            }

            if(j - i > 1){
                for(const char& c : to_string(j - i)){
                    chars[insertPos++] = c;
                }
            }

            i = j;
        }

        return insertPos;
    }
};