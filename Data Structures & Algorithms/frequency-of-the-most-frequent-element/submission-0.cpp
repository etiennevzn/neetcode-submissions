class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int maxFreq = 1;

        unordered_set<int> uniques(nums.begin(), nums.end());
        for(int num : uniques){
            int cnt = k;
            vector<int> diffs(n);
            for(int i = 0; i < n; ++i){
                diffs[i] = num - nums[i];
            }

            sort(diffs.begin(), diffs.end());
            int freq = 0;
            for(int i = 0; i < diffs.size(); ++i){
                if(diffs[i] < 0) continue;
                if(diffs[i] > cnt || cnt == 0) break;

                freq++;
                cnt -= diffs[i];
            }

            maxFreq = max(maxFreq, freq);
        }

        return maxFreq;
    }
};