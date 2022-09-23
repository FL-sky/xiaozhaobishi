#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param a int整型vector
     * @param k int整型
     * @param x int整型
     * @return int整型
     */
    int minMax(vector<int> &a, int k, int x)
    {
        // write code here
        priority_queue<int> pq;
        for (int i = 0; i < a.size(); i++)
        {
            pq.push(a[i]);
        }
        for (int i = 0; i < k; i++)
        {
            int tp = pq.top();
            pq.pop();
            pq.push(tp - x);
        }
        return pq.top();
    }
};

int main()
{
    Solution sl;
    vector<int> v = {7, 2, 1};
    int k = 3, x = 2;
    cout << sl.minMax(v, k, x) << endl;
    return 0;
}