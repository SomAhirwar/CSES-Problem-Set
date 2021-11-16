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

bool dfs(vector<vector<pii>> &adjList, int src, vector<bool> &visited, vector<bool> &visitedPath, vector<int> &path, vector<int> &cycle)
{
    // cout << src << endl;
    if (visitedPath[src])
    {
        bool found = false;
        for (int i : path)
        {
            // cout << i << " ";
            if (i == src)
                found = true;
            if (found)
                cycle.push_back(i);
        }
        cycle.push_back(src);
        return true;
    }

    if (visited[src])
        return false;

    visited[src] = true;
    visitedPath[src] = true;
    path.push_back(src);

    for (pii i : adjList[src])
    {
        if (dfs(adjList, i.first, visited, visitedPath, path, cycle))
            return true;
    }

    path.pop_back();
    visitedPath[src] = false;
    return false;
}

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adjList(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, wt = 0;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back({v, wt});
    }

    vector<bool> visited(n, false), visitedPath(n, false);
    vector<int> path, cycle;

    bool foundCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            foundCycle = dfs(adjList, i, visited, visitedPath, path, cycle);
        }
        if (foundCycle)
            break;
    }

    if (foundCycle)
    {
        cout << cycle.size() << "\n";
        for (int i : cycle)
            cout << i + 1 << " ";
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    //---------------------------
    timeTaken();
    return 0;
}