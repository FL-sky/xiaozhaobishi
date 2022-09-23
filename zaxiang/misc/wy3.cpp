#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int N = 1e5 + 5;
ll val[N];
struct po
{
    int x, y, z;
    bool operator<(const po &b) const
    {
        return z < b.z;
    }
};
vector<po> v;
int fa[N];
int getpa(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = getpa(fa[x]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    int sum = 0;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        ll z = val[x] * val[y];
        int cnt = 0;
        while (z)
        {
            cnt += (z % 10 == 0);
            z /= 10;
        }
        v.push_back({x, y, cnt});
        sum += cnt;
    }
    //
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++)
        fa[i] = i;
    int couter = n - 1;
    int mi = 0;
    for (int i = 0; i < v.size() && couter > 0; i++)
    {
        int x = v[i].x, y = v[i].y, z = v[i].z;
        int fx = getpa(x), fy = getpa(y);
        if (fx != fy)
        {
            fa[fx] = fy;
            mi += z;
            couter--;
        }
    }
    cout << sum - mi << endl;
    return 0;
}