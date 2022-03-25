#include<bits/stdc++.h>
using namespace std;

#define N 5
int edge[N][N] = {{0, 0, 0, 1, 1},
                {1, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {0, 0, 0, 0, 0}};

char vis[N];

bool is_circle(int ind) {
    if (vis[ind] == 2) return false;
    if (vis[ind] == 1) return true;
    vis[ind] = 1;
    bool ret = false;
    for(int i = 0; i < N; i++) {
        if(edge[ind][i]) {
            ret |= is_circle(i);
        }
    }
    vis[ind] = 2;
    return ret;
}

int main() {
    bool flag = false;
    for(int i = 0; i < N; i++) {
        flag |= is_circle(i);
    }
    cout << "There is" << (flag ? " " : " not ") << "a circle in graph\n";
    return 0;
}