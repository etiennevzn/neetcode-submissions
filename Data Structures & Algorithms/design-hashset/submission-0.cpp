class MyHashSet {
private:
    vector<int> hashset;
public:
    MyHashSet() {}
    
    void add(int key) {
        if(!contains(key)){
            hashset.push_back(key);
        }
    }
    
    void remove(int key) {
        if(contains(key)){
            hashset.erase(find(hashset.begin(), hashset.end(), key));
        }
    }
    
    bool contains(int key) {
        return find(hashset.begin(), hashset.end(), key) != hashset.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */