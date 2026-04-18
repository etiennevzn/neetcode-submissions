class Solution {
public:
    int findMin(vector<int> &nums) {
        int min = INT_MAX;

        for(const int& num : nums){
            min = num < min ? num : min;
        }

        return min;
    }
};
