#include <iostream>

#include "vec3.hpp"
#include "mat4x4.hpp"

using namespace std;

int main(){
    vec3 v(0, 1, 1);

    cout << v.norm2() << endl;

    vec3 w = v*2;

    cout << w.norm2() << endl;

    mat4x4 M = mat4x4::createTranslationMatrix(2.0, 3.0, 4.0);

    vec3 z = M*w;

    cout << z.norm() << endl;

    return 0;
}