#include <iostream>
#include "vec3.hpp"

using namespace std;

int main(){
    vec3 v(0, 1, 1);

    cout << v.norm2() << endl;

    vec3 w = v*2;

    cout << w.norm2() << endl;

    return 0;
}