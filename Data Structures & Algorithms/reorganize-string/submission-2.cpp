class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for(const char& c : s) freq[c]++;
        priority_queue<pair<int,char>> maxHeap;

        for(const auto& p : freq){
            maxHeap.push({p.second, p.first});
        }
        
        string res = "";
        while(!maxHeap.empty()){
            auto [freq, c] = maxHeap.top();
            maxHeap.pop();
            if(res.empty() || c != res[res.size() - 1]){
                freq--;
                res.push_back(c);
                if(freq > 0) maxHeap.push({freq, c});
            }else if(!maxHeap.empty()){
                auto [freq2, c2] = maxHeap.top();
                maxHeap.pop();
                freq2--;
                res.push_back(c2);
                if(freq2 > 0) maxHeap.push({freq2, c2});
                maxHeap.push({freq, c});
            }else{
                return "";
            }
        }

        return res;
    }
};