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
const ll n=1000000;
bool ar[n];

void solve()
{
    memset(ar,0,sizeof(bool)*n);
    
    for(ll i=2;i*i<n;i++){
        if(ar[i]==0){
            for(ll j=2*i;j<n;j+=i){
                ar[j]=1;
            }
        }
    }
    cout<<"found sieve"<<endl;
    for(long i=2;i<n;i++){
        if(ar[i]==0){
            //if it is prime no
            // watch(i);
            vector <int> cc[10];
            for(int t=0;t<10;t++){
                cc[t].clear();
            }
           
            ll index=0;
            ll temp=i;  
            vector<int> arr;
            arr.clear();
            
            while(temp){
                cc[(temp%10)].push_back(index);
                arr.push_back(temp % 10);
                temp/=10;
                index++;
            }
            set <int> st;
            
            
            st.insert(i);
            // for(int h=0;h<10;h++){
            //     if(cc[h].size()>0){
            //         for (int g = 0; g < cc[h].size(); g++){
            //             watch(h);
            //             watch(cc[h][g]);
            //         }
            //     }
            // }
            for(int t=0;t<10;t++){
                if(cc[t].size()>0){
                    for (int m = 0; m < 10; m++)
                    {
                        if(m!=t){
                            int f=1;
                            for (int h = 0; h < cc[t].size(); h++)
                            {
                                assert(cc[t][h] < arr.size());
                                if (cc[t][h]==arr.size()-1 && m==0){
                                   f=0; 
                                }
                                    arr[cc[t][h]] = m;  
                            }
                            
                            ll ele=0;
                            for (int h = arr.size()-1; h >=0 ; h--)
                            {
                                ele=ele*10+arr[h];
                            }
                            
                            
                            if(ele<n){
                                if(ar[ele]==0 && f==1){
                                    st.insert(ele);
                                }
                            }
                        }
                     
                    }
                       
                        if (st.size() == 8)
                        {
                            cout<<"working "<<endl;
                            for (auto itt = st.begin(); itt != st.end(); itt++)
                                {
                                    cout << *itt << " ";
                                 }
                                 cout << endl;
                        }
                        st.clear();
                   

                    for (int h = 0; h < cc[t].size(); h++)
                    {
                        assert(cc[t][h]<arr.size());
                            arr[cc[t][h]] = t;
                    }
                    
                }
            }
           

        }
    }
    
}