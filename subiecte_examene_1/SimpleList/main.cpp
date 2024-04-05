#include <iostream>
#include "SimpleList.h"

using namespace std;

int main() {
    SimpleList<int> l = {1, 3, 5, 7, 9};
    for (auto i: l) {
        cout << i << " ";
        cout << endl;
    }
    return 0;
}
