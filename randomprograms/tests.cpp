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

template <class T>
struct tree{
    T element;
    struct tree *left;
    struct tree *right;
    tree(int n)
    {
        element =n;
        left=NULL;
        right=NULL;        
    }
    friend struct tree * insert(T ele, tree *node){
        if(node==NULL){
            node = new tree(ele);
            return node;
        }
        if( node->element < ele ){
            node->right=insert(ele,node->right);
        }
        else if ((node->element) >ele)
        { 
            node->left=insert(ele,node->left);
        }
        return node;
    }
    friend void show(struct tree *head){
        if(head==NULL){
            return;
        }else{
            show(head->left);
            cout<<head->element<<endl;
            show(head->right);
        }
    };
    

    friend struct tree * getparentnode(T ele,tree * root)
    {
        if(ele<root->element){
            return getparentnode(ele,root->left);
        }else if (ele>root->element){
            return getparentnode(ele,root->right);
        }else{
             return root;
        }
    }
    friend void remove(T ele,tree *root){
       

        struct tree * deletionnode=getparentnode(ele,root);
        if(deletionnode->left==NULL && deletionnode->right==NULL){
            
        }
    }
};
void foo()
{
    tree<int> *node =NULL ;
    node = insert(9,node);
    insert(5, node);
    insert(11, node);
    show(node);

}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    foo();
    return 0;
}