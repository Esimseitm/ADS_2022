// graph
// матрица смежности
#include <iostream>

using namespace std;
int g[100][100];



int main() {
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    for


    return 0;
}