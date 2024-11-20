#pragma once

#include <string>
#include <unordered_set>
#include <unordered_map>

#include "map.hpp"
#include "faction.hpp"
#include "location.hpp"
#include "map"
#include "sprite.hpp"
#include "quest.hpp"
#include "charecter.hpp"
#include "inventory.hpp"
#include "diplomacy.hpp"




enum class FameLevel 
{
    NOT_SET = 0,
};

enum class ReputationLevel 
{
    NOT_SET = 0,
};


class Band
{
    int id;
    std::string name = "NOT_SET";
    const Sprite* banner;
    const Sprite* map_icon;
    
    Coordinate map_postion;


    int fame_val = 0;
    FameLevel fame_level = FameLevel::NOT_SET;   
    
    int reputation_val = 0;
    ReputationLevel reputation_level = ReputationLevel::NOT_SET;

    std::unordered_set<Charecter*> members;
    Diplomacy diplomacy;
    Inventory<Item> inventory;
};


class PlayerBand : Band
{
    int gold = 0;
    int food = 0;
    int supplies = 0;
    int medicen = 0;

    Inventory<Deployable_Charecter> fighters;
    Inventory<Deployable_Charecter> reserve;

    std::unordered_set<Charecter*> auxiliaries;
    std::unordered_map<Charecter*, int> wage;
};