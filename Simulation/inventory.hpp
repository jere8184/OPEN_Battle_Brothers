#pragma once

#include <vector>
#include <array>
#include <unordered_map>
#include <iostream>
#include <optional>






template<typename Storage_Type, std::size_t slots = 30>
class Inventory
{
private:
    using element_t = std::optional<Storage_Type>;
    using array_t = std::array<element_t, slots>;

    array_t m_inventory = {};
    //std::unordered_set<int> m_unique_ids;

    array_t::iterator begin()
    {
        return m_inventory.begin();
    }

    array_t::iterator end()
    {
        return m_inventory.end();
    }

public:
    
    Inventory() = default;

    template<typename Iter>
    Inventory(const Iter& start, const Iter& end)
    {        
        int s = 0;
        for(auto& i = start; i != end ; i++)
        {
            if(s < m_inventory.size() == false)
            {
                break;
            }

            m_inventory[s++] = *i; 
        }
    };


   //returns -1 if no empty slot found, else returns next empty slot
    int next_empty(int start = 0)
    {
        for(int i = start; i < this->inventory.size(); i++)
        {
            if(!this->inventory[i])
            {
                return i;
            }
        }
        return -1;
    }

    //returns -1 if no occupied slot found, else returns next occupied slot
    int next_occupied(int start = 0)
    {
        for(int i = start; i < this->m_inventory.size(); i++)
        {
            if(this->m_inventory[i])
            {
                return i;
            }
        }
        return -1;
    }

    //place element at postion, returns object that was already present at that postion or   
    element_t place(Storage_Type& new_obj, int s)
    {
        element_t old_obj = remove(s);
        this->m_inventory[s] = new_obj;
        return old_obj;
    }


    //remove element from inventory at specified slot and return it
    element_t remove(int s)
    {
        element_t obj = this->m_inventory[s];
        this->m_inventory[s].reset();
        return obj;
    }


    //place all elements in other into empty slots of this inventory. Return true if all elements transfered else return false;
    template<size_t size>
    bool Transfer(Inventory<Storage_Type, size>& other)
    {
        int this_slot = 0;
        int other_slot = 0;
        while(this_slot != -1 || other_slot != -1)
        {
            this_slot = this->next_empty(this_slot);
            other_slot = this->next_occupied(other_slot);
            element_t removed_element = other->remove(other_slot);
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