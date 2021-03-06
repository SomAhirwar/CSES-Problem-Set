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
    cout << "Execution Time: " << fixed << setprecision(5) << time_taken << "s\n";
#endif
}

bool notSame(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j])
                return false;
    }

    return true;
}

int32_t main()
{
    init();
    //--------------------
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    vector<vector<int>> twoValueSum;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            twoValueSum.push_back({arr[i] + arr[j], i, j});

    sort(all(twoValueSum));

    int l = 0, h = twoValueSum.size() - 1;
    bool resFound = false;

    while (l < h && !resFound)
    {
        if (twoValueSum[l][0] + twoValueSum[h][0] == x)
            if (notSame({twoValueSum[l][1], twoValueSum[l][2], twoValueSum[h][1], twoValueSum[h][2]}))
                resFound = true;
            else if (twoValueSum[l + 1][0] == twoValueSum[l][0])
                l++;
            else
                h--;
        else if (twoValueSum[l][0] + twoValueSum[h][0] < x)
            l++;
        else
            h--;
    }

    if (resFound)
        cout << twoValueSum[l][1] + 1 << " " << twoValueSum[l][2] + 1 << " " << twoValueSum[h][1] + 1 << " " << twoValueSum[h][2] + 1;
    else
        cout << "IMPOSSIBLE";

    //---------------------------
    timeTaken();
    return 0;
}
