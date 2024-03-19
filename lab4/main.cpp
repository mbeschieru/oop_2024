
#include "Sort.h"

int main() {
    Sort sort1(10, 10, 25);
    sort1.QuickSort();

    int *a = new int[5]{5, 4, 2, 2, 1};
    Sort sort2(a, 5);
    sort2.BubbleSort(true);

    Sort sort3 = {7,5,5,5,2,9,3,5,1,2,19,20};
    sort3.QuickSort();

    Sort sort4(5,3,6,9,1,2);
    sort4.InsertSort(true);

    Sort sort5("1,3,6,6,6,7,19,22,34,53,11");
    sort5.QuickSort(true);

    std::cout<<sort1.GetElementFromIndex(3)<<" "<<sort1.GetElementsCount();

    return 0;
}
