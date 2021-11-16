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

class medianDS
{
    multiset<int> s1, s2;
    int s1Sum, s2Sum;

public:
    medianDS()
    {
        s1Sum = 0;
        s2Sum = 0;
    }

    void arrangeDS()
    {
        if ((int)(s1.size()) - (int)(s2.size()) > 1)
        {
            auto lastElement = prev(s1.end());

            s2Sum += *lastElement;
            s1Sum -= *lastElement;

            s2.insert(*lastElement);
            s1.erase(lastElement);
        }
        else if (s2.size() > s1.size())
        {
            s1Sum += *(s2.begin());
            s2Sum -= *(s2.begin());

            s1.insert(*(s2.begin()));
            s2.erase(s2.begin());
        }
    }

    void insert(int data)
    {
        if (s2.empty() && s1.empty())
        {
            s1.insert(data);
            s1Sum += data;
        }
        else if (*s1.rbegin() > data)
        {
            s1.insert(data);
            s1Sum += data;
        }
        else
        {
            s2.insert(data);
            s2Sum += data;
        }

        arrangeDS();
    }

    int median()
    {
        if (s1.empty())
            return INT_MIN;

        return *s1.rbegin();
    }

    int getCost()
    {
        int sumSmall = (s1.size() - 1) * (*s1.rbegin()) - (s1Sum - (*s1.rbegin()));
        int sumLarge = (s2.size()) * (*s1.rbegin()) - s2Sum;

        return abs(sumLarge) + abs(sumSmall);
    }

    void erase(int data)
    {
        if (s1.find(data) != s1.end())
        {
            s1.erase(s1.find(data));
            s1Sum -= data;
        }
        else if (s2.find(data) != s2.end())
        {
            s2.erase(s2.find(data));
            s2Sum -= data;
        }

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

        cout << mds.getCost() << " ";

        mds.erase(arr[i]);
        i++;
    }
    //---------------------------
    timeTaken();
    return 0;
}
