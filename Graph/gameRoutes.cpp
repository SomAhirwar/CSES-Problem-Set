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

void dijkstra(vector<vector<pii>> &adjList, int src, int n)
{
    vector<int> price(n, inf), ways(n), minFlights(n), maxFlights(n);
    price[src] = 0;
    ways[src] = 1;
    minFlights[src] = 0;
    maxFlights[src] = 0;
    vector<bool> visited(n, false);
    int leftVertex = n;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({price[src], src});

    while (!pq.empty())
    {
        pii temp = pq.top();
        pq.pop();
        int u = temp.second;
        int d = temp.first;
        if (visited[u])
            continue;

        visited[u] = true;
        leftVertex--;
        if (!leftVertex)
            break;

        for (pii i : adjList[u])
        {
            int v = i.first, wt = i.second;
            if (d + wt == price[v])
            {
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
                ways[v] += ways[u];
                ways[v] %= mod;
            }
            else if (d + wt < price[v])
            {
                price[v] = d + wt;
                pq.push({price[v], v});
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                ways[v] = ways[u];
            }
        }
    }

    cout << price[n - 1] << " " << ways[n - 1] << " " << minFlights[n - 1] << " " << maxFlights[n - 1];
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
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        adjList[u].push_back({v, wt});
    }

    dijkstra(adjList, 0, n);
    //---------------------------
    timeTaken();
    return 0;
}