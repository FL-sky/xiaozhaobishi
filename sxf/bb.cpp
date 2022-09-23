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
    set<int> mst;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        mst.clear();
        mst.insert(a[i]);
        for (int j = i + 1; j < n; j++)
        {
            mst.insert(a[j]);
            if (mst.size() != j - i + 1)
                break;
            int mi = *mst.begin();
            int mx = *mst.rbegin();
            if (j - i == mx - mi)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}