#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

#define pii pair<int, int>

using namespace std;
using namespace __gnu_pbds; //for policy based ds

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    init();
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    pbds ms;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ms.insert({arr[i], i});
    }

    for (int qq = 0; qq < q; qq++)
    {
        char c;
        int a, b;
        cin >> c;
        if (c == '!')
        {
            cin >> a >> b;
            a--;
            ms.erase(ms.find({arr[a], a}));
            arr[a] = b;
            ms.insert({arr[a], a});
        }
        else
        {
            cin >> a >> b;
            int start = ms.order_of_key({a, 0});
            int last = ms.order_of_key({b, n});
            cout << last - start << "\n";
        }
    }
    return 0;
}