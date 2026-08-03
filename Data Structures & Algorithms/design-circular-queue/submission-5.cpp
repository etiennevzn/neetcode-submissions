class MyCircularQueue {
private:
    vector<int> q;
    int front, back, size, capacity;
public:
    MyCircularQueue(int k) : q(k, -1), front(0), back(0), size(0), capacity(k){}
    
    bool enQueue(int value) {
        if(!isFull()){
            q[back++] = value;
            back %= capacity;
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            front = (front + 1) % capacity;
            size--;
            return true;
        }
        return false;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[(back - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */