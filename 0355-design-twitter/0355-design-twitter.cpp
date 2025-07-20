class Twitter {
private:
    int timestamp = 0;
    //tweet
    unordered_map<int , vector<pair<int, int>>>tweets;
    //followers
    unordered_map<int , unordered_set<int>>followers;

public:    
    Twitter() {
        timestamp = 0; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int , int>>pq;

        //own tweet
        for(auto &tweet : tweets[userId]){
            pq.push(tweet);
        }

        //follower tweet
        for(int followeedId : followers[userId]){
            for(auto &followertweet : tweets[followeedId]){
            pq.push(followertweet);
            }
        }
       

        //top 10 tweet
        vector<int>result;
        int count = 0;
        while(!pq.empty() && count < 10){
            result.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */