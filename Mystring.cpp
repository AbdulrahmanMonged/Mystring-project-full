#include "Mystring.h"
#include "cstring"
#include <iostream>
using namespace std;


Mystring::Mystring() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s) {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);

    }

}

Mystring::Mystring(const Mystring &source) : Mystring (source.str) {

}

Mystring::Mystring(Mystring &&source) {
    str = source.str;
    source.str = nullptr;
}

Mystring::~Mystring() {
    delete [] str;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs) {
        return *this;
    } else {
        delete [] str;
        str = new char[strlen(rhs.str) + 1];
        strcpy(str, rhs.str);
        return *this;
    }

}

Mystring &Mystring::operator=(Mystring &&rhs) {
    if (this == &rhs) {
        return *this;
    } else {
        delete [] str;
        str = rhs.str;
        rhs.str = nullptr;
        return *this;  
    }
}

ostream &operator<<(ostream &os, const Mystring &obj) {
    os << obj.str;
    return os;
}

istream &operator>>(istream &is, Mystring &obj) {
    delete [] obj.str;
    obj.str = new char[1000];
    is >> obj.str;
    return is;
}

Mystring operator--(Mystring &obj) {
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i {}; i < strlen(buff) ; ++i) {
        buff[i] = tolower(buff[i]);
    }
    obj = Mystring{buff};
    delete [] buff;
    return obj;
}
Mystring operator--(Mystring &obj, int) {
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i {}; i < strlen(buff) ; ++i) {
        buff[i] = tolower(buff[i]);
    }
    obj = Mystring{buff};
    delete [] buff;
    return obj;
}


Mystring operator++(Mystring &obj) {
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i {}; i < strlen(buff) ; ++i) {
        buff[i] = toupper(buff[i]);
    }
    obj = Mystring{buff};
    delete [] buff;
    return obj;
}

Mystring operator++(Mystring &obj, int) {
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i {}; i < strlen(buff) ; ++i) {
        buff[i] = toupper(buff[i]);
    }
    obj = Mystring{buff};
    delete [] buff;
    return obj;
}

bool operator==(const Mystring &rhs, const Mystring &lhs) {
    return (strcmp(rhs.str, lhs.str) == 0);
}

bool operator!=(const Mystring &rhs, const Mystring &lhs) {
    return !(strcmp(rhs.str, lhs.str) == 0);
}

bool operator>(const Mystring &rhs, const Mystring &lhs) {
    return (strcmp(rhs.str, lhs.str) > 0);
}

bool operator<(const Mystring &rhs, const Mystring &lhs) {
    return (strcmp(rhs.str, lhs.str) < 0);
}
bool operator>=(const Mystring &rhs, const Mystring &lhs) {
    return (strcmp(rhs.str, lhs.str) >= 0);
}

bool operator<=(const Mystring &rhs, const Mystring &lhs) {
    return (strcmp(rhs.str, lhs.str) <= 0);
}

Mystring operator+(const Mystring &rhs, const Mystring &lhs) {
    char *buff = new char[strlen(rhs.str) + strlen(lhs.str) + 1];
    strcpy(buff, rhs.str);
    strcat(buff, lhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
} 

Mystring operator+=(Mystring &rhs, const Mystring &lhs) {
    char *buff = new char[strlen(rhs.str) + strlen(lhs.str) + 1];
    strcpy(buff, rhs.str);
    strcat(buff, lhs.str);
    rhs = Mystring{buff};
    delete [] buff;
    return rhs;
}

Mystring operator*(const Mystring &rhs, const int &lhs) {
    char *buff = new char[strlen(rhs.str)*lhs + 1];
    strcpy(buff, rhs.str);
    for(size_t i{1} ; i < lhs ; ++i) {
        strcat(buff, rhs.str);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring operator*=(Mystring &rhs, const int &lhs) {
    char *buff = new char[strlen(rhs.str)*lhs + 1];
    strcpy(buff, rhs.str);
    for(size_t i{1} ; i < lhs ; ++i) {
        strcat(buff, rhs.str);
    }
    rhs= Mystring{buff};
    delete [] buff;
    return rhs;
}