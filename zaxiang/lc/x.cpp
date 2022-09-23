#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int a[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0, ti = 0;
    for (int i = 0; i < n; i++)
    {
        if (ti + m > a[i])
        {
            ans++;
        }
        else
        {
            ti += m;
        }
    }
    cout << ans << endl;
    return 0;
}