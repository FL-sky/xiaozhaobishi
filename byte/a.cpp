#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 4;
const double eps = 1e-6;
int a[N];
int b[N];
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = 0;
            if (a[i])
            {
                b[i] = log2(a[i] + eps);
            }
        }
        int rx, ry;
        rx = ry = 1;
        int mx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i])
            {
                int j = i;
                int sum = 0;
                while (j <= n && a[j])
                {
                    sum += b[j];
                    ++j;
                }
                if (sum > mx)
                {
                    mx = sum;
                    rx = i;
                    ry = j;
                }
                i = j;
            }
        }
        while (ry > 0 && a[ry] == 1)
        {
            ry--;
        }
        ry = max(rx, ry);
        cout << rx << " " << ry << endl;
    }
    return 0;
}