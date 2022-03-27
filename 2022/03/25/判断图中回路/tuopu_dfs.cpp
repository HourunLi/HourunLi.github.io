#include<bits/stdc++.h>
using namespace std;

#define N 7
vector<vector<int> > edges = {{2, 4, 5}, {0, 2}, {}, {5}, {}, {4, 6}, {}};
vector<int> indeg;
vector<int> result;
int main() {
    indeg.resize(N);
    for(auto &vec : edges) {
        for(auto &edge : vec) {
            ++indeg[edge];
        }
    }

    queue<int> q;
    for(int i = 0; i < N; ++i) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int top = q.front(); q.pop();
        result.push_back(top);
        for(int v : edges[top]) {
            --indeg[v];
            if(indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    if(result.size() != N) {
        cout << "There is a cicle in graph\n";
    } else{
        cout << "The topological order is: ";
        for(int i = 0; i < N; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
