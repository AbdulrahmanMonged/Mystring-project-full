#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <iostream>

class Mystring {

//friends
    

private:
    friend Mystring operator*(const Mystring &rhs, const int &lhs);
    friend Mystring operator*=(Mystring &rhs, const int &lhs);
    friend Mystring operator+=(Mystring &rhs, const Mystring &lhs);
    friend Mystring operator+(const Mystring &rhs, const Mystring &lhs);
    friend bool operator<=(const Mystring &rhs, const Mystring &lhs);
    friend bool operator>=(const Mystring &rhs, const Mystring &lhs);
    friend bool operator<(const Mystring &rhs, const Mystring &lhs);
    friend bool operator>(const Mystring &rhs, const Mystring &lhs);
    friend bool operator!=(const Mystring &rhs, const Mystring &lhs);
    friend bool operator==(const Mystring &rhs, const Mystring &lhs);
    friend Mystring operator++(Mystring &obj);
    friend Mystring operator--(Mystring &obj);
    friend Mystring operator--(Mystring &obj, int);
    friend Mystring operator++(Mystring &obj, int);
    friend std::ostream &operator<<(std::ostream &os, const Mystring &obj);
    friend std::istream &operator>>(std::istream &is, Mystring &obj);
    char *str;

public:
    
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);

};


#endif // __MYSTRING_H__
