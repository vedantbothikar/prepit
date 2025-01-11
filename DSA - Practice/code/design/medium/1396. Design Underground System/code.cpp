/*

- https://leetcode.com/problems/design-underground-system/?envType=study-plan-v2&envId=programming-skills

Check the complexity here: https://gist.github.com/vedantbothikar/9851de133302a56ec85bdf3b5415b080

Data Structure for storing checkIn and checkOut information

what should we keep the key?
I think it should be the train station that the person checks in



// this will be populated in both checkIn and checkout methods
id -> vector<Node>

// this will be populated in checkout method
s1 -> {
    s2 -> [{t1, t2}, {t3, t4}]
    s3 -> [{t5, t6}, {t7, t8}]
}

s1 -> {
    s2 -> {avgTime, totRides}
}

Node {
    checkInName
    checkOutName
    startTime
    endTime
}

everytime, last element in the vector will have the station where id person checkedIn


CheckIn
- I want to enter the checkInstation, id, t1
O(1)

Checkout
- I want to enter checkoutStation, id, t2
O(1)

Average:
- You will have to traverse through all ids - Inefficient


*/

class Node {

public: 
    int id;
    int startTime;
    int endTime;
    string startPoint;
    string endPoint;

    Node() {

    }
};

class UndergroundSystem {

    // id -> vector<Node>
    unordered_map<int, vector<Node*>> travelInfo;    
    
    // s1 -> {s2 -> {totalTimeOfAllRides, NoOfRides} }
    unordered_map<string, unordered_map<string, pair<long long, int>>> avgTravelTime;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        
        // populate travelInfo
        Node* travelNode = new Node();
        travelNode->id = id;
        travelNode->startPoint = stationName;
        travelNode->startTime = t;

        travelInfo[id].push_back(travelNode);
    }
    
    void checkOut(int id, string stationName, int t) {
        

        // populate travelInfo
        int n = travelInfo[id].size();
        Node* travelNode = travelInfo[id][n-1];

        travelNode->endTime = t;
        travelNode->endPoint = stationName;

        string startPoint = travelNode->startPoint;
        string endPoint = stationName;
        int startTime = travelNode->startTime;
        int endTime = t;

        // update the values in avgTravelTime
        long long totalTimeOfAllRides = avgTravelTime[startPoint][endPoint].first;
        int NoOfRides = avgTravelTime[startPoint][endPoint].second;
        
        totalTimeOfAllRides += (endTime - startTime);
        NoOfRides++;

        avgTravelTime[startPoint][endPoint].first = totalTimeOfAllRides;
        avgTravelTime[startPoint][endPoint].second = NoOfRides;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        long long totalTimeOfAllRides = avgTravelTime[startStation][endStation].first;
        int NoOfRides = avgTravelTime[startStation][endStation].second;

        return (double) totalTimeOfAllRides / (double) NoOfRides;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */