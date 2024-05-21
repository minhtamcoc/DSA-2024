#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V, E;
vector<int> v[1001];
bool visited[1001];
int check;

void hamilton(int k, int cnt) {
    if (cnt == V) {
        check = 1;
        return;
    }
    visited[k] = true;
    for (auto x : v[k]) {
        if (!visited[x]) {
            hamilton(x, cnt + 1);
        }
    }
    visited[k] = false;
}

void solve() {
    cin >> V >> E;
    check = 0;
    memset(v, 0, sizeof(v));
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= E; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x); // Thêm cả 2 chiều của cạnh
    }

    int res = 0;
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            hamilton(i, 1);
        }
        if (check == 1) {
            cout << "1" << endl;
            res = 1;
            break;
        }
    }
    if (res == 0) {
        cout << "0" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
