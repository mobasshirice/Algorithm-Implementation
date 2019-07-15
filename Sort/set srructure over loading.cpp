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
        if(a==rhs.a){
            return b < rhs.b;
        }
        
        return a < rhs.a;
    }
};

void solve()
{
    int n;
    cin>>n;
    set<item> v;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;

        v.insert({a,i});
    }


    for(auto it:v){
        cout<<it.a<<" ";;
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
