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

class medianDS
{
    multiset<int> s1, s2;

public:
    void arrangeDS()
    {
        if ((int)(s1.size()) - (int)(s2.size()) > 1)
        {
            // cout << s1.size() << " " << s2.size() << " jh";
            auto lastElement = prev(s1.end());
            s2.insert(*lastElement);
            s1.erase(lastElement);
        }
        else if (s2.size() > s1.size())
        {
            s1.insert(*(s2.begin()));
            s2.erase(s2.begin());
        }
        // cout << s1.size() << "-" << s2.size() << endl;
    }

    void insert(int data)
    {
        if (s2.empty() && s1.empty())
            s1.insert(data);
        else if (*s1.rbegin() > data)
            s1.insert(data);
        else
            s2.insert(data);

        arrangeDS();
    }

    int median()
    {
        if (s1.empty())
            return INT_MIN;

        return *s1.rbegin();
    }

    void erase(int data)
    {
        if (s1.find(data) != s1.end())
            s1.erase(s1.find(data));
        else if (s2.find(data) != s2.end())
            s2.erase(s2.find(data));

        arrangeDS();
    }
};

int32_t main()
{
    init();
    //--------------------
    //
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    medianDS mds;

    for (int &i : arr)
        cin >> i;

    int i = 0;
    for (int j = 0; j < n; j++)
    {
        mds.insert(arr[j]);
        if (j - i + 1 < k)
            continue;

        cout << mds.median() << " ";

        mds.erase(arr[i]);
        i++;
    }
    //---------------------------
    timeTaken();
    return 0;
}
