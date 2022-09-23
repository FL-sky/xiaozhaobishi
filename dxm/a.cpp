#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
int a[N];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    multiset<int> mst;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        mst.clear();
        for (int j = i; j < n; j++)
        {
            mst.insert(a[j]);
            int mi = *mst.begin();
            int mx = *(--mst.end());
            if (mx % mi == 0 && mx / mi == k)
            {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}