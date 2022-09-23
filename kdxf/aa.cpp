#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1.6e4 + 10;
ll x[maxn], r[maxn];
struct po
{
    ll val;
    po(ll v = 0) : val(v) {}
    bool operator<(const po &b) const
    {
        if (abs(val) == abs(b.val))
        {
            return val < b.val;
        }
        return abs(val) < abs(b.val);
    }
    bool operator==(const po &b) const
    {

        return val == b.val;
    }
};
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    multiset<po> mst;
    for (int k = 0; k < N; k++)
    {
        ll tp = 0;
        for (int n = 0; n <= N - k - 1; n++)
        {
            tp += x[n] * x[n + k];
        }
        for (int n = N - k; n <= N - 1; n++)
        {
            tp += x[n] * x[n + k - N];
        }
        r[k] = tp;
        mst.insert(po(tp));
    }
    for (int i = 0; i < N; i++)
    {
        if (i)
            cout << " ";
        cout << r[i];
    }
    cout << endl;
    ll *a = r;
    ll mx = 0, pos = -1;

    for (int i = 1; i < N; i++)
    {
        if (a[i] >= a[i - 1] && a[i] >= a[(i + 1) % N])
        {
            if (a[i] != r[0])
            {
                if (abs(a[i]) > mx)
                {
                    mx = abs(a[i]);
                    pos = i;
                }
            }
        }
        if (a[i] <= a[i - 1] && a[i] <= a[(i + 1) % N])
        {
            if (a[i] != r[0])
            {
                if (abs(a[i]) > mx)
                {
                    mx = abs(a[i]);
                    pos = i;
                }
            }
        }
    }
    if (pos >= 0)
    {
        cout << r[pos];
        if (mst.find(-r[pos]) != mst.end())
        {
            cout << " " << -r[pos];
        }
        cout << endl;
    }
    else
        puts("NO");
    return 0;
}