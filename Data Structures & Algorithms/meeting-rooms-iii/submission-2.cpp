class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> used;
        vector<int> count(n);

        for(int i = 0; i < n; ++i){
            available.push(i);
        }

        for(const auto& meeting : meetings){
            int begin = meeting[0], end = meeting[1];

            while(!used.empty() && used.top().first <= begin){
                auto [_, room] = used.top();
                used.pop();
                available.push(room);
            }

            if(available.empty()){
                auto [nextEnd, room] = used.top();
                used.pop();
                end = nextEnd + end - begin;
                available.push(room);
            }

            int room = available.top();
            available.pop();
            used.emplace(end, room);
            count[room]++;
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};