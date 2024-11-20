#pragma once

#include <string>
#include <set>


#include "charecter.hpp"
#include "inventory.hpp"
#include "quest.hpp"
#include "faction.hpp"


enum class Size
{
    NOT_SET = 0,
};


enum class Affects
{
    NOT_SET = 0,
};

enum class Type
{
    NOT_SET = 0,
};


class Store
{
    Charecter* owner;
    Inventory<> inventory;
    std::unordered_map<Item, float> price_modifications;
};

class Location
{
    int id;
    std::string name;
    Size size;
    Affects status;

    std::set<Charecter*> potential_recruits;
    std::set<Charecter*> notables;
    std::set<Store*> stores;
    std::set<Quest*> quests;
    std::set<Location*> sub_locations;
    Faction* faction;

    //Tile& postion;
};