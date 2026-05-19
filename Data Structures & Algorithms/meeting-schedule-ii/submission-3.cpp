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
        if(intervals.empty()) return 0;

        vector<int> starts;
        vector<int> ends;

        for(const auto& i : intervals){
            starts.push_back(i.start);
            ends.push_back(i.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int cur = 0, res = 0, s = 0, e = 0;
        int n = intervals.size();

        while(s < n && e < n){
            while(s < n && starts[s++] < ends[e]){
                cur++;
            }
            e++;
            res = max(res, cur);
        }

        return res;
    }
};
