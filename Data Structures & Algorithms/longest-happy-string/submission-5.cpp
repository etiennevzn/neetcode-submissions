class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int,char>> maxHeap;
        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});

        while(!maxHeap.empty()){
            auto [count, letter] = maxHeap.top();
            maxHeap.pop();
            if(res.size() > 1 && res[res.size() - 1] == letter && res[res.size() - 2] == letter){
                if(maxHeap.empty()) return res;
                auto [count2, letter2] = maxHeap.top();
                maxHeap.pop();
                res.push_back(letter2);
                if(--count2 > 0) maxHeap.push({count2, letter2});
                maxHeap.push({count, letter});
            }else{
                res.push_back(letter);
                if(--count > 0) maxHeap.push({count, letter});
            }
        }    

        return res;
    }
};