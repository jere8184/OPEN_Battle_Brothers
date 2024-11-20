#pragma once

#include <unordered_map>


#include "item.hpp"

template<typename Stored_Type = Item>
class Inventory
{
    using Slot = int;
    using Stored_Type = Stored_Type;

    int size;
    std::unordered_map<Slot, Stored_Type*> inventory;
};