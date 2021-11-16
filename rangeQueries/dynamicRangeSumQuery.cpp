#include <bits/stdc++.h>
#define int long long

using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class segmentTree
{
    vector<int> arr;
    vector<long long> tree;

public:
    segmentTree(vector<int> &a)
    {
        arr = a;
        tree = vector<long long>(arr.size() * 4, 0);
        build(0, 0, arr.size() - 1);
    }

    void build(int node, int low, int high)
    {
        if (low == high)
        {
            tree[node] = arr[low];
            return;
        }

        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        int mid = low + (high - low) / 2;

        build(leftChild, low, mid);
        build(rightChild, mid + 1, high);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    void update(int node, int low, int high, int idx, int val)
    {
        if (idx < low || idx > high)
            return;

        if (low == high)
        {
            arr[low] = val;
            tree[node] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (idx >= low && idx <= mid)
            update(node * 2 + 1, low, mid, idx, val);
        else
            update(node * 2 + 2, mid + 1, high, idx, val);

        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

    long long query(int node, int low, int high, int left, int right)
    {
        if (right < low || left > high)
            return 0;
        if (left <= low && right >= high)
            return tree[node];

        int mid = low + (high - low) / 2;

        long long leftAns = query(node * 2 + 1, low, mid, left, right);
        long long rightAns = query(node * 2 + 2, mid + 1, high, left, right);
        return leftAns + rightAns;
    }
};

int32_t main()
{
    init();
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    segmentTree s(arr);

    for (int qq = 0; qq < q; qq++)
    {
        int a, l, r;
        cin >> a >> l >> r;
        if (a == 1)
        {
            l--;
            s.update(0, 0, arr.size() - 1, l, r);
        }
        else
        {
            l--;
            r--;
            cout << s.query(0, 0, n - 1, l, r) << "\n";
        }
    }
    return 0;
}