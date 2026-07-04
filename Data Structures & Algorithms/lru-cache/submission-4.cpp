class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    Node* dummyHead;
    Node* dummyTail;
    int capacity_;
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) : capacity_(capacity), dummyHead(new Node(-1,-1)), dummyTail(new Node(-1,-1)){
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        if(cache.count(key)){
            Node* curNode = cache[key];
            curNode->prev->next = curNode->next;
            curNode->next->prev = curNode->prev;
            dummyTail->prev->next = curNode;
            curNode->prev = dummyTail->prev;
            curNode->next = dummyTail;
            dummyTail->prev = curNode;
            return curNode->val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* curNode = cache[key];
            curNode->val = value;

            curNode->prev->next = curNode->next;
            curNode->next->prev = curNode->prev;
            dummyTail->prev->next = curNode;
            curNode->prev = dummyTail->prev;
            curNode->next = dummyTail;
            dummyTail->prev = curNode;
            return;
        } 

        if(cache.size() == capacity_){
            Node* curNode = dummyHead->next;
            dummyHead->next = curNode->next;
            curNode->next->prev = dummyHead;
            cache.erase(curNode->key);
            delete curNode;
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        dummyTail->prev->next = newNode;
        newNode->prev = dummyTail->prev;
        newNode->next = dummyTail;
        dummyTail->prev = newNode;
    }
};
