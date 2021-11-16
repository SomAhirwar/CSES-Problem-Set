#include <bits/stdc++.h>

#define pii pair<int, int>

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
            tree[node] = 1;
            return;
        }

        int mid = getMid(low, high);
        build(leftChild(node), low, mid);
        build(rightChild(node), mid + 1, high);

        tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
    }

public:
    segmentTree(vector<int> &a)
    {
        arr = a;
        tree = vector<int>(a.size() * 4);
        build(0, 0, arr.size() - 1);
    }
    void update(int node, int low, int high, int idx)
    {
        if (low == high)
        {
            tree[node] = 0;
            return;
        }

        int mid = getMid(low, high);

        if (tree[leftChild(node)] >= idx)
            update(leftChild(node), low, mid, idx);
        else
            update(rightChild(node), mid + 1, high, idx - tree[leftChild(node)]);

        tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
    }

    int query(int node, int low, int high, int idx)
    {
        // cout << node << " " << low << "-" << high << " " << idx << endl;
        if (low == high)
        {
            return arr[low];
        }

        int mid = getMid(low, high);

        if (tree[leftChild(node)] >= idx)
            return query(leftChild(node), low, mid, idx);
        return query(rightChild(node), mid + 1, high, idx - tree[leftChild(node)]);
    }

    void print()
    {
        for (int i : tree)
            cout << i << " ";
        cout << "\n";
    }
};

int main()
{
    init();
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int &i : arr)
        cin >> i;

    segmentTree s(arr);

    for (int i = 0; i < n; i++)
    {
        // s.print();
        int a;
        cin >> a;
        // cout << a << " ";
        cout << s.query(0, 0, n - 1, a) << " ";
        s.update(0, 0, n - 1, a);
    }
    timeTaken();
}