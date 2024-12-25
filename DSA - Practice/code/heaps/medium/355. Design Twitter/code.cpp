/*


- https://leetcode.com/problems/design-twitter/
- https://neetcode.io/solutions/design-twitter

userId      {tweetId, time} // or reverse it to {time, tweetId}
  1     ->  [{1, 0}, {2, 1}, {3, 2}]
unordered_map<userId, vector<tweetId>>

userId      followees
  1     ->  {2,3}

unordered_map<userId, unordered_set<followeeId>>
but I should be able to insert AND delete from the followees easily, so I will use an unordered_set 
    - insert, search and remove in O(1) in unordered set


POST TWEET:
mp[userId].push_back({time, tweetId}) => O(1)

GET TWEETS:
for the user and their followees: O(no.Of Followers+1)
    - for loop 10 tweets from the back: O(10) - constant
        - add the last 10 tweets of the user in the heap - O(logn)

At the end, return all the tweets inside the heap

maxheap based on the time property.

We need to maintain a variable called time in the class. Whenever a tweet is created, we need to update the time.


- postTweet
    - some data structure to map userId and tweetId
- getTweet
    - get the user & followee's tweets
        - need a mapping between userId and their followee
    - some way i should get the user and list of followee
        - for every relevant users: find the list of tweets each have made and print in order of how recent it was

- follow
    - insert in the map: O(1)


- unfollow
    - remove from the set inside the map: O(1)

*/
class Twitter {

    unordered_map <int, vector<pair<int, int>>> tweets; // users <-> {time, tweetId}
    unordered_map <int, unordered_set<int>> users;  // users <-> followees

    int time;

public:
    Twitter() {
        
        tweets.clear();
        users.clear();
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        
        unordered_set<int> relUsers = users[userId];
        relUsers.insert(userId);

        priority_queue <pair<int, int>> feedpq;

        // Collect tweets from all relevant users
        for (int currUsrId : relUsers) {
            for (auto& tweet : tweets[currUsrId]) {
                feedpq.push(tweet); // Push tweet into the max-heap
            }
        }

        // Extract the top 10 tweets (most recent first)
        vector<int> feed;
        for (int i = 0; i < 10 && !feedpq.empty(); i++) {
            feed.push_back(feedpq.top().second); // Get the tweetId
            feedpq.pop();
        }

        return feed; // Already in most recent to least recent order
    }
    
    void follow(int followerId, int followeeId) {
        
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        users[followerId].erase(followeeId);
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