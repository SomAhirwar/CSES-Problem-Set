#include <bits/stdc++.h>

using namespace std;

class segmentTree
{
    vector<int> arr;
    vector<int> queryArr;

public:
    segmentTree(vector<int> &a)
    {
        arr = a;
        queryArr = vector<int>(a.size() * 4);
        build(0, 0, arr.size() - 1);
    }

    void build(int node, int low, int high)
    {
        if (low == high)
        {
            queryArr[node] = arr[low];
            return;
        }
        // cout << node << endl;
        int mid = low + (high - low) / 2;
        int leftChild = node * 2 + 1;
        int rightChild = node * 2 + 2;

        build(leftChild, low, mid);
        build(rightChild, mid + 1, high);
        queryArr[node] = min(queryArr[leftChild], queryArr[rightChild]);
    }

    void update(int node, int low, int high, int idx, int val)
    {
        if (low == high)
        {
            arr[idx] = val;
            queryArr[node] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (low <= idx && idx <= mid)
            update(node * 2 + 1, low, mid, idx, val);
        else
            update(node * 2 + 2, mid + 1, high, idx, val);

        queryArr[node] = min(queryArr[node * 2 + 1], queryArr[node * 2 + 2]);
    }

    int query(int node, int low, int high, int left, int right)
    {
        if (right < low || left > high)
            return INT_MAX;

        if (left <= low && high <= right)
            return queryArr[node];

        int mid = low + (high - low) / 2;

        int leftRes = query(node * 2 + 1, low, mid, left, right);
        int rightRes = query(node * 2 + 2, mid + 1, high, left, right);

        return min(leftRes, rightRes);
    }
};

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

int main()
{
    init();
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);

    for (int &i : arr)
        cin >> i;

    segmentTree s(arr);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << s.query(0, 0, arr.size() - 1, l, r) << endl;
    }
}