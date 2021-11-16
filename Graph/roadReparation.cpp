#include <bits/stdc++.h>

//for policy based ds
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace __gnu_pbds; //for policy based ds
using namespace std;

#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define maxHeap priority_queue<int>;
#define minHeap priority_queue<int, vi, greater<int>>
#define mod 1000000007
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define rep(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define srt(v) sort(v.begin(), v.end())
#define all(v) begin(v), end(v)

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
    cout << "\nExecution Time: " << fixed << setprecision(5) << time_taken << "s\n";
#endif
}

int dX[] = {1, 0, -1, 0};
int dY[] = {0, 1, 0, -1};

class disjointSet
{
    vector<int> arr;
    int n;

public:
    disjointSet(int n1)
    {
        n = n1;
        arr = vector<int>(n, -1);
    }

    int find(int a)
    {
        if (arr[a] < 0)
            return a;

        return arr[a] = find(arr[a]);
    }

    bool inSameSet(int a, int b)
    {
        int s1 = find(a), s2 = find(b);
        if (s1 == s2)
            return true;

        return false;
    }

    void uninon(int a, int b)
    {
        int s1 = find(a), s2 = find(b);
        if (arr[s1] > arr[s2]) //size of set s1 is small
        {
            arr[s2] += arr[s1];
            arr[s1] = s2;
        }
        else
        {
            arr[s1] += arr[s2];
            arr[s2] = s1;
        }
    }

    void printSet()
    {
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
};

int kruskal(vector<vector<int>> &edgeList, int v, int e)
{
    sort(all(edgeList));
    disjointSet d(v);
    int edges = 0;
    int res = 0;
    for (int i = 0; i < e && edges < v - 1; i++)
    {
        int u = edgeList[i][1], v = edgeList[i][2], wt = edgeList[i][0];
        if (d.inSameSet(u, v))
            continue;
        d.uninon(u, v);
        res += wt;
        edges++;
    }

    if (edges != v - 1)
        return -1;

    return res;
}

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edgeList;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        edgeList.push_back({wt, u, v});
    }
    int minWeight = kruskal(edgeList, n, m);
    if (minWeight == -1)
        cout << "IMPOSSIBLE";
    else
        cout << minWeight;

    //---------------------------
    timeTaken();
    return 0;
}