class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> folderList;
        vector<string> res;

        sort(folder.begin(), folder.end());
        for(const string& f : folder){
            string folderName = "";
            bool exists = false;
            for(const char& c : f){
                if(c == '/'){
                    if(folderList.count(folderName)){
                        exists = true;
                        break;
                    }
                }
                folderName.push_back(c);
            }
            if(!exists){
                res.push_back(f);
                folderList.insert(folderName);
            }
        }

        return res;
    }
};