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

int dfs(vector<vector<int>> &adjList, int src, vector<bool> &visited, vector<int> &parent, vector<int> &maxCity)
{
    if (visited[src] || maxCity[src] != -1)
        return maxCity[src];
    visited[src] = true;

    for (int i : adjList[src])
    {
        int routeCity = dfs(adjList, i, visited, parent, maxCity);
        if (routeCity != -1 && routeCity + 1 > maxCity[src])
        {
            maxCity[src] = routeCity + 1;
            parent[src] = i;
        }
    }

    return maxCity[src];
}

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
    }

    vector<int> parent(n, -1), maxCity(n, -1);
    vector<bool> visited(n, false);
    maxCity[n - 1] = 1;

    dfs(adjList, 0, visited, parent, maxCity);

    if (parent[0] == -1)
        cout << "IMPOSSIBLE";
    else
    {
        cout << maxCity[0] << "\n";
        int u = 0;
        while (u != -1)
        {
            cout << u + 1 << " ";
            u = parent[u];
        }
    }

    //---------------------------
    timeTaken();
    return 0;
}