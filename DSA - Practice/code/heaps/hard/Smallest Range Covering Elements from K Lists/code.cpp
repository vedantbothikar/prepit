/*

On observation, the smallest range will come when you take the range of the smallest
numbers from all the lists. (This is not true but gives a lead for us to start with)
(Think upon it once) This range of smallest numbers, we can keep reducing further, because this might not be the smallest range...

So suppose we have 
[4, 10, 15, 24,26]
[0, 9, 12, 20]
[5, 18, 22, 30]

We can take the smallest elements from all the arrays
4,0,5
Now the range of this will be the max-min of this 
    => min: 0
    => max: 5
    Range: 5-0 = 5
Now, this is a possible solution. To make this range smaller, we can go to the next element in the array in which the min is present.
So here min is present in 2nd array, so we increment the index and add the new value and check what fits here
So, now the elements are 
4,9,5 (9 came as the second index in the second array)
Now, 
    => min: 5
    => max: 9
    Range: 9-5 = 4 (This is an even smaller range)
To reduce the range of this further, we do the same thing, take the smaller element and increment the index of the array in which this smallest element is present
So the min is present in 3rd array, so increment the index there and you will reach to 18
4,9,18
    => min: 4
    => max: 18
    Range: 18-4= 14
Continue this process until you reach end in any of the arrays, and then return the min of the ranges that you have calculated

____

vector<pair<int,int>> currentElements => has the smallest elements of all k arrays
size: k

find the min and max of this currentElements
Put all elements of currentElementss in the minheap => O(k*logk)

Find the maxelement of this currentElements store it in maxNum variable
Find the range, store it in a variabled called currentRange

condition is that index should be less than the current array's size
pair<int, int> minNum  => this is how we will store the minNum and maxNum
    .first: array number
    .second: element number


condition
    minNum.second < nums[minNum.first].size

int newIndex = minNum.second + 1
While(newIndex < nums[minNum.first].size())

    pair<int,int> newElement = nums[minNum.first][newIndex]

    if(nums[newElement.first][newElement.second] > nums[maxNum.first][maxNum.second]) {
        // update maxNum
        maxNum = newElement
    }

    pq.pop()
    pq.push(newElement)

    minNum = pq.top()
    // currentRange = maxNum - minNum
    currentRange = nums[maxNum.first][maxNum.second] - nums[minNum.first][minNum.second]   

    goto the next index in the array in which the min element is present,
    int newIndex = minNum.second + 1
    
_______________

Complexity Analysis
Time Complexity:
Heap Operations: Each insertion and removal operation on the priority queue takes O(log k) time, where k is the number of lists.
Total Operations: The algorithm performs N operations in total, where N is the sum of all elements in the k lists. For each of the N elements, we perform an O(log k) operation, giving us a total time complexity of:
𝑂
(
𝑁
log
⁡
𝑘
)
O(Nlogk)
Space Complexity:
Heap Size: The priority queue stores only k elements at any time, resulting in an O(k) space complexity.
Additional Space: Additional space is required to store the result range, minRangeValues, and a few helper variables, but this is constant and doesn’t affect the asymptotic complexity.
Therefore, the overall space complexity is:
𝑂
(
𝑘
)
O(k)

*/

class Node {

public: 
    int data;
    int arrayIndex;
    int elementIndex;

    Node(int data, int arrayIndex, int elementIndex) {
        this->data = data;
        this->arrayIndex = arrayIndex;
        this->elementIndex = elementIndex;
    }
};

class CustomNodeComparator {

public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k = nums.size();
        
        // push the smallest elements of nums
        priority_queue<Node*, vector<Node*>, CustomNodeComparator> pq;   // min heap
        int maxNum = INT_MIN;
        for(int i = 0; i < k; i++) {
            
            pq.push(new Node(nums[i][0], i, 0));
            maxNum = max(maxNum, nums[i][0]);
        }

        Node* minNum = pq.top();
        int finalMinRange = maxNum - minNum->data;
        vector<int> minRangeValues = {minNum->data, maxNum};

        int nextElementIndex = minNum->elementIndex + 1;
        while(nextElementIndex < nums[minNum->arrayIndex].size()) {

            // next element
            int newElementValue = nums[minNum->arrayIndex][nextElementIndex];
            int newElementArrayIndex = minNum->arrayIndex;
            Node* newElement = new Node(newElementValue, newElementArrayIndex, nextElementIndex);

            // update maxNum
            if(newElementValue > maxNum) maxNum = newElementValue;

            pq.pop();
            pq.push(newElement);

            minNum = pq.top();

            // calculate currentRange
            int currentRange = maxNum - minNum->data; 
            if(currentRange < finalMinRange) {
                finalMinRange = currentRange;
                minRangeValues = {minNum->data, maxNum};   // update minRangeValues
            }

            // update index in the array
            nextElementIndex = minNum->elementIndex + 1;   
        }

        return minRangeValues;
    }
};