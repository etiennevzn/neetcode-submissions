class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
        }

        int k = 0;
        for(int i = 0; i < 3; i++){
            while(count[i]){
                nums[k] = i;
                count[i]--;
                k++;
            }
        }
    }
};