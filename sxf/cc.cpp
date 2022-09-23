#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

struct po
{
    ll mi, mx;
    bool operator<(const po &b) const
    {
        return mx < b.mx;
    }
} a[N];
struct bianjie
{
    ll l, ty;
    bool operator<(const bianjie &b) const
    {
        if (l == b.l)
        {
            return ty < b.ty;
        }
        return l < b.l;
    }
} bj[N];
int main()
{
    int n, x;
    ll ai;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> ai;
        a[i].mi = ai - x;
        a[i].mx = ai + x;
    }
    ll mi = a[0].mi, mx = a[0].mx;
    int left = 0;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int ni = max(a[i].mi, mi);
        int nx = min(a[i].mx, mx);
        if (ni <= nx)
        {
            mi = ni;
            mx = nx;
        }
        else
        {
            ++ans;
            mi = a[i].mi;
            mx = a[i].mx;
        }
    }
    cout << ans << endl;
    return 0;
}