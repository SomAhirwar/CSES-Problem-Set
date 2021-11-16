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
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    vector<int> bid(m);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        tickets.insert(temp);
    }

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        if (tickets.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            auto itr = tickets.upper_bound(temp);
            if (itr == tickets.begin())
                cout << -1 << " ";
            else
            {
                auto preItr = prev(itr, 1);
                cout << *preItr << " ";
                tickets.erase(preItr);
            }
        }
    }

    //---------------------------
    timeTaken();
    return 0;
}
