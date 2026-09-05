class Solution {
public:
    int minSwaps(string s) {
        stack<char> unmatched;
        for(const char& c : s){
            if(c == '['){
                unmatched.push(c);
            }else{
                if(!unmatched.empty()) unmatched.pop();
            }
        }

        return (unmatched.size() + 1) / 2;
    }
};