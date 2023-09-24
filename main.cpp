#include <iostream>
#include "Mystring.h"
#include <vector>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

void space(Mystring &&s) {
    cout << "\n=========== " << s << " ===========\n\n";
}

void concatenate(vector<Mystring> &v) {
    Mystring temp{};
    for(size_t i{}; i < v.size() ; ++i) {
        cout << v.at(i) << ((i == (v.size() - 1))?" ":" + ");
        temp += (v.at(i) + " ");
    }
    cout << "= " << temp << endl;
}


int main() {
    cout << boolalpha;
    int num{};
    vector <Mystring> vstring{};
    space(Mystring{"Beginning of the program"});
    cout << "Welcome To Mystring Project" << endl;
    cout << "How many inputs do you want to enter: ";
    cin >> num;
    cout << "Enter your strings seperated by spaces: ";
    for(int i{}; i < num ; ++i) {
        Mystring temp{};
        cin >> temp;
        vstring.push_back(temp);
    }
    
    space(Mystring{"Relational Operators (FIRST AND SECOND STRING ONLY)"});

    cout << "1. Equality" << endl;
    cout << vstring.at(0) << " == " << vstring.at(1) << " = " << (vstring.at(0) == vstring.at(1)) << endl;
    
    cout << "\n2. Not Equality" << endl;
    cout << vstring.at(0) << " != " << vstring.at(1) << " = " << (vstring.at(0) != vstring.at(1)) << endl;
    
    cout << "\n3. Greater Than" << endl;
    cout << vstring.at(0) << " > " << vstring.at(1) << " = " << (vstring.at(0) > vstring.at(1)) << endl;
    
    cout << "\n4. Lower Than" << endl;
    cout << vstring.at(0) << " < " << vstring.at(1) << " = " << (vstring.at(0) < vstring.at(1)) << endl;
    
    cout << "\n5. Greater Than or equal" << endl;
    cout << vstring.at(0) << " >= " << vstring.at(1) << " = " << (vstring.at(0) >= vstring.at(1)) << endl;
    
    cout << "\n6. Lower Than or equal" << endl;
    cout << vstring.at(0) << " <= " << vstring.at(1) << " = " << (vstring.at(0) <= vstring.at(1)) << endl;

    space(Mystring{"Binary Operators"});
    
    cout << "String concatenation" << endl;
    concatenate(vstring);

    cout << "\nString Repeat" << endl;
    int repeattimes{};
    cout << "How many Times do you want to repeat the strings: ";
    cin >> repeattimes;
    for(auto s: vstring) {
        cout << s * repeattimes << endl;
    }

    space(Mystring{"Unary Operators"});
    
    cout << "Pre-increament(makes all letters uppercase)" << endl;
    for(auto s: vstring) {
        ++s;
        cout << s << endl;
    }

    cout << "\nPre-decreament(makes all letters lowercase)" << endl;
    for(auto s: vstring) {
        --s;
        cout << s << endl;
    }

    space(Mystring{"END OF PROGRAM"});

    return 0;
}