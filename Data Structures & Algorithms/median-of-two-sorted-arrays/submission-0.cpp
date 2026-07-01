class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined;
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                combined.push_back(nums1[i++]);
            }else{
                combined.push_back(nums2[j++]);
            }
        }

        while(i < nums1.size()) combined.push_back(nums1[i++]);
        while(j < nums2.size()) combined.push_back(nums2[j++]);

        if(combined.size() % 2){
            return combined[combined.size()/2];
        }else{
            return (combined[combined.size()/2] + combined[combined.size()/2 - 1]) / 2.0;
        }
    }
};
