#include<bits/stdc++.h>
using namespace std;

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


void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    set<int> items;
    int mx=0;
    int mn=1e8;

    for(int i=0; i<n; i++)
    {
        int item;
        cin>>item;
        items.insert(item);
        mx=max(mx,item);
        mn=min(mn,item);
    }

    long long res=0;
    for(int i=mn; i<=mx; i++)
    {
        int from=i;
        int to=from+m-1;

        while(true)
        {
            set<int>::iterator it_l, it_u;
            it_l = items.lower_bound(from);
            it_u = items.upper_bound(to);
            int cnt = std::distance(it_l, it_u);

            if(cnt>=k)
            {
                items.erase(--items.upper_bound(to));
                res++;
            }
            else
            {
                break;
            }
        }
    }

    cout<<res<<endl;
}

int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
