//#include "head.h"
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
using namespace std;

static struct Timer
{
private:
    clock_t start;
public:
    Timer() { start = clock(); }
    ~Timer() { cout << "Time: " << clock() - start << "ms" << endl; }
};

static void My_nextval(int* const next, const string& sub)
{
    int sublen = sub.size();
    next[0] = -1;
    
    int i = 0;  
    int j = -1; 
    
    while (i < sublen - 1)  
    {
        if (j == -1 || sub[i] == sub[j]) {
            i++;
            j++;
            // 普通next数组计算
            next[i] = j;
            
            // 优化：如果当前字符和回溯位置的字符相同
            if (sub[i] == sub[j]) {
                next[i] = next[j];
            }
        }
        else {
            j = next[j];
        }
    }
}

static int My_KMP(const string& str, const string& sub)
{
    Timer timer;
    assert(&str != nullptr && &sub != nullptr);
    int strlen = str.size();
    int sublen = sub.size();
    
    if (strlen == 0 || sublen == 0)
        return -1;
    
    int* const next = new int[sublen];
    assert(next != nullptr);
    
    // 计算next数组
    My_nextval(next, sub);
    
    int i = 0, j = 0;
    while (i < strlen && j < sublen)
    {
        if (j == -1 || str[i] == sub[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    
    delete[] next;
    
    if (j == sublen)
        return i - j;
    else
        return -1;
}

int main()
{
    string str, sub;
    cin >> str >> sub;
    cout << My_KMP(str, sub);
    cin.get();
    return 0;
}