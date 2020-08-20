#include <bits/stdc++.h>

using namespace std;
#define range(i,n)  for(long i = 0  ; i < (long long)n ; ++i )
#define rrange(i,n) for(long i = (long long)n-1; i >= 0; --i )
#define all(x) x.begin(),x.end()
#define watch(x) cerr << #x << " is : " << x << " " ;

const int INF = 0x3f3f3f3f;
typedef long long  ll;

const int N =1.1e5;
class fenwicktree
{
    vector <int> tree;
    int n;
    public:
    
    void debug() {
        for(auto it:tree) {
            cout << it << " ";
        }cout << endl;
    }
    fenwicktree(int num):n(num+1),mode(m) {
        tree.resize(n,0);
    }
    void insert(int i,int delta) {
        i++;
        for(int j=i;j<n;j += j&-j){
            tree[j] += delta;
        }
    }
    long get(int l){
        long sum = 0;
        for (int i=l;i>0;i-= i&-i){
            sum += tree[i];
        }
        return sum;
    }
    long get(int l,int r) {
        return get(r) -get(l);
    }
};


int main(void) {
    fenwicktree ft(4);
    vector <int> a{1,2,3,4};
    for(int i=0;i<4;i++) {
        ft.insert(i,a[i]);
    }
    ft.debug();
    cout << ft.get(1) << endl;

    return 0;

}