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
    /*
        IDEA - Binary Lifting
    */
    init();
    //--------------------
    int n, q, logK = log2(1e9) + 1;
    cin >> n >> q;
    vector<vector<int>> afterK(logK, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> afterK[0][i];
        afterK[0][i]--;
    }

    for (int i = 1; i < logK; i++)
        for (int j = 0; j < n; j++)
            afterK[i][j] = afterK[i - 1][afterK[i - 1][j]];

    for (int qq = 0; qq < q; qq++)
    {
        int x, k;
        cin >> x >> k;
        x--;
        while (k)
        {

            int v = ((int)(log2(k))); //lastsetBit
            x = afterK[v][x];
            k = (1 << v) ^ k;
        }

        cout << x + 1 << "\n";
    }

    //---------------------------
    timeTaken();
    return 0;
}