#include<bits/stdc++.h>

using namespace std;

#define  SZ(items) (int)items.size()
#define  CLR(a)  memset(a,0,sizeof(a))
#define  SET(a)  memset(a,-1,sizeof(a))

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
}

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

const int N=100005;

int path[N];

void root(int n)
{
    for(int i=0; i<=n; i++)
        path[i]=i;
}

int findUnion(int x)        ///Find root of x
{
    if(path[x]==x)
        return x;
    return path[x]=findUnion(path[x]);

}

void mergeUnion(int x,int y)
{
    path[findUnion(x)]=findUnion(y); ///making same root of both x and y
}
bool sameset(int x,int y)   ///check two element are in same set or not
{
    return findUnion(x)==findUnion(y);
}


void solve()
{
    root(100);

    cout<<sameset(7,6)<<endl;
    mergeUnion(6,5);
    mergeUnion(7,6);
    cout<<sameset(7,6)<<endl;
    cout<<sameset(7,5)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}
