#include <list>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 4000 + 10;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<int, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        mp.clear();
        for (int k = i + 2; k < n; k++)
        {
            mp[a[k - 1]]++;
            int x = a[i] + a[k];
            if (x % 3 == 0)
            {
                int y = x / 3;
                if (mp.find(y) != mp.end())
                    ans += mp[y];
            }
        }
    }
    cout << ans << endl;
    return 0;
}