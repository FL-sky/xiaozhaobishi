#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int hf = 0, dz = 0;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        if (x == 1)
            ++hf;
        else if (x == 2)
            ++dz;
        else if (x == 3)
        {
            if (hf > dz)
                ++hf;
            else if (hf < dz)
                dz++;
            else
            {
                ++hf;
                ++dz;
            }
        }
    }
    printf("%d %d\n", hf, dz);
    return 0;
}