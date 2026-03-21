#include <iostream>
#include <vector>
#define ll long long

int N;
std::vector<int> bit;
inline int lowbit(int x) {
    return x & (-x);
}

void add(int p, int x) {
    while (p <= N) {
        bit[p] += x;
        p += lowbit(p);
    }
}

ll count(int p) {
    ll res = 0;
    while (p) {
        res += bit[p];
        p -= lowbit(p);
    }
    return res;
}
int main() {
    using namespace std;
    cin >> N;
    bit.resize(N + 1);
    //构造树状数组
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        add(i, x);
    }

    return 0;
}