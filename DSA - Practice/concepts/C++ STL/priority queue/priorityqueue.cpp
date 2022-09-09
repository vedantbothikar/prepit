#include <bits/stdc++.h>
using namespace std;

/*

The default priority queue that you make is max heap

the first element is the greatest


*/

void printMaxi(priority_queue<int> maxi)
{
    int size = maxi.size();
    for (int i = 0; i < size; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }

    cout << endl;
}

void printMini(priority_queue<int, vector<int>, greater<int>> mini)
{
    int size = mini.size();
    for (int i = 0; i < size; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }

    cout << endl;
}

int main()
{
    cout << "----------PRIORITY QUEUE----------" << endl;

    cout << endl;

    cout << "----------INITIALIZATION----------" << endl;

    // this will act as max heap
    priority_queue<int> maxi;

    // this will act as min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    cout << endl;

    cout << "----------PUSH----------" << endl;
    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(0);

    mini.push(1);
    mini.push(2);
    mini.push(3);
    mini.push(0);

    cout << "Printing maxi: " << endl;
    printMaxi(maxi);

    cout << "Printing mini: " << endl;
    printMini(mini);

    cout << endl;
    cout << "----------FIRST----------" << endl;

    cout << endl;

    cout << "----------POP----------" << endl;

    cout << endl;

    cout << "---------SIZE, EMPTY-----------" << endl;

    cout << "size: " << maxi.size() << endl;
    cout << "empty or not: " << maxi.empty() << endl;

    return 0;
}