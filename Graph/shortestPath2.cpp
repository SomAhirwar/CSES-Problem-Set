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

vector<vector<int>> floydWarshall(vector<vector<pii>> &adjList, int n)
{
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for (int u = 0; u < n; u++)
    {
        for (pii v : adjList[u])
        {
            dist[u][v.first] = min(dist[u][v.first], v.second);
        }
        dist[u][u] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min({dist[i][j], dist[i][k] + dist[k][j], dist[j][k] + dist[k][i]});
            }
        }
    }

    return dist;
}

int32_t main()
{
    init();
    //--------------------
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pii>> adjList(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    vector<vector<int>> dist = floydWarshall(adjList, n);

    for (int qq = 0; qq < q; qq++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (dist[u][v] == inf)
            cout << -1 << "\n";
        else
            cout << dist[u][v] << "\n";
    }
    //---------------------------
    timeTaken();
    return 0;
}