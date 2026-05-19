/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> mp;
        for(const Interval& i : intervals){
            mp[i.start]++;
            mp[i.end]--;
        }
    
        int res = 0, cur = 0;
        for(auto& [key, value] : mp){
            cur += value;
            res = max(res, cur);
        }

        return res;
    }
};
