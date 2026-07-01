class TimeMap {
private:
    unordered_map<int, unordered_map<string, string>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[timestamp][key] = value;
    }
    
    string get(string key, int timestamp) {
        for(int i = timestamp; i >= 0; --i){
            if(mp.count(i) && mp[i].count(key)){
                return mp[i][key];
            }
        }
        return "";
    }
};
