#include <bits/stdc++.h>
using namespace std;
struct FenwickTree {
    vector<int> bit; // binary indexed tree
    int n;

    void init(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
            ret += bit[r];
        return ret;
     }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx+1))
            bit[idx] += delta;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    void init(vector<int> a) {
        init(a.size());
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
};
int main(){
    vector <int > ar = {1,2,3,4,5,6,7,8,9};
    FenwickTree tree;
    tree.init(ar);
    cout<<tree.sum(9)<<endl;
    for(int a:tree.bit){
        cout<<a<<" ";
    }cout<<endl;
    return 0;

}