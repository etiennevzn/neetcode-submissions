class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const string& a, const string& b){
            if(a.size() > b.size()) return true;
            if(a.size() < b.size()) return false;

            int i = 0;
            while(i < a.size() && a[i] == b[i]) i++;
            if(i == a.size()) return false;
            if((a[i] - '0') > (b[i] - '0')) return true;
            return false;
        });

        return nums[k - 1];
    }
};
