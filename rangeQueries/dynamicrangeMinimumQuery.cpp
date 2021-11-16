#include <bits/stdc++.h>

using namespace std;

time_t Begin;

void init()
{
    Begin = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void timeTaken()
{
#ifndef ONLINE_JUDGE
    double time_taken = double(clock() - Begin) / double(CLOCKS_PER_SEC);
    cout << "Execution Time: " << fixed << setprecision(5) << time_taken << "s\n";
#endif
}

class segmentTree
{
    vector<int> arr;
    vector<int> tree;

public:
    segmentTree(vector<int> &a)
    {
        arr = a;
        tree = vector<int>(a.size() * 4);
        build(0, 0, arr.size() - 1);
    }

    int leftChild(int node)
    {
        return node * 2 + 1;
    }

    int rightChild(int node)
    {
        return node * 2 + 2;
    }

    int getMid(int low, int high)
    {
        return low + (high - low) / 2;
    }

    void build(int node, int low, int high)
    {
        if (low == high)
        {
            tree[node] = arr[low];
            return;
        }

        int mid = getMid(low, high);

        build(leftChild(node), low, mid);
        build(rightChild(node), mid + 1, high);

        tree[node] = min(tree[leftChild(node)], tree[rightChild(node)]);
    }

    void update(int node, int low, int high, int idx, int val)
    {
        if (low == high)
        {
            arr[low] = val;
            tree[node] = val;
            return;
        }

        int mid = getMid(low, high);

        if (idx >= low && idx <= mid)
            update(leftChild(node), low, mid, idx, val);
        else
            update(rightChild(node), mid + 1, high, idx, val);

        tree[node] = min(tree[leftChild(node)], tree[rightChild(node)]);
    }

    int query(int node, int low, int high, int left, int right)
    {
        if (right < low || left > high)
            return INT_MAX;

        if (low == high)
            return tree[node];

        if (left <= low && high <= right)
            return tree[node];

        int mid = getMid(low, high);
        int leftRes = query(leftChild(node), low, mid, left, right);
        int rightRes = query(rightChild(node), mid + 1, high, left, right);

        return min(leftRes, rightRes);
    }
};

int main()
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
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            b--;
            s.update(0, 0, n - 1, b, c);
        }
        else
        {
            b--;
            c--;
            cout << s.query(0, 0, n - 1, b, c) << endl;
        }
    }
    timeTaken();
    return 0;
}