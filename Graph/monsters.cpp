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

bool isBorder(int x, int y, int n, int m)
{
    return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}

int32_t main()
{
    init();
    //--------------------
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    queue<pair<pii, char>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pii>> parent(n, vector<pii>(m));
    int aX, aY;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            grid[i].push_back(c);
            if (c == 'M')
            {
                parent[i][j] = {-1, -1};
                visited[i][j] = true;
                q.push({{i, j}, c});
            }
            else if (c == 'A')
            {
                aX = i;
                aY = j;
            }
        }
    }

    if (isBorder(aX, aY, n, m)) //Edge Case
    {
        cout << "YES\n";
        cout << 0;
        return 0;
    }

    parent[aX][aY] = {-1, -1};
    visited[aX][aY] = true;
    q.push({{aX, aY}, 'A'});
    bool resFound = false;
    pii res;

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        int x = temp.first.first;
        int y = temp.first.second;
        char c = temp.second;

        for (int i = 0; i < 4; i++)
        {
            int X = x + dX[i], Y = y + dY[i];
            if (isValid(X, Y, n, m) && !visited[X][Y] && grid[X][Y] == '.')
            {
                visited[X][Y] = true;
                parent[X][Y] = {x, y};

                if (c == 'A' && isBorder(X, Y, n, m))
                {
                    res = {X, Y};
                    resFound = true;
                    break;
                }
 
                q.push({{X, Y}, c});
            }
        }

        if (resFound)
            break;
    }

    if (resFound)
    {
        vector<char> path;
        int x = res.first;
        int y = res.second;
        while (grid[x][y] != 'A')
        {
            int parentX = parent[x][y].first;
            int parentY = parent[x][y].second;
            char dir;

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
        for (char c : path)
            cout << c;
    }
    else
        cout << "NO";
    //---------------------------
    timeTaken();
    return 0;
}