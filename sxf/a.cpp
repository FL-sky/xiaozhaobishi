#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input
    list<int> lt;
    int ai;
    int mx = INT32_MIN;
    while (scanf("%d", &ai) != EOF)
    {
        mx = max(mx, ai);
        lt.push_back(ai);
    }
    int k = *lt.rbegin();
    lt.pop_back();
    //
    // solve
    int cnt = 0;
    while (cnt < k)
    {
        auto ij = (++lt.begin());
        if (*lt.begin() == mx) //保证O(n)
        {
            cout << mx << endl;
            return 0;
        }
        if (*lt.begin() >= *ij)
        {
            lt.push_back(*ij);
            lt.erase(ij);
            ++cnt;
        }
        else
        {
            lt.push_back(*lt.begin());
            lt.erase(lt.begin());
            cnt = 1;
        }
    }
    cout << *lt.begin() << endl;
    return 0;
}