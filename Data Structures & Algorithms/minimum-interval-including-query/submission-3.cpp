class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res(queries.size());
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> sortedQueries;
        for(int i = 0; i < queries.size(); ++i){
            sortedQueries.push_back({queries[i],i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        int i = 0;
        for(const auto& [query, idx] : sortedQueries){
            while(i < intervals.size() && intervals[i][0] <= query){
                minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }
            while(!minHeap.empty() && minHeap.top().second < query){
                minHeap.pop();
            }

            if(minHeap.empty()){
                res[idx] = -1;
            }else{
                res[idx] = minHeap.top().first;
            }
        } 
        return res;
    }
};
