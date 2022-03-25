#include<bits/stdc++.h>
using namespace std;

#define N 5
int edge[N][N] = {{0, 0, 0, 1, 1},
                {1, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {0, 0, 0, 0, 0}};


int parent[N];

int Find(int x) {
    if(x ==parent[x]) 
        return x;
    parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y) {
    int p_x = Find(x);
    int p_y = Find(y);
    if(p_x != p_y) {
        parent[p_x] = p_y;
    }
    return;
}


int main() {
    for(int i = 0; i < N; i++) {
        parent[i] = i;
    }
    bool flag = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(edge[i][j]) {
                if(Find(i) == Find(j)) {
                    flag = true;
                    break;
                }else{
                    Union(i, j);
                }
            }
        }
    }
    cout << "There is" << (flag ? " " : " not ") << "a circle in graph\n";
    return 0;
}
