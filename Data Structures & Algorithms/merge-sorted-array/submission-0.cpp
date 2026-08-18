class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        int pt1 = 0, pt2 = 0;

        while(pt1 < m && pt2 < n){
            if(nums1[pt1] < nums2[pt2]){
                tmp.push_back(nums1[pt1++]);
            }else{
                tmp.push_back(nums2[pt2++]);
            }
        }

        while(pt1 < m) tmp.push_back(nums1[pt1++]);
        while(pt2 < n) tmp.push_back(nums2[pt2++]);

        nums1 = tmp;
    }
};