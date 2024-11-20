#pragma once

#include <vector>
#include <array>
#include <unordered_map>

#include "item.hpp"



//current implimnetation only works with pointer types
template<typename Element_Type = Item*, std::size_t slots = 30>
class Inventory
{
private:

    std::array<Element_Type, slots> inventory = {};
    
    using Slot = int;
    std::unordered_map<Element_Type, Slot> unique_items;


    std::array<Element_Type, slots>::iterator begin()
    {
        return inventory.begin();
    }

    std::array<Element_Type, slots>::iterator end()
    {
        return inventory.end();
    }

public:
    
    Inventory() = default;

    template<typename T>
    Inventory(const T& elements)
    {
        if(elements.size() > slots)
        {
            //throw error
        }
        
        Slot s = 0;
        for(Element_Type element :  elements)
        {
            if(unique_items.insert({element, s}).second)
                inventory[s++] = element; 
        }
    };


   //returns -1 if no empty slot found, else returns next empty slot
    Slot next_empty(Slot start = 0)
    {
        for(int i = start; i < this->inventory.size(); i++)
        {
            if(!this->inventory[i])
                return i;
        }
        return -1;
    }

    //returns -1 if no occupied slot found, else returns next occupied slot
    Slot next_occupied(Slot start = 0)
    {
        for(int i = start; i < this->inventory.size(); i++)
        {
            if(this->inventory[i])
            {
                return i;
            }
        }
        return -1;
    }

    //place element at postion, postion, returns pointer to item that was already present at that postion or nullptr  
    Element_Type place(Element_Type new_element, Slot s)
    {
        if(this->unique_items.insert({new_element, s}).second)
        {
            Element_Type old_element = remove(s);
            this->inventory[s] = new_element;
            return old_element;
        }

        //item already present throw
        return nullptr;
    }


    //remove element from inventory at specified slot and return it
    Element_Type remove(Slot s)
    {
        Element_Type element = this->inventory[s];
        this->inventory[s] = nullptr;
        this->unique_items.erase(element);
        return element;
    }


    //place all elements in other into empty slots of this inventory. Return true if all elements transfered else return false;
    template<size_t size>
    bool Transfer(Inventory<Element_Type, size>& other)
    {
        Slot this_slot = 0;
        Slot other_slot = 0;
        while(this_slot != -1 || other_slot != -1)
        {
            this_slot = this->next_empty(this_slot);
            other_slot = this->next_occupied(other_slot);
            Element_Type removed_element = other->remove(other_slot);
            this->place(removed_element);
        }

        if(other_slot != -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};