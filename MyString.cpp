#include <iostream>
class myString
{
private:
    char *str;
public:
    myString() : str(NULL) {};
    myString(const char *s);
    ~myString();
    myString(const myString &s);
    char& operator[](int i);
    myString &operator=(const myString &s);
    myString &operator=(const char *s);
    myString operator+(const myString &s) const;
    myString operator+(const char *s) const;
    myString &operator+=(const myString &s);
    myString &operator+=(const char *s);
    friend std::ostream &operator<<(std::ostream &out, const myString &s);
    void push_back(char c);
    void pop_back();
    void clear();
    void resize(int n);
};

myString::myString(const char *s)
{
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}


myString::myString(const myString &s)
{
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}
myString::~myString()
{
    delete [] str;
    str = NULL;
}


char& myString::operator[](int i)
{
    if (i >= 0 && i < strlen(str))
        return str[i];
    else
        throw "Index out of range";
}
myString &myString::operator=(const myString &s)
{
    if (this != &s)
    {
        delete [] str;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    return *this;
}

myString &myString::operator=(const char *s)
{
    delete [] str;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    return *this;
}

myString myString::operator+(const myString &s) const
{
    char *temp = new char[strlen(str) + strlen(s.str) + 1];
    strcpy(temp, str);
    strcat(temp, s.str);
    myString t(temp);
    delete [] temp;
    return t;
}

myString myString::operator+(const char *s) const
{
    char *temp = new char[strlen(str) + strlen(s) + 1];
    strcpy(temp, str);
    strcat(temp, s);
    myString t(temp);
    delete [] temp;
    return t;
}

myString &myString::operator+=(const myString &s)
{
    char *temp = new char[strlen(str) + strlen(s.str) + 1];
    strcpy(temp, str);
    strcat(temp, s.str);
    delete [] str;
    str = temp;
    return *this;
}

myString &myString::operator+=(const char *s)
{
    char *temp = new char[strlen(str) + strlen(s) + 1];
    strcpy(temp, str);
    strcat(temp, s);
    delete [] str;
    str = temp;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const myString &s)
{
    out << s.str;
    return out;
}

void myString::push_back(char c)
{
    char *temp = new char[strlen(str) + 2];
    strcpy(temp, str);
    temp[strlen(str)] = c;
    temp[strlen(str) + 1] = '\0';
    delete [] str;
    str = temp;
}

void myString::pop_back()
{
    char *temp = new char[strlen(str)];
    strcpy(temp, str);
    temp[strlen(str) - 1] = '\0';
    delete [] str;
    str = temp;
}

void myString::clear()
{
    delete [] str;
    str = NULL;
}

void myString::resize(int n)
{
    char *temp = new char[n + 1];
    strcpy(temp, str);
    temp[n] = '\0';
    delete [] str;
    str = temp;
}


int main()
{
    using namespace std;
    myString s1("hello "), s2("world");
    s1[0] = 'H';
    myString s3 = s1 + s2;
    cout << s3 << endl;
    s3 += "!";
    cout << s3 << endl;
    return 0;
}