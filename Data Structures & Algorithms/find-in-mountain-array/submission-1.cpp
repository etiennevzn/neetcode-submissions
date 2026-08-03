/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    unordered_map<int,int> memo;
    int findPeak(MountainArray &mountainArr){
        int l = 0, r = mountainArr.length() - 1;
        while(l < r){
            int m = l + (r - l)/2;
            int valm = memo.find(m) != memo.end() ? memo[m] : memo[m] = mountainArr.get(m);
            int valmsup = memo.find(m+1) != memo.end() ? memo[m+1] : memo[m+1] = mountainArr.get(m+1);

            if(valm < valmsup){
                l = m + 1;
            }else{
                r = m;
            }
        }

        return l;
    }

    int findLeft(MountainArray &mountainArr, int r, int target){
        int l = 0;
        while(l <= r){
            int m = l + (r - l)/2;
            int valm = memo.find(m) != memo.end() ? memo[m] : memo[m] = mountainArr.get(m);

            if(valm == target){
                return m;
            }else if(valm < target){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }

        return -1;
    }

    int findRight(MountainArray &mountainArr, int l, int target){
        int r = mountainArr.length() - 1;
        while(l <= r){
            int m = l + (r - l)/2;
            int valm = memo.find(m) != memo.end() ? memo[m] : memo[m] = mountainArr.get(m);

            if(valm == target){
                return m;
            }else if(valm < target){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }

        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        int idx = findLeft(mountainArr, peak, target);
        if(idx == -1) idx = findRight(mountainArr, peak + 1, target);

        return idx;
    }
};