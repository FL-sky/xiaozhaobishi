#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 3;
int a[N];
int dp[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 1, tmp = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1] + 1)
        {
            ++tmp;
        }
        else
        {
            ans = max(ans, tmp);
            tmp = 1;
        }
    }
    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}