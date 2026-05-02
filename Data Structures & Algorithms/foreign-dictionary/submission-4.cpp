class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;
    string res;

    string foreignDictionary(vector<string>& words) {
        for(const string& word : words){
            for(const char& c : word){
                adj[c];
                indegree[c] = 0;
            }
        }

        for(size_t i = 0; i < words.size()-1; ++i){
            const string& w1 = words[i], & w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());

            if(w1.size() > w2.size() && w1.substr(0,minLen) == w2.substr(0,minLen)){
                return "";
            }

            for(size_t j = 0; j < minLen; ++j){
                if(w1[j] != w2[j]){
                    if(adj[w1[j]].insert(w2[j]).second) indegree[w2[j]]++;
                    break;
                }
            }
        }

        queue<char> q;
        for(const auto& pair : adj){
           if(indegree[pair.first] == 0) q.push(pair.first);
        }

        while(!q.empty()){
            char cur = q.front(); q.pop();
            res.push_back(cur);
            for(const char& next : adj[cur]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }

        if(res.size() < adj.size()) return "";
        return res;
    }
};
