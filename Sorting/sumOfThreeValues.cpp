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
    int n, x, a, b, c;
    cin >> n >> x;
    vector<pii> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(all(arr));

    bool foundSol = false;
    for (int i = 2; i < n; i++)
    {
        int k = i - 1, j = 0;
        while (j < k)
        {
            if (arr[j].first + arr[k].first == x - arr[i].first)
            {
                foundSol = true;
                a = arr[j].second;
                b = arr[k].second;
                c = arr[i].second;
                break;
            }
            else if (arr[j].first + arr[k].first < x - arr[i].first)
                j++;
            else
                k--;
        }

        if (foundSol)
            break;
    }

    if (foundSol)
    {
        //sorting a, b, c
        if (a >= b)
        {
            if (a < c)
                swap(a, c);
        }
        else
        {
            swap(a, b);
            if (a < c)
                swap(a, c);
        }

        if (b < c)
            swap(b, c);

        cout << c + 1 << " " << b + 1 << " " << a + 1;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    //---------------------------
    timeTaken();
    return 0;
}
