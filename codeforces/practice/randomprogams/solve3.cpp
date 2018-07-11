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


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
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


void solve()
{
    string s ;
    cin >>s;
    int n;cin >>n;
    string x="";
    string te="";
   
    
    for(int i =0;i<n;i++){
        int t;
        cin >>t;
        if(t<0){
            int pos=abs(t);
            for(int j =pos;j<s.length();j++){
                if(s[j]=='a' ||s[j]=='e' ||s[j]=='i' ||s[j]=='o' ||s[j]=='u'  )
                x+=s[j];
            }
        }else{
            for(int j =0;j<=t;j++){
                if(s[j]=='a' ||s[j]=='e' ||s[j]=='i' ||s[j]=='o' ||s[j]=='u'  )
                
                x+=s[j];
            }
        }
       // cout<<x<<endl;
    }
    int q;cin>>q;
    for(int i=0;i<q;i++)
    {   
        int temp;
        cin >>temp;
        if(temp<=x.length()){
            cout<<x[temp-1]<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}
