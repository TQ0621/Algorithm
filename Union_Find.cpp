#include "iostream"
static int fa[10005];
int find(int x) {
    //更新路径上的所有节点的父节点为根节点
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

void Union(int x, int y) {
    // 将 x 和 y 的根节点连接起来
    //小并大合并能够降低树的高度，减少 find 的时间复杂度
    fa[find(x)] = find(y);
    return;
}
int main() {
    using namespace std;
    int  n;
    cin >> n;
    for (int i = 1; i <= n; i++) fa[i] = i;


    return 0;
}