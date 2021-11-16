#include <bits/stdc++.h>

#define int long long

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

//Point Query and Range Update
class segmentTree
{
    vector<int> arr;
    vector<int> tree;

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

    void propagate(int node, int left, int right)
    {
        if (left == right)
            return;

        tree[leftChild(node)] += tree[node];
        tree[rightChild(node)] += tree[node];
        tree[node] = 0;
    }

public:
    segmentTree(vector<int> &a)
    {
        arr = a;
        tree = vector<int>(arr.size() * 4);
        build(0, 0, arr.size() - 1);
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
        tree[node] = 0;
    }

    void update(int node, int low, int high, int left, int right, int val)
    {

        if (right < low || left > high)
            return;

        if (low == high)
        {
            tree[node] += val;
            return;
        }

        if (low >= left && high <= right)
        {
            tree[node] += val;
            return;
        }

        int mid = getMid(low, high);
        update(leftChild(node), low, mid, left, right, val);
        update(rightChild(node), mid + 1, high, left, right, val);
    }

    int query(int node, int low, int high, int idx)
    {
        propagate(node, low, high);

        if (low == high)
            return tree[node];

        int mid = getMid(low, high);
        if (idx >= low && idx <= mid)
            return query(leftChild(node), low, mid, idx);

        return query(rightChild(node), mid + 1, high, idx);
    }
};

int32_t main()
{
    init();
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    segmentTree s(arr);

    for (int qq = 0; qq < q; qq++)
    {
        int a;
        cin >> a;

        if (a == 1)
        {
            int b, c, d;
            cin >> b >> c >> d;
            b--;
            c--;
            s.update(0, 0, n - 1, b, c, d);
        }
        else
        {
            int b;
            cin >> b;
            b--;
            cout << s.query(0, 0, n - 1, b) << "\n";
        }
    }

    timeTaken();

    return 0;
}