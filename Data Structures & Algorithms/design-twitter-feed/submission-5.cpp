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
        vector<int> feed;
        priority_queue<pair<int,int>> tweetHeap;

        followMap[userId].insert(userId);
        for(int followee : followMap[userId]){
            for(const auto& tweet : tweetMap[followee]){
                tweetHeap.push(tweet);
            }
        }

        while(!tweetHeap.empty() && feed.size() < 10){
            int tweetId = tweetHeap.top().second;
            tweetHeap.pop();
            feed.push_back(tweetId);
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
