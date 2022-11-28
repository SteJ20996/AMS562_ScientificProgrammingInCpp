#include "array.hpp"
#include <iostream>

void test(){
    // set v1 is an array with 100 elements, v2 is half value of v1
    Array v1(200);
    Array v2(200);
    for (unsigned i = 0; i < v1.size(); ++i) {
        v1[i] = i;
        v2[i] = v1[i]/2;
        v1.at(i) = i;
        v2.at(i) = v1.at(i)/2;
    } 
    std::cout << "\n" << "v1 properties:" << std::endl;
    v1.print();

    std::cout << "\n" << "v2 properties:" << std::endl;
    v2.print();
    
    // addition
    Array v_add;
    v_add = v1 + v2;
    std::cout << "\n" << "v1+v2 properties:" << std::endl;
    v_add.print();

    // substraction
    Array v_sub;
    v_sub = v1 - v2;
    std::cout << "\n" << "v1-v2 properties:" << std::endl;
    v_sub.print();

    // try different size
    Array v3(150);
    Array v_add2;
    Array v_sub2;
    Array v_add3;
    Array v_sub3;
    for (unsigned i = 0; i < v3.size(); ++i) {
        v3[i] = i;
        v3.at(i) = i;
    } 
    v_add2 = v_sub + v3;
    std::cout << "\n" << "v1-v2+v3 properties:" << std::endl;
    v_add2.print();

    v_sub2 = v_add - v3;
    std::cout << "\n" << "v1+v2-v3 properties:" << std::endl;
    v_sub2.print();

    v_sub3 = v_sub - v3;
    std::cout << "\n" << "v1-v2-v3 properties:" << std::endl;
    v_sub3.print();

    v_add3 = v_add + v3;
    std::cout << "\n" << "v1+v2+v3 properties:" << std::endl;
    v_add3.print();
    std::cout << std::endl;
}

int main() {
    test();
}
