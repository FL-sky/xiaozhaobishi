#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e4 + 10;
vector<int> a;
int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << abs(a[0] - 7) << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    // 7
    int p7 = lower_bound(a.begin(), a.end(), 7) - a.begin();
    set<int> st;
    if (p7 - 1 >= 0)
        st.insert(p7 - 1);
    if (p7 < n)
    {
        st.insert(p7);
    }

    //
    ll ans = 1e18;
    for (auto it : st)
    {
        ll cnt = 0;
        int sgn = 1;
        for (int i = 0; i < a.size(); i++)
        {
            if (i == it)
            {
                cnt += abs(7 - a[i]);
            }
            else
            {
                if (abs(1 - a[i]) < abs(-1 - a[i]))
                {
                    sgn *= 1;
                    cnt += abs(1 - a[i]);
                }
                else if (abs(1 - a[i]) > abs(-1 - a[i]))
                {
                    sgn *= -1;
                    cnt += abs(-1 - a[i]);
                }
                else
                {
                    sgn = 0;
                    cnt += 1;
                }
            }
        }
        if (sgn == 1 || sgn == 0)
        {
            ans = min(ans, cnt);
        }
        else
        {
            ans = min(ans, cnt + 2);
        }
    }

    //
    st.clear();
    p7 = lower_bound(a.begin(), a.end(), -7) - a.begin();
    if (p7 - 1 >= 0)
        st.insert(p7 - 1);
    if (p7 < n)
    {
        st.insert(p7);
    }
    ///
    for (auto it : st)
    {
        ll cnt = 0;
        int sgn = -1;
        for (int i = 0; i < a.size(); i++)
        {
            if (i == it)
            {
                cnt += abs(-7 - a[i]);
            }
            else
            {
                if (abs(1 - a[i]) < abs(-1 - a[i]))
                {
                    sgn *= 1;
                    cnt += abs(1 - a[i]);
                }
                else if (abs(1 - a[i]) > abs(-1 - a[i]))
                {
                    sgn *= -1;
                    cnt += abs(-1 - a[i]);
                }
                else
                {
                    sgn = 0;
                    cnt += 1;
                }
            }
        }
        if (sgn == 1 || sgn == 0)
        {
            ans = min(ans, cnt);
        }
        else
        {
            ans = min(ans, cnt + 2);
        }
    }
    cout << ans << endl;
    return 0;
}