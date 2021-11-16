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

int dfs(vector<int> &dest, int src, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> &res, vector<int> &time, stack<int> &s, int t)
{
    if (dfsVisited[src])
    {
        stack<int> temp;
        int cycleRes = t - time[src];
        while (s.top() != src)
        {
            int top = s.top();
            s.pop();
            temp.push(top);
            res[top] = cycleRes;
        }
        res[src] = cycleRes;

        while (!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }

        return res[src];
    }
    if (visited[src])
        return res[src];

    visited[src] = true;
    dfsVisited[src] = true;
    time[src] = t;

    s.push(src);

    int newVal = dfs(dest, dest[src], visited, dfsVisited, res, time, s, t + 1);

    res[src] = min(res[src], newVal + 1);

    dfsVisited[src] = false;
    s.pop();

    return res[src];
}

int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    vector<int> destination(n);

    for (int i = 0; i < n; i++)
    {
        cin >> destination[i];
        destination[i]--;
    }

    vector<bool> visited(n, false), dfsVisited(n, false);
    vector<int> res(n, inf), time(n);
    stack<int> s;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(destination, i, visited, dfsVisited, res, time, s, 0);

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    //---------------------------
    timeTaken();
    return 0;
}