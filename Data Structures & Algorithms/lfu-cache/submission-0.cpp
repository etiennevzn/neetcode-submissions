class LFUCache {
private:
    struct Compare {
        bool operator()(vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] > b[0];
        }
    };

    priority_queue<vector<int>, vector<vector<int>>, Compare> minHeap;
    unordered_map<int,pair<int,int>> cache;
    int cap, size;
    int time = 0; 
public:
    LFUCache(int capacity) : cap(capacity), size(0) {}
    
    int get(int key) {
        time++;
        if(!cache.count(key)) return -1;
        minHeap.push({++cache[key].second, time, key});
        return cache[key].first;
    }
    
    void put(int key, int value) {
        time++;
        if(cache.count(key)){
            cache[key].first = value;
            minHeap.push({++cache[key].second, time, key});
        }else{
            if(size == cap){
                while(!cache.count(minHeap.top()[2]) || cache[minHeap.top()[2]].second != minHeap.top()[0]) minHeap.pop();
                cache.erase(minHeap.top()[2]);
                minHeap.pop();
                cache[key] = {value, 1};
                minHeap.push({1, time, key});
            }else{
                cache[key] = {value, 1};
                minHeap.push({1, time, key});
                size++;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */