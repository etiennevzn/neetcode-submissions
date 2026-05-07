class Solution {
public:
    int numDecodings(string s) {
        int next2 = 1;
        int next1 = 1;

        for(int i = s.size()-1; i >= 0; --i){
            if(s[i] == '0'){
                int temp = 0;
                next2 = next1;
                next1 = temp;
            }else{
                int temp = next1;
                string two = "";
                two += s[i];
                two += s[i+1];
                if(i < s.size()-1 && stoi(two) <= 26) temp += next2;
                next2 = next1;
                next1 = temp;
            }
        }
        
        return next1;
    }
};
