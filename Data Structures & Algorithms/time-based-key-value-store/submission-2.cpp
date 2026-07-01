class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> val = mp[key];
        int l = 0, r = val.size()-1;

        string cur;
        while(l <= r){
            int m = l + (r-l)/2;
            if(val[m].first == timestamp){
                return val[m].second;
            }else if(val[m].first < timestamp){
                cur = val[m].second;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }

        return cur;
    }
};
