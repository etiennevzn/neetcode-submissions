class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1, B = nums2;
        if(A.size() > B.size()) swap(A,B);

        int total = A.size() + B.size();
        int half = (total)/2;

        int l = 0, r = A.size();
        while(l <= r){
            int m = l + (r-l)/2;
            int m2 = half-m;

            int Aleft = m-1 >= 0 ? A[m-1] : INT_MIN;
            int Aright = m < A.size() ? A[m] : INT_MAX;
            int Bleft = m2-1 >= 0 ? B[m2-1] : INT_MIN;
            int Bright = m2 < B.size() ? B[m2] : INT_MAX;

            if(Aleft <= Bright && Bleft <= Aright){
                if(total % 2){
                    return min(Aright,Bright);
                }else{
                    return (max(Aleft, Bleft) + min(Aright, Bright))/2.0;
                }
            }else if(Aleft > Bright){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return -1;
    }
};
