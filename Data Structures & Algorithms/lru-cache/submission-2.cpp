class LRUCache {
public:
    unordered_map<int,int> cache;
    deque<int> keys;
    int capacity_;

    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)){
            auto it = find(keys.begin(), keys.end(), key);
            keys.push_back(*it);
            keys.erase(it);
            return cache[key];
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            cache[key] = value;
            auto it = find(keys.begin(), keys.end(), key);
            keys.push_back(*it);
            keys.erase(it);
            return;
        } 

        if(keys.size() == capacity_){
            cache.erase(keys.front());
            keys.pop_front();
        }
        keys.push_back(key);
        cache[key] = value;
    }
};
