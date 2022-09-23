#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
bool check(map<int, int> &mp, unordered_map<int, int> &mq)
{
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (mq.find(it->first) == mq.end())
            return false;
        if (mq[it->first] < mp[it->first])
            return false;
    }
    return true;
}
int main()
{
    int m;
    cin >> m;
    while (m-- > 0)
    {
        int k, n;
        cin >> k >> n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        map<int, int> mp;
        int tp = k;
        int up = sqrt(tp + 0.5);
        for (int i = 2; i <= up; i++)
        {
            while (tp > 1 && tp % i == 0)
            {
                mp[i]++;
                tp /= i;
            }
        }
        if (tp > 1)
            mp[tp]++;
        unordered_map<int, int> mq;
        int r = -1;
        for (int i = 1; i <= n; i++)
        {
            mq[a[i]]++;
            if (check(mp, mq))
            {
                r = i;
                break;
            }
        }
        if (r < 0)
        {
            puts("0");
            continue;
        }
        int ans = r;
        int l = 1;
        while (1)
        {
            int nd = -1;
            while (l <= r)
            {
                ans = min(ans, r - l + 1);
                if (mp.find(a[l]) == mp.end())
                {
                    --mq[a[l]];
                    ++l;
                }
                else if (mp[a[l]] < mq[a[l]])
                {
                    --mq[a[l]];
                    ++l;
                }
                else
                {
                    --mq[a[l]];
                    nd = a[l];
                    ++l;
                    break;
                }
            }
            int i;
            for (i = r + 1; i <= n; i++)
            {
                mq[a[i]]++;
                if (a[i] == nd)
                {
                    ans = min(ans, i - l + 1);
                    break;
                }
            }
            if (i > n)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}