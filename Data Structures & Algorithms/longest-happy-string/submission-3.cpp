class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int,char>> maxHeap;
        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});
        int streak = 0;

        while(!maxHeap.empty()){
            auto [count, letter] = maxHeap.top();
            maxHeap.pop();
            if(!res.empty()){
                if(letter != res.back()){
                    res.push_back(letter);
                    streak = 1;
                    if(--count > 0){
                        maxHeap.push({count, letter});
                    }
                }else{
                    if(streak < 2){
                        res.push_back(letter);
                        streak++;
                        if(--count > 0){
                            maxHeap.push({count, letter});
                        }
                    }else{
                        if(maxHeap.empty()) return res;
                        auto [count2, letter2] = maxHeap.top();
                        maxHeap.pop();
                        res.push_back(letter2);
                        streak = 1;
                        if(--count2 > 0){
                            maxHeap.push({count2, letter2});
                        }
                        maxHeap.push({count, letter});
                    }
                }
            }else{
                res.push_back(letter);
                streak = 1;
                if(--count > 0){
                    maxHeap.push({count, letter});
                }
            }
        }

        return res;
    }
};