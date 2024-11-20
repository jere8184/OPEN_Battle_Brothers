

#include "../inventory.hpp"
#include <iostream>

int main()
{
    Inventory<int*, 30> inv;
    int a = 4;
    inv.place(&a, 5);
    inv.remove(4);
    std::cout << inv.next_occupied(0);
};