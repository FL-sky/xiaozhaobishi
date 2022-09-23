#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// const int N = 2e5 + 5;
// int a[N], la, sa[N];
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型
     */
    multiset<int> mst;
    int mx;
    void dfs(TreeNode *u, int dep, int sa)
    {
        if (u == NULL)
            return;
        int ns = sa + u->val;
        if (mst.size())
        {
            int y = ns - *mst.begin();
            mx = max(mx, y);
        }
        mx = max(mx, u->val);
        mx = max(mx, ns);
        mst.insert(ns);
        dfs(u->left, dep + 1, ns);
        dfs(u->right, dep + 1, ns);
        auto it = mst.find(ns);
        mst.erase(it);
    }
    int maxSum(TreeNode *root)
    {
        mx = root->val;
        dfs(root, 0, 0);
        return mx;
    }
};

int main()
{
    return 0;
}