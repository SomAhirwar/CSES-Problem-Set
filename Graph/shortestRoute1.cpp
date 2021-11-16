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

vector<int> dijkstra(vector<vector<pii>> &adjList, int src, int n)
{
    vector<int> dist(n, 1e15);
    dist[0] = 0;

    vector<bool> visited(n, false);
    int leftVertex = n;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pii temp = pq.top();
        pq.pop();
        if (visited[temp.second])
            continue;

        visited[temp.second] = true;
        leftVertex--;
        if (leftVertex == 0)
            break;

        for (pii i : adjList[temp.second])
        {
            if (dist[temp.second] + i.second < dist[i.first])
            {
                dist[i.first] = dist[temp.second] + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }

    return dist;
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

    vector<int> dist = dijkstra(adjList, 0, n);
    for (int i : dist)
        cout << i << " ";
    //---------------------------
    timeTaken();
    return 0;
}