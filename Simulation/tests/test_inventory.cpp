

#include "../inventory.hpp"
#include <iostream>

int main()
{
    Inventory<int*, 30> inv;
    int* a;
    inv.place(a, 5);
    inv.remove(5);
    std::cout << inv.next_occupied(0);
};