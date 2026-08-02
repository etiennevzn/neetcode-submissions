class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(const char& c : s){
            if(c == ']'){
                string tmp = "";
                while(st.top() != '['){
                    tmp.push_back(st.top());
                    st.pop();
                }
                reverse(tmp.begin(), tmp.end());
                st.pop();

                string mult = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    mult.push_back(st.top());
                    st.pop();
                }
                reverse(mult.begin(), mult.end());
                int m = stoi(mult);

                for(int i = 0; i < m; ++i){
                    for(const char& c : tmp){
                        st.push(c);
                    }
                }
            }else{
                st.push(c);
            }
        }

        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};