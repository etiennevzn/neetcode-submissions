class LFUCache {
private:
    struct Node{
        int key;
        int val;
        int freq;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), val(v), freq(1), next(nullptr), prev(nullptr){}
    };

    struct LinkedList{
        Node* left;
        Node* right;
        int size;

        LinkedList() : size(0), left(new Node(-1,-1)), right(new Node(-1, -1)){
            left->next = right;
            right->prev = left;
        }

        ~LinkedList(){
            delete left;
            delete right;
        }

        int length(){return size;}

        void pushRight(Node* node){
            right->prev->next = node;
            node->prev = right->prev;
            right->prev = node;
            node->next = right;
            size++;
        }

        void pop(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = nullptr;
            node->next = nullptr;
            size--;
        }

        Node* popLeft(){
            Node* res = left->next;
            pop(res);
            return res;
        }
    };

    void counter(Node* node){
        int count = node->freq;
        freqMap[count]->pop(node);
        if(minFreq == count && freqMap[count]->length() == 0) minFreq++;

        count++;
        if(!freqMap.count(count)) freqMap[count] = new LinkedList();
        node->freq = count;
        freqMap[count]->pushRight(node);
    }

    unordered_map<int,Node*> nodeMap;
    unordered_map<int,LinkedList*> freqMap;
    int minFreq, capacity;
    
public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    ~LFUCache(){
        for(auto& pair : nodeMap){
            delete pair.second;
        }

        for(auto& pair : freqMap){
            delete pair.second;
        }
    }
    
    int get(int key) {
        if(nodeMap.count(key)){
            Node* node = nodeMap[key];
            counter(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(nodeMap.count(key)){
            Node* node = nodeMap[key];
            node->val = value;
            counter(node);
            return;
        }

        if(nodeMap.size() == capacity){
            Node* toDelete = freqMap[minFreq]->popLeft();
            nodeMap.erase(toDelete->key);
            delete toDelete;
        }

        Node* node = new Node(key, value);
        nodeMap[key] = node;
        if(!freqMap.count(1)) freqMap[1] = new LinkedList();
        freqMap[1]->pushRight(node);
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */