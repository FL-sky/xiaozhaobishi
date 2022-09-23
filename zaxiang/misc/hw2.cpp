#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main()
{
    int n, m;
    cin >> n >> m;
    v.resize(m + 2);
    v[0] = v[m + 1] = 0;
    int mxh = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%*c%d", &v[i]);
        v[i] = -v[i];
        v[i] = max(0, v[i]);
        mxh = max(mxh, v[i]);
    }
    int ans = 0;
    for (int h = 1; h <= mxh; h++)
    {
        int i = 1, l, r;
        while (i <= m)
        {
            while (i <= m && v[i] < h)
                ++i;
            l = r = i;
            while (i <= m && v[i] >= h)
                ++i;
            r = i;
            int len = r - l;
            if (len >= n)
            {
                ans += len / n;
            }
        }
    }
    cout << ans << endl;

    return 0;
}