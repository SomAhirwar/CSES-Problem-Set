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

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v, wt = 0;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        indegree[v]++;
    }

    vector<bool> visited(n, false);
    queue<int> q;
    vector<int> schedule;
    int leftVertex = n;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            visited[i] = true;
            q.push(i);
            leftVertex--;
        }
    }

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        schedule.push_back(temp);
        for (int i : adjList[temp])
        {
            if (indegree[i] > 0)
            {
                indegree[i]--;
                if (indegree[i] == 0 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                    leftVertex--;
                }
            }
        }
    }

    if (leftVertex)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i : schedule)
            cout << i + 1 << " ";
    }

    //---------------------------
    timeTaken();
    return 0;
}