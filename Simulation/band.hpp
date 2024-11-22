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
private:
    int id;
    std::string name = "NOT_SET";
    const Sprite* banner;
    const Sprite* map_icon;
    
    Coordinate map_postion;
    int speed;
    static const float ENGAGMENT_DISTANCE = 20;

    int fame_val = 0;
    FameLevel fame_level = FameLevel::NOT_SET;   
    
    int reputation_val = 0;
    ReputationLevel reputation_level = ReputationLevel::NOT_SET;

    std::unordered_set<Deployable_Charecter*> fighters;
    Diplomacy diplomacy;
    Inventory<Item*> inventory;
    Faction* faction;
    


public:
    Band(std::string& name, Sprite* banner, Sprite* map_icon, Faction* faction, std::vector<Item*> starting_items, std::unordered_set<Charecter*> members);
    bool add_fighter(Deployable_Charecter* fighter);
    Inventory<Item*>& get_inventory();
    void set_postion(Coordinate map_postion);
    void move_towards(Coordinate map_postion);
    void move_away(Coordinate map_postion);
    void set_speed(int speed);
    void adjust_speed(float modifier);
    void Interact(Interactable* other_band); 
};


class PlayerBand : Band
{
    int gold = 0;
    int food = 0;
    int supplies = 0;
    int medicen = 0;

    //Inventory<Deployable_Charecter> reserve;

    std::unordered_set<Charecter*> auxiliaries;
    std::unordered_map<Charecter*, int> wage;


};