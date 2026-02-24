#include "iostream"
#include "vector"
#include "climits"
static std::vector<std::vector<int>> D;//邻接矩阵
static int s[1005][2];//查询的节点
int main()
{
    using namespace std;
    int n, m, k, q;//n行，m列，k条边，q个查询
	cin >> n >> m >> k >> q;
    D.resize(n+1, vector<int>(n+1, INT_MAX));
    for (int i = 1; i <= k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        D[x][y] = D[y][x] = min(D[x][y], z);
        D[x][x] = D[y][y] = 0;
    }
    for (int p = 1; p <= n; p++)
        for (int i = 1; i <= n; i++) {
            if (i == p || D[i][p] == INT_MAX) continue;
            for (int j = 1; j <= n; j++) {
                if (j == p || D[p][j] == INT_MAX) continue;
                D[j][i] = D[i][j] = min(D[i][j], D[i][p] + D[p][j]);
            }
        }
    for (int i = 1; i <= q; i++) {
        cin >> s[i][0] >> s[i][1];
    }
    for (int i = 1; i <= q; i++) {
        if (D[s[i][0]][s[i][1]] == INT_MAX) cout << -1 << " ";
        else cout << D[s[i][0]][s[i][1]] << " ";
    }
    return 0;
}