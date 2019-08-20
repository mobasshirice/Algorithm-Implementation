#include<bits/stdc++.h>
//https://codeforces.com/contest/1200/problem/E

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


#define  N  1000005
const long long MOD[] = { 1000000007LL, 2117566807LL,1000000007LL,1000000037LL };
const long long BASE[] = { 1572872831LL, 1971536491LL,1000003LL,31 };

class stringhash
{
public:
    long long base, mod, len, ar[N], P[N], nextpos;

    void GenerateFH(string &s, long long b, long long m)
    {
        base = b;
        mod = m;
        len = s.length();
        nextpos=len;
        P[0] = 1;
        long long h = 0;
        for (int i = 1; i < len; i++)
            P[i] = ((long long)P[i - 1] * (long long)base) % mod;
        for (int i = 0; i < len; i++)
        {
            h = (h*base) + s[i];
            h %= mod;
            ar[i] = h;
        }
    }
    void Add(string &s)
    {
        if(nextpos==0)
        {
            throw std::invalid_argument( "you have to genrate hash first!" );
        }

        long long clen = s.length();
        len = nextpos + clen;

        for (int i = nextpos; i < len; i++)
            P[i] = ((long long)P[i - 1] * (long long)base) % mod;
        long long h = ar[nextpos - 1];

        for (int j = 0; j < clen; j++, nextpos++)
        {
            h = (h*base) + s[j];
            h %= mod;
            ar[nextpos] = h;
        }
    }


    int Fhash(int x, int y)
    {
        long long h = ar[y];
        if (x > 0)
        {
            h = (h - (long long)P[y - x + 1] * (long long)ar[x - 1]) % mod;
            if (h < 0)
                h += mod;
        }
        return h;
    }

    void GenerateRH(string &s, long long b, long long m)
    {
        base = b;
        mod = m;
        len = s.length();
        P[0] = 1;
        long long h = 0;
        for (int i = 1; i < len; i++)
            P[i] = ((long long)P[i - 1] * (long long)base) % mod;
        for (int i = len - 1; i >= 0; i--)
        {
            h = (h*base) + s[i];
            h %= mod;
            ar[i] = h;
        }
    }
    long long Rhash(int x, int y)
    {
        long long h = ar[x];
        if (y < len - 1)
        {
            h = (h - (long long)P[y - x + 1] * (long long)ar[y + 1]) % mod;
            if (h < 0)
                h += mod;
        }
        return h;
    }


};

stringhash mainhash,subhash;

void solve(){

    int n;
    cin>>n;
    string ans;

    for(int i=0;i<n;i++){
        string cur;
        cin>>cur;
        if(i==0){
            ans=cur;
            mainhash.GenerateFH(ans,BASE[0],MOD[0]);
        }
        else{
            int index=-1;
            subhash.GenerateFH(cur,BASE[0],MOD[0]);
            int curlen=cur.size();
            int anslen=ans.size();

            for(int j=0;j<curlen&&j<anslen;j++){

                if(subhash.Fhash(0,j)==mainhash.Fhash(anslen-1-j,anslen-1)){
                    index=j;
                }
            }

            string temp=cur.substr(index+1);

            mainhash.Add(temp);

            ans+=temp;
        }
    }

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
    while (t--)
    {
        solve();
    }

    return 0;
}
