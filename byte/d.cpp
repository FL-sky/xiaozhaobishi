#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
const double eps = 1e-6;
int a[N];
int psum[N];
int main()
{
    int n, k;
    cin >> n >> k;
    ++k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    multiset<int> mst;
    int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        mst.insert(a[i]);
        sum += a[i];
    }
    int ans = sum - *mst.begin();
    for (int i = 2; i + k - 1 <= n; i++)
    {
        sum -= a[i - 1];
        mst.erase(mst.find(a[i - 1]));
        mst.insert(a[i + k - 1]);
        sum += a[i + k - 1];
        ans = max(ans, sum - *mst.begin());
    }
    --k;
    for (int i = 1; i + k - 1 <= n; i++)
    {
        ans = max(ans, psum[i + k - 1] - psum[i - 1]);
    }
    cout << ans << endl;
    return 0;
}