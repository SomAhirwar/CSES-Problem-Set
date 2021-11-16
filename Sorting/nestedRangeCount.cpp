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

int32_t main()
{
    init();
    //--------------------
    int n;
    cin >> n;
    vector<vector<int>> range(n, vector<int>(3));
    vector<int> containsOther(n), otherContains(n);
    pbds pre, next;
    for (int i = 0; i < n; i++)
    {
        range[i][2] = i;
        cin >> range[i][0] >> range[i][1];
    }

    sort(all(range), [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0])
            return a[1] > b[1];

        return a[0] < b[0];
    });

    for (int i = 0; i < n; i++)
        next.insert({range[i][1], -i});

    for (int i = 0; i < n; i++)
    {
        next.erase(*next.find({range[i][1], -i}));
        containsOther[range[i][2]] = next.order_of_key({range[i][1], -i});

        otherContains[range[i][2]] = pre.size() - pre.order_of_key({range[i][1], -i});
        pre.insert({range[i][1], -i});
    }

    for (int i = 0; i < n; i++)
    {
        cout << containsOther[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << otherContains[i] << " ";
    }
    //---------------------------
    timeTaken();
    return 0;
}
