class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.empty() || secondList.empty()) return {};
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;  

        vector<vector<int>> res;
        while(i < n && j < m){
            int start1 = firstList[i][0], end1 = firstList[i][1];
            int start2 = secondList[j][0], end2 = secondList[j][1];

            if((start2 <= end1 && end2 >= start1) || (start1 <= end2 && end1 >= start2)){
                res.push_back({max(start1,start2), min(end1, end2)});
            }

            if(end1 < end2){
                i++;
            }else{
                j++;
            }
        }

        return res;
    }
};