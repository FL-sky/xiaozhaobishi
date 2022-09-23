#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 10;
int a[N];
int main()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    --k;
    ll p = k % (n * 2);
    if (p >= n)
    {
        p = 2 * n - 1 - p;
    }
    cout << a[p] << endl;
    return 0;
}