#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i, n) for (long i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define debug() cerr<<"running till line "<<__LINE__<<" in function " << __func__<<endl
const double PI = 3.141592;
const int inf = (int)1.01e9;
const double eps = (1e-9);
typedef unsigned long long ull;
typedef long long ll;
typedef vector<long> vl;
typedef vector<int> vi;

void solve();
template <class T>
void print(T container1){
    for(auto it: container1){
        cout<<it<<" ";
    }cout<<endl;
}
int main(int argc, char const *argv[])
{
   // ios::sync_with_stdio(false);
    // std::cin.tie(0);
#ifdef _DEBUG
    int tt = clock();
#endif

    solve();

#ifdef _DEBUG
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
#endif
}
long ar[(long) 1.2e5];
long dp[(long)1.2e5];

void solve()
{
    long int n;
    scanf("%ld",&n);
    forn(i,n){
        long long temp;
        scanf("%lld",&temp);
        long bits=0;
        while(temp){
            bits|=(1<<(temp%10));
            temp/=10;
        }
        ar[i]=bits;
    }
    long m=0;
    for(int i =0;i<n;i++){
        
        for(int j=0;j<i;j++){
            if(ar[i]&ar[j]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        if(m<dp[i]){
            m=dp[i];
        }
    }
    
    printf("%d",m+1);
}
