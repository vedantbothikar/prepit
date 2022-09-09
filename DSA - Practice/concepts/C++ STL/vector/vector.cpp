#include <bits/stdc++.h>
using namespace std;

/*

These are DYNAMIC ARRAYS

Vectors are 
- single-dimensional
- homogeneous 
data structures.

How they work: 
They create another vector of double size 
when the elements increase beyond a certain point

*/

//  IMPORTANT
// if you don't put `&` before v here
// then it will a new vector for this function
// which means that the capacity and size printed will be wrong
// DO: remove the & sign and check the size and capacity after pushing
// NOW: add the & sign and again check the size and capacity after pushing
void printSizeCapacity(vector<int> &v)
{
    cout << "CAPACITY: " << v.capacity() << endl;
    cout << "SIZE: " << v.size() << endl;
}

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;

    // Vector

    cout << "----------------VECTORS--------------" << endl;

    cout << "-----------INITIALIZATION--------------" << endl;

    vector<int> v;

    // this initializes the vector with size `5` & all values as `1`
    // by default it initializes with `0`
    vector<int> myvec(5, 1);
    printVector(myvec);

    // this copies the elements of myvec into newvec
    vector<int> newvec(myvec);
    printVector(newvec);

    cout << "-----------SIZE & CAPACITY--------------" << endl;

    // size: how many elements are present
    // capacity: how much memory is allocated

    // initially the vector's capacity & size both will be 0
    cout << "---INTIALLY" << endl;
    printSizeCapacity(v);

    cout << "---AFTER PUSHING" << endl;
    v.push_back(1);
    printSizeCapacity(v);

    cout << "---AFTER PUSHING" << endl;
    v.push_back(2);
    printSizeCapacity(v);

    cout << "---AFTER PUSHING" << endl;
    v.push_back(3);
    printSizeCapacity(v);

    cout << "---AFTER PUSHING" << endl;
    v.push_back(4);
    printSizeCapacity(v);

    cout << "---AFTER PUSHING" << endl;
    v.push_back(5);
    printSizeCapacity(v);

    cout << "-----------AT Operation, FRONT, BACK--------------" << endl;

    // at operation
    cout << "Element at 2nd index: " << v.at(2) << endl;

    // FRONT BACK
    cout << "FRONT: " << v.front() << endl;
    cout << "BACK: " << v.back() << endl;

    cout << "-----------POP--------------" << endl;

    // pop_back

    cout << "BEFORE POPPING" << endl;
    printVector(v);

    // NOTE: it doesn't return anything
    v.pop_back();

    cout << "AFTER POPPING" << endl;
    printVector(v);

    cout << "-----------CLEAR--------------" << endl;

    cout << "In clear, the size becomes 0 but the capacity stays the same" << endl;

    cout << "BEFORE CLEARING" << endl;
    printSizeCapacity(v);
    v.clear();
    cout << "AFTER CLEARING" << endl;
    printSizeCapacity(v);

    cout << "-------------------------" << endl;

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    cout << "Size: " << v1.size() << endl;
    cout << "Capacity: " << v1.capacity() << endl;

    vector<int> v2 = v1;
    cout << "Size: " << v2.size() << endl;
    cout << "Capacity: " << v2.capacity() << endl;

    return 0;
}