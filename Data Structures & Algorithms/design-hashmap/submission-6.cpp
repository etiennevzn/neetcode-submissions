class MyHashMap {
private:
    struct ListNode{
        int key, val;
        ListNode* next;

        ListNode(int key = -1, int val = -1, ListNode* next = nullptr) : key(key), val(val), next(next) {}
    };

    vector<ListNode*> map;

    int hash(int key){
        return key % map.size();
    }

public:
    MyHashMap() : map(1000){
        for(auto& bucket : map){
            bucket = new ListNode(0);
        }
    }
    
    void put(int key, int value) {
        int bucket = hash(key);
        ListNode* cur = map[bucket];
        while(cur->next){
            if(cur->next->key == key){
                cur->next->val = value;
                return;
            }
            cur = cur->next;
        }

        cur->next = new ListNode(key, value);
    }
    
    int get(int key) {
        int bucket = hash(key);
        ListNode* cur = map[bucket];
        while(cur->next){
            if(cur->next->key == key) return cur->next->val;
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket = hash(key);
        ListNode* cur = map[bucket];
        while(cur->next){
            if(cur->next->key == key){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */