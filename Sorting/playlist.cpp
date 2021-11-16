#include <bits/stdc++.h>

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

struct modified_hash
{

    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    int operator()(uint64_t x) const
    {
        static const uint64_t random = std::chrono::steady_clock::now()
                                           .time_since_epoch()
                                           .count();
        return splitmix64(x + random);
    }
};

int32_t main()
{
    init();
    //--------------------
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    unordered_map<int, int, modified_hash> mp;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        mp[arr[j]]++;
        while (mp[arr[j]] > 1)
        {
            mp[arr[i]]--;
            i++;
        }

        res = max(res, j - i + 1);
    }
    cout << res;
    //---------------------------
    timeTaken();
    return 0;
}