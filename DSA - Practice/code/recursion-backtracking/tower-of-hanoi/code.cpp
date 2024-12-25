#include <bits/stdc++.h>
using namespace std;

long long toh(int N, int from, int to, int aux, long long &count)
{

    // base case
    if (N == 0)
    {
        return 0;
    }

    toh(N - 1, from, aux, to, count);
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    count++;
    toh(N - 1, aux, to, from, count);

    return count;
}

int main()
{

    return 0;
}