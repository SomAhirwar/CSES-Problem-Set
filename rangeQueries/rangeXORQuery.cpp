#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    init();
    int n, q;
    cin >> n >> q;

    vector<int> prefix(n);
    cin >> prefix[0];
    for (int i = 1; i < n; i++)
    {
        cin >> prefix[i];
        prefix[i] = prefix[i - 1] ^ prefix[i];
    }

    for (int qq = 0; qq < q; qq++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a == 0)
            cout << prefix[b] << "\n";
        else
        {
            int res = prefix[b] ^ prefix[a - 1];
            cout << res << "\n";
        }
    }

    timeTaken();

    return 0;
}