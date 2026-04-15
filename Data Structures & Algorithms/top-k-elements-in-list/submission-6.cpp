class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> count;
        for(const auto& num : nums){
            count[num]++;
        }

        std::priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for(const auto& p : count){
            heap.push({p.second, p.first});
            if(heap.size() > k){
                heap.pop();
            }
        }

        vector<int> result;
        for(int i = 0; i<k; i++){
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};
