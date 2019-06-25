//https://codeforces.com/problemset/problem/1181/C

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

class rangQuery
{
public:


    int table[22][1005];
    int Log[1005];

    void RMQ_init(vector<int> &ar)
    {
        int n=ar.size();

        for(int i=0; i<n; i++)
            table[0][i] = ar[i];
        for(int i=2; i<=n; i++)
            Log[i]=1+Log[i/2];
        for(int i =1; i<20; i++)
            for(int j=0; j+(1<<(i-1))<n; j++)
                table[i][j]=min(table[i-1][j],table[i-1][j+(1<<(i-1))]);  /// j+1<<(i-1) means shifting index
        /// at j+2^(i-1)
    }

    int getmin(int i,int j)
    {
        int k = Log[j-i+1];
        return min(table[k][i],table[k][j-(1<<k)+1]);

    }

};

char grid[1005][1005];
int gridcntRow[1005][1005];
int gridcntColumn[1005][1005];
rangQuery rng[1005];

void solve()
{
    int n,m;
    cin>>n>>m;


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>grid[i][j];
        }
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=m; j>=1; j--)
        {
            if(grid[i][j]==grid[i][j+1])
            {
                gridcntRow[i][j]=gridcntRow[i][j+1]+1;
            }
            else
            {
                gridcntRow[i][j]=1;
            }
        }
    }


    for(int j=1; j<=m; j++)
    {
        for(int i=n; i>=1; i--)
        {
            if(grid[i][j]==grid[i+1][j])
            {
                gridcntColumn[i][j]=gridcntColumn[i+1][j]+1;
            }
            else
            {
                gridcntColumn[i][j]=1;
            }
        }
    }


       for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<gridcntColumn[i][j]<<" ";
        }
        cout<<endl;
    }


    for(int j=1; j<=m; j++)
    {
        vector <int> arr;

        for(int i=1; i<=n; i++)
        {
            arr.push_back(gridcntRow[i][j]);
        }

        rng[j].RMQ_init(arr);
    }


    long long ans=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int cnt1=gridcntColumn[i][j];

            char a=grid[i][j];

            int cnt2=gridcntColumn[i+cnt1][j];

            if(cnt1==cnt2)
            {
                continue;
            }

            char c=grid[i+cnt1*2][j];

            int cnt3=gridcntColumn[i+cnt1*2][j];
             debug(cnt3,cnt2);
            if(cnt2>cnt3)
            {
                continue;
            }



            int from=i;
            int to=from+cnt1*3-1;


            long long res=rng[j].getmin(from-1,to-1);
            debug(res);
            ans+=res;

        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cout.setf(ios::fixed);cout.precision(10);cout.tie(nullptr);cin.tie(nullptr);

    int t = 1;

    while (t--)
    {

        solve();
    }

    return 0;
}
