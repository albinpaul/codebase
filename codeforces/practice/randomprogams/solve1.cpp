#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i, n) for (long i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define debug() cerr << "running till line " << __LINE__ << " in function " << __func__ << endl
const double PI = 3.141592;
const int inf = (int)1.01e9;
const double eps = (1e-9);
typedef unsigned long long ull;
typedef long long ll;
typedef vector<long> vl;
typedef vector<int> vi;

void solve();
template <class T>
void print(T container1)
{
    for (auto it : container1)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
#ifdef _DEBUG
    int tt = clock();
#endif

    solve();

#ifdef _DEBUG
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
#endif
}
long A[(long)1.2e5];
long C[(long)1.2e5];
long dp[(long)1.2e5];

void solve()
{
    long int n,k;
   cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
      cin>>A[i]; 
    }
    for (int i = 0; i < n; i++)
    {
    cin>>C[i];
    }

    dp[n-1]=min(A[n-1],C[n-1]);
    for(int i =n-2;i>=0;i--){
        
        long m = 2147483647;
        for (int j = 1; j < k; j++)
        {
            if(i+j<n){
                if(m > dp[i+j]){
                    m=dp[i+j];
                }
            }else{
                m=0;
                break;
            }
        }
        
        if (A[i] + dp[i + 1] <C[i]+m){
            dp[i]=A[i]+dp[i+1];
        }else{
            dp[i]=C[i]+m;
        }
    }

    // for(int i =0;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }cout<<endl;
    cout<<dp[0];
}
