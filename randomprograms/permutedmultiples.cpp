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
    solve();
    return 0;
}
int bitt(ll n){
    int b=0;
    
    while(n){
        b|=(1<<(n%10));
        n/=10;
    }

    return b;
}
const ll n=1000000;
void solve()
{
    //answer is 142857
    for(int i =1;i<n;i++){
        int x=bitt(i);
        if(x==bitt(2*i) && x==bitt(3*i) && x==bitt(4*i) && x==bitt(5*i)&&x==bitt(6*i)){
            cout<<i<<endl;
            break;
        }
    }

}