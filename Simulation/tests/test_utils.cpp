#include "../utils.hpp"

#include <iostream>

int main()
{
    std::cout << Utils::id_generator<int>(5);
    std::cout << Utils::id_generator<int>(1);
    std::cout << Utils::id_generator<int>(1);
    std::cout << Utils::id_generator<long>();

}