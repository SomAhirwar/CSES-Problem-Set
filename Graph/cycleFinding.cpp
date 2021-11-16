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

void bellmonFord(vector<vector<pii>> &adjList, int src, int n)
{
    vector<int> dist(n, inf);
    vector<int> parent(n);
    dist[src] = 0;
    int x;

    for (int ii = 0; ii < n; ii++)
    {
        x = -1;
        for (int i = 0; i < n; i++)
        {
            for (pii j : adjList[i])
            {
                int u = i, v = j.first, wt = j.second;
                // if (dist[u] < inf)
                // {
                if (dist[u] + wt < dist[v])
                {
                    // cout << u << " ";
                    dist[v] = (-inf > dist[u] + wt) ? -inf : dist[u] + wt;
                    x = v;
                    parent[v] = u;
                }
                // }
            }
        }
        // cout << endl;
        // for (int i = 0; i < n; i++)
        //     cout << i << ":" << dist[i] << " ";
    }

    if (x == -1)
        cout << "NO";
    else
    {
        cout << "YES\n";
        int y = x;
        for (int i = 0; i < n; ++i)
            x = parent[x];

        vector<int> cycle;
        for (int v = x;; v = parent[v])
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        for (int i : cycle)
            cout << i << " ";
        cout << cycle[0];
    }
}

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adjList(n);

    for (int i = 0; i < n; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        adjList[u].push_back({v, wt});
    }

    bellmonFord(adjList, 0, n);

    //---------------------------
    timeTaken();
    return 0;
}