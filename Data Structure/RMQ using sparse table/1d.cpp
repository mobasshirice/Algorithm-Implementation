#include<bits/stdc++.h>
#define N 200000
using namespace std;

int table[22][N];
int Log[N];
void RMQ_init(vector<int>  ar) {
    int n=(int)ar.size();
    for(int i=0; i<n; i++)
        table[0][i] = ar[i];
    for(int i=2; i<=n; i++) Log[i]=1+Log[i/2];
    for(int i =1; i<20; i++)
        for(int j=0; j+(1<<(i-1))<n; j++)
            table[i][j]=max(table[i-1][j],table[i-1][j+(1<<(i-1))]);  /// j+1<<(i-1) means shifting index
                                                                      /// at j+2^(i-1)
                                                                      /// use min/gcd for gcd
}

int getmax(int i,int j) {
    int k = Log[j-i+1];
    return max(table[k][i],table[k][j-(1<<k)+1]);/// use min/gcd for gcd

}
int main() {
    vector<int> ar= {209 ,100 ,51 ,999,671,939, 350, 811 ,114, 997, 1000, 173, 786, 696, 50, 490, 637, 631 ,394 ,708, 543, 135, 260 ,378, 1017 ,368, 683 ,30, 117};
    RMQ_init(ar);
    cout<<getmax(0,1)<<endl;
    ///RMQ is range maximum query..
    ///for range minimum query just write min instead of max
}
