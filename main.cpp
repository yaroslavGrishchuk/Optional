#include <iostream>

#include<iostream>
#include "optional.h"


using namespace std;

int main(){
    optional<double> a(4.1);
    optional<int> b(4);

    /*cout << "swap\n";
    if (a){
        cout << 'a' << *a << endl;
    }
    if (b){
        cout << 'b' << *b << endl;
    }
    swap(a, b);
    cout << endl;
    if (a){
        cout << 'a' << *a << endl;
    }
    if (b){
        cout << 'b' << *b << endl;
    }

    b = 2;
    cout << "clear\n";
    if (a){
        cout << 'a' << *a << endl;
    }
    if (b){
        cout << 'b' << *b << endl;
    }
    b.clear();
    cout << endl;
    if (a){
        cout << 'a' << *a << endl;
    }
    if (b){
        cout << 'b' << *b << endl;
    }
    cout << endl;

    cout << "* and =\n";
    b = 3;
    a = b;
    (*a)++;

    if (a){
        cout << 'a' << *a << endl;
    }
    if (b){
        cout << 'b' << *b << endl;
    }*/

    cout << (a == b) << " " << (a < b) << " " << (a >= b);

}
