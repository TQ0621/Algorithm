#include "iostream" 
double myPow(double x, int n) {
    double ans = 1;
    long long N = n;
    if (n < 0)
    {
        N = -n;
        x = 1 / x;
    }
    
    while (N) { //快速幂运算
        if (N & 1) ans *= x;//只有N二进制的最低位为1才乘.
        x *= x;             //例如x^13   13 = 1101   -> x^8*x^4*x^1 
        N >>= 1;            //1      1      0      1
    }                       //x^8    x^4    x^2    x^1
    return ans;
}

int main() {
    using namespace std;
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n) << endl;
}