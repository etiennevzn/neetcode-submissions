class Solution {
public:
    string simplifyPath(string path) {
        stack<string> parts;

        string part = "";
        for(int i = 0; i < path.size(); ++i){
            const char& c = path[i];
            if(c == '/' || i == path.size() - 1){
                if(i == path.size() - 1 && c != '/') part.push_back(c);
                if(part == ".."){
                    if(!parts.empty()) parts.pop();
                }else if(part != "." && !part.empty()){
                    parts.push(part);
                }
                part = "";
            }else{
                part.push_back(c);
            }
        }
        
        if(parts.empty()) return "/";
        vector<string> tmp;
        while(!parts.empty()){
            tmp.push_back(parts.top());
            parts.pop();
        }

        reverse(tmp.begin(), tmp.end());
        string res = "";
        for(const string& part : tmp){
            res.push_back('/');
            for(const char& c : part) res.push_back(c);
        }

        return res;
    }
};