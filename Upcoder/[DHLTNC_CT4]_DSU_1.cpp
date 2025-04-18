#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> parent;
vector<int> rank_tree;
set<int> s;
int check = 1;

int find_set(int v){
    return v == parent[v] ? v : parent[v] = find_set(parent[v]); // tim cha cua cay va gan cho cha cua cay la cha cua cay cha cua cay do
}

void union_set(int a, int b, int t){
    a = find_set(a);
    b = find_set(b);
    if (a == b && t == 0){
        check = 0; // neu t = 0 thi check = 0 thi khong the tao cay voi cac dinh do
        return;
    }
    if(t == 1){
        if(a != b) 
        if(rank_tree[a] < rank_tree[b])
            swap(a, b);
        parent[b] = a;
        if(rank_tree[a] == rank_tree[b])
            rank_tree[a]++;
    }
}

void make_set(int v){
    parent[v] = v;
    rank_tree[v] = 0;
}

void trees(){
    for(int i = 0; i < parent.size() - 1; i++)  s.insert(find_set(i + 1));
    cout << s.size();
}

int main(){
    int n, m;
    int u, v, t;
    cin >> n >> m;
    parent.resize(n + 1);
    rank_tree.resize(n + 1);
    for(int i = 0; i < n; i++)  make_set(i + 1); // tao cay
        for(int i = 0; i < m; i++){
            if(check == 0)  break;
            else{
                cin >> u >> v >> t;
                union_set(u, v, t); // neu t = 1 thi them u v vao 1 cay
            }
        }
        if(check == 0) cout << -1;
        else trees();
    
    return 0;
}