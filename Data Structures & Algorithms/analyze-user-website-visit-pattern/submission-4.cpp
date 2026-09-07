class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> historic;
        int n = username.size();
        for(int i = 0; i < n; ++i){
            historic[username[i]].emplace_back(timestamp[i], website[i]);
        }

        for(auto& [_, sites] : historic) sort(sites.begin(), sites.end());

        unordered_map<string, unordered_set<string>> patternCount;
        for(const auto& [user, sites] : historic){
            int s = sites.size();

            for(int i = 0; i < s; ++i){
                for(int j = i + 1; j < s; ++j){
                    for(int k = j + 1; k < s; ++k){
                        string pattern = sites[i].second + "," + sites[j].second + "," + sites[k].second;
                        patternCount[pattern].insert(user);
                    }
                }
            }
        }

        vector<pair<int, string>> candidates;
        for(const auto& [pattern, count] : patternCount){
            candidates.emplace_back(count.size(), pattern);
        }
        sort(candidates.rbegin(), candidates.rend());
        int maxVisits = candidates[0].first;

        vector<string> finalCandidates;
        for(const auto& [count, pattern] : candidates){
            if(count < maxVisits) break;
            finalCandidates.push_back(pattern);
        }

        sort(finalCandidates.begin(), finalCandidates.end());
        string final = finalCandidates[0];
        
        vector<string> res;
        string curStr = "";
        for(char c : final){
            if(c == ','){
                res.push_back(curStr);
                curStr.clear();
            }else{
                curStr.push_back(c);
            }
        }
        res.push_back(curStr);

        return res;
    }
};