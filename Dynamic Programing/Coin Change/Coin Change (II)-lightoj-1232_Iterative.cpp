//http://lightoj.com/volume_showproblem.php?problem=1140
#include<bits/stdc++.h>
using namespace std;
 
int n, k;
vector<int> items;
 
int dp[2][10001];
 
int recur(int pos, int make)
{
 
    if (pos == items.size() || make > k) {
        return 0;
    }
 
    if (make == k)
    {
        return 1;
    }
 
    return dp[pos%2][make];
}
 
int main()
{
    int tc;
    cin >> tc;
 
    for (int t = 1; t <= tc; t++)
    {
        items.clear();
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
 
        for (int it = 0; it < n; it++) {
            int item;
            cin >> item;
            items.push_back(item);
        }
 
        for (int pos = n - 1; pos >= 0; pos--)
        {
            for (int make = k; make >= 0; make--)
            {
 
                int taking = recur(pos,  make + items[pos]);
 
                int nottaking = recur(pos + 1, make);
 
                dp[pos%2][make] = (taking + nottaking) % 100000007;
 
            }
        }
 
        int res = dp[0][0];
 
        cout << "Case " << t << ": " << res << endl;
    }
 
 
 
    return 0;
}