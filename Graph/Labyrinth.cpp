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

bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    int Ax, Ay, Bx, By;
    vector<string> Map(n);
    vector<vector<pii>> parants(n, vector<pii>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            Map[i].push_back(c);
            if (c == 'A')
            {
                Ax = i;
                Ay = j;
            }
            if (c == 'B')
            {
                Bx = i;
                By = j;
            }
        }
    }

    queue<pii> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool pathExists = false;
    q.push({Ax, Ay});
    visited[Ax][Ay] = true;

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;

        for (int i = 0; i < 4; i++)
        {
            if (isValid(x + dX[i], y + dY[i], n, m) && (Map[x + dX[i]][y + dY[i]] == '.' || Map[x + dX[i]][y + dY[i]] == 'B') && !visited[x + dX[i]][y + dY[i]])
            {
                parants[x + dX[i]][y + dY[i]] = {x, y};
                if (Map[x + dX[i]][y + dY[i]] == 'B')
                {
                    pathExists = true;
                    break;
                }
                visited[x + dX[i]][y + dY[i]] = true;
                q.push({x + dX[i], y + dY[i]});
            }
        }
        if (pathExists)
            break;
    }

    if (!pathExists)
        cout << "NO";
    else
    {
        string path = "";
        int x = Bx, y = By;

        while (!(x == Ax && y == Ay))
        {
            char dir;
            int parentX = parants[x][y].first;
            int parentY = parants[x][y].second;
            if (parentX + 1 == x && parentY == y)
                dir = 'D';
            else if (parentX - 1 == x && parentY == y)
                dir = 'U';
            else if (parentX == x && parentY + 1 == y)
                dir = 'R';
            else
                dir = 'L';
            path.push_back(dir);

            x = parentX;
            y = parentY;
        }

        reverse(all(path));
        cout << "YES\n";
        cout << path.size() << "\n";
        cout << path;
    }
    //---------------------------
    timeTaken();
    return 0;
}