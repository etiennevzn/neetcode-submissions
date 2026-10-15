class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        stack<int> positives;
        stack<int> negatives;

        for(int num : nums){
            if(num < 0) negatives.push(num);
            if(num > 0) positives.push(num);
        }

        vector<int> res;
        while(!negatives.empty() && !positives.empty()){
            res.push_back(negatives.top());
            negatives.pop();
            res.push_back(positives.top());
            positives.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};