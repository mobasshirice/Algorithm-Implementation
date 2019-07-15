#include<bits/stdc++.h>
using namespace std;


struct item
{

    int a;
    int b;

    item(int _a,int _b)
    {
        a=_a;
        b=_b;
    }

    bool operator<(const item& rhs) const
    {
        return a < rhs.a;
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<item> v;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;

        v.push_back({a,a});
    }

    sort(v.begin(),v.end());
    
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].a<<" ";
    }
}

int main()
{
    int t;
    t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
