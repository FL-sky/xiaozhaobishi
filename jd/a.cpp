#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
char s[N];

int main()
{

    scanf("%s", s);
    int l = strlen(s);

    int ans = 0, tp = 0;
    for (int i = 1; i < l; i++)
    {
        if (s[i] == s[i - 1])
        {
            ++tp;
        }
        else
        {
            //
            ans += (tp + 1) / 3;
            tp = 1;
        }
    }
    ans += (tp + 1) / 3;
    cout << ans << endl;

    return 0;
}