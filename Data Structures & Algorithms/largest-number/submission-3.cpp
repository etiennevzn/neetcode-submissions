class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string aFirst = to_string(a) + to_string(b);
            string bFirst = to_string(b) + to_string(a);
            return aFirst > bFirst;
        });

        string res;
        for(int num : nums){
            res += to_string(num);
        }

        return res[0] == '0' ? "0" : res;
    }
};