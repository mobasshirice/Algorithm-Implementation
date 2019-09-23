//https://codeforces.com/contest/1221/problem/D
#include<bits/stdc++.h>
using namespace std;


#define  SZ(items) (int)items.size()
#define  CLR(a)  memset(a,0,sizeof(a))
#define  SET(a)  memset(a,-1,sizeof(a))


int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};




template <class T> inline T biton(T n, T pos)
{
    return n | ((T)1 << pos);
}
template <class T> inline T bitoff(T n, T pos)
{
    return n & ~((T)1 << pos);
}
template <class T> inline T ison(T n, T pos)
{
    return (bool)(n & ((T)1 << pos));
}
template <class T> inline T gcd(T a, T b)
{
    while (b)
    {
        a = a%b;
        swap(a, b);
    }
    return a;
}
template <class T> inline T bigmod(T p, T e, T m)
{
    T ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1)
            ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (T)ret;
};

#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " is " << arg1 << std::endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " is " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(...)
#endif


long long dp[300005][5];
long long visited[300005][5];
int cs=0;
vector<pair<long long,long long>> items;


long long recur(int pos,int last)
{

    if(pos==items.size())
    {
        return 0;
    }

    if(visited[pos][last]==cs){
        return dp[pos][last];
    }

    long long mn=1e18;

    for(int i=0; i<=4; i++)
    {
        if(items[pos-1].first+last!=items[pos].first+i)
        {
            mn=min(mn,recur(pos+1,i)+items[pos].second*i);
        }
    }

    visited[pos][last]=cs;

    return dp[pos][last]=mn;

}

void solve()
{
    cs++;
    items.clear();
    items.push_back({0,0});
    int n;
    cin>>n;


    for(int i=0; i<n; i++)
    {
        long long u,v;
        cin>>u>>v;
        items.push_back({u,v});
    }

    long long ans=recur(1,0);

    cout<<ans<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t = 1;
    cin>>t;

    while (t--)
    {
        solve();
    }

    return 0;
}
