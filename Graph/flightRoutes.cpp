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

vector<int> kShortestPathDijkstra(vector<vector<pii>> &adjList, int src, int dest, int n, int k)
{
    vector<vector<int>> dist(n, vector<int>(k, inf));
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, src});

    while (!pq.empty())
    {
        pii temp = pq.top();
        pq.pop();
        int u = temp.second, dis = temp.first;

        if (dis > dist[u][k - 1])
            continue;

        for (pii j : adjList[u])
        {
            int v = j.first, wt = j.second;
            if (dis + wt < dist[v][k - 1])
            {
                dist[v][k - 1] = dis + wt;
                pq.push({dist[v][k - 1], v});
                sort(all(dist[v]));
            }
        }
    }

    return dist[dest];
}

int32_t main()
{
    init();
    //--------------------
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> adjList(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        adjList[u].push_back({v, wt});
    }

    vector<int> paths = kShortestPathDijkstra(adjList, 0, n - 1, n, k);

    for (int i : paths)
        cout << i << " ";
    //---------------------------
    timeTaken();
    return 0;
}