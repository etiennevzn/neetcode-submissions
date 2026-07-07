class Twitter {
private:
    unordered_map<int,unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    int tweetCounter = 0;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({tweetCounter++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> tweetHeap(cmp);

        followMap[userId].insert(userId);
        for(int followee : followMap[userId]){
            if(tweetMap.count(followee)){
                const vector<pair<int,int>>& tweets = tweetMap[followee];
                int index = tweets.size() - 1;
                tweetHeap.push({tweets[index].first, tweets[index].second, followee, index});
            }
        }

        while(!tweetHeap.empty() && res.size() < 10){
            vector<int> cur = tweetHeap.top();
            tweetHeap.pop();
            res.push_back(cur[1]);

            int index = cur[3];
            if(index > 0){
                const pair<int,int>& newTweet = tweetMap[cur[2]][index - 1];
                tweetHeap.push({newTweet.first, newTweet.second, cur[2], index - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
