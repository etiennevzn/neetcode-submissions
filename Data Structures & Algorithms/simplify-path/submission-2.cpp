class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts;
        string part = "";
        for(const char& c : path + "/"){
            if(c == '/'){
                if(part == ".."){
                    if(!parts.empty()) parts.pop_back();
                }else if(part != "." && !part.empty()){
                    parts.push_back(part);
                }
                part = "";
            }else{
                part.push_back(c);
            }
        }

        if(parts.empty()) return "/";
        string res = "";
        for(const string& part : parts){
            res.push_back('/');
            res += part;
        }

        return res;
    }
};