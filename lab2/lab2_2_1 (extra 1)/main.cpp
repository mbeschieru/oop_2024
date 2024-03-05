#include <iostream>
#include "NumberList.h"
int main() {
    NumberList numberList;
    numberList.Init();
    numberList.Add(5);
    numberList.Add(1);
    numberList.Add(3);
    numberList.Add(6);
    numberList.Add(2);
    std::cout<<"Array before sorting : \n";
    numberList.Print();
    std::cout<<"Array after sorting : \n";
    numberList.Sort();
    numberList.Print();
    return 0;
}
