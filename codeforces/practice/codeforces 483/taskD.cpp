#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << endl
const double PI = 3.141592;
const int inf = (int)1.01e9;
const double eps = (1e-9);
typedef unsigned long long ull;
typedef long long ll;
typedef vector<long> vl;
typedef vector<int> vi;

void solve();

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
#ifdef _DEBUG
    int tt = clock();
#endif

    solve();

#ifdef _DEBUG
    cout<< "TIME = " << clock() - tt <<" ms "<< endl;
    tt = clock();
#endif
}

void solve()
{
    int n;
    cin>>n;
    long long ar[n+1];
    long long dp[n+1];
    memset(dp,0,sizeof(int)*(n+1));
    ar[0]=0;
    for(int i =1;i<=n;i++) {
        cin>>ar[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        dp[i]=dp[i-1]^ar[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        long long s=0;
        for(int i =l;i<=r;i++){
            for(int j=i;j<=r;j++){
                ll range=i-j+1;
                ll m;
                if (range & 1)
                    m = ar[j] ^ ar[i - 1];
                else{
                    m = dp[j] ^ dp[i - 1];
                }
                if(m>s){
                    watch(i);watch(j);
                    watch(m);
                    watch(s);
                    s=m;
                }
            }
        }
        cout<<s<<endl;
    }
    return;
}