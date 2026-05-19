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
        vector<pair<int,int>> time;
        int res = 0, cur = 0;

        for(const Interval& i : intervals){
            time.push_back({i.start, 1});
            time.push_back({i.end, -1});
        }

        sort(time.begin(), time.end(), [](auto& a, auto& b){
            return a.first == b.first ? a.second < b.second : a.first < b.first; 
        });

        for(const auto& p : time){
            cur += p.second;
            res = max(res, cur);
        }

        return res;
    }
};
