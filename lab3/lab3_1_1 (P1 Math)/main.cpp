#include <iostream>
#include "Math.h"

int main() {
    std::cout << Math::Add(1, 2) << std::endl;
    std::cout << Math::Add(1, 2, 3) << std::endl;
    std::cout << Math::Add(1.0, 2.0) << std::endl;
    std::cout << Math::Add(1.0, 2.0, 3.0) << std::endl;


    std::cout << Math::Mul(1, 2) << std::endl;
    std::cout << Math::Mul(1, 2, 3) << std::endl;
    std::cout << Math::Mul(1.0, 2.0) << std::endl;
    std::cout << Math::Mul(1.0, 2.0, 3.0) << std::endl;

    std::cout << Math::Add(3, 1, 2, 3) << std::endl;

    std::cout << Math::Add("ana", " are mere");

    return 0;
}
