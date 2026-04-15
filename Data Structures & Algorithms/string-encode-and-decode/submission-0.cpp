class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(const string& str : strs){
            encoded += std::to_string(str.size());
            encoded.push_back('#');
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        int len;
        string lenStr;
        int i = 0;
        int n = s.size();
        vector<string> result;
        while(i < n){
            while(s[i] != '#'){
                lenStr += s[i];
                i++;
            }
            len = std::stoi(lenStr);
            lenStr.clear();
            if(s[i] == '#') i++;
            string temp = s.substr(i,len);
            result.push_back(temp);
            i += len;
        }

        return result;
    }
};
