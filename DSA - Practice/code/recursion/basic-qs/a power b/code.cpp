#include <bits/stdc++.h>
using namespace std;

// multiply a,   b number of time
int apowerb(int a, int b, int ans)
{

    cout << "ANS: " << ans << endl;

    if (b <= 0)
    {

        return ans;
    }

    apowerb(a, b - 1, ans * a);
}

int main()
{

    int a, b;
    cout << "enter a and b for a power b: " << endl;

    cin >> a;
    cin >> b;

    cout << "Answer: " << apowerb(a, b, 1) << endl;

    return 0;
}