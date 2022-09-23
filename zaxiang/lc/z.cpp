#include <list>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int ans[N], a[N];
struct po
{
    int p, v;
    po(int p = 0, int v = 0) : p(p), v(v) {}
};
list<int> lt;
void cg(list<int>::iterator &i)
{
    if (i == lt.end())
    {
        i = ++lt.begin();
    }
}
int main()
{
    int n;
    cin >> n;
    lt.push_back(-1);
    for (int i = 0, t; i < n; i++)
    {
        cin >> t;
        a[i] = t;
        lt.push_back(i);
    }
    auto it = lt.begin(), ij = ++it;
    for (int i = 0; i < n; i++)
    {
        it = ij;
        cg(it);
        ++it;
        cg(it);
        ++it;
        cg(it);
        ans[*it] = a[i];
        ij = it;
        ++ij;
        lt.erase(it);
    }
    cout << ans[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << ans[i];
    }
    return 0;
}