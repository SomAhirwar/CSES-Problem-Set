#include <bits/stdc++.h>

using namespace std;

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
    vector<long long> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    for (int qq = 0; qq < q; qq++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << prefix[r + 1] - prefix[l] << endl;
    }
    return 0;
}