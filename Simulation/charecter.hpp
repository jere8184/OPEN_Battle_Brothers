#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include <map>
#include <set>

#include <vector>

#include "faction.hpp"
#include "item.hpp"
#include "sprite.hpp"
#include "stat.hpp"
#include "inventory.hpp"

struct CharecterInventory
{
    Inventory<EquipableItem*, 0> head_gear;
    Inventory<EquipableItem*, 0> torso_gear;
    Inventory<EquipableItem*, 0> left_hand;
    Inventory<EquipableItem*, 0> right_hand;
    Inventory<EquipableItem*, 0> ammo_pouch;
    Inventory<EquipableItem*, 0> item_pouch;
    Inventory<EquipableItem*, 0> secodary;
};

class Charecter
{
private:
    int id;
    std::string name;
    const Faction* faction;
    CharecterInventory inventory;

    Sprite* face_sprite;
    Sprite* hair_sprite;
    Sprite* scar_sprite;
    Sprite* wounded_1_sprite;
    Sprite* wounded_2_sprite;
    Sprite* wounded_3_sprite;
    Sprite* recovering_sprite;
public:
    Charecter(std::string name, Faction* faction, Sprite* face_sprite, Sprite* hair_sprite, Sprite* wounded_1, Sprite* wounded_2, Sprite* wounded_3);
    
    //set scar sprite
    void add_scar(Sprite* scar);

    //add head gear returns head_gear that was previously being worn
    EquipableItem* change_head_gear(EquipableItem* head_gear);
    EquipableItem* change_torso_gear(EquipableItem* torso_gear);
    EquipableItem* change_left_hand(EquipableItem* left_hand);
    EquipableItem* change_right_hand(EquipableItem* right_hand);
    EquipableItem* change_ammo_pouch(EquipableItem* ammo_pouch);
    EquipableItem* change_item_pouch(EquipableItem* item_pouch);
    EquipableItem* change_secondary(EquipableItem* secodary);


};


struct Wound
{
    int id;
    int days_left;
    std::string name;
    Sprite* icon;
    std::set<Stat> effects;
};

struct PermanentInjury
{
    int id;
    std::string name;
    Sprite* icon;
    std::set<Stat> effects;
};

struct Effect
{
    int id;
    int turns_left;
    std::string name;
    Sprite* icon;
    std::set<Stat> effects;
};





class Deployable_Charecter : Charecter
{
private:


    struct Ability
    {
        std::string name;
        Sprite* icon;
        std::set<Stat> effects;
        Abilities abilites;
    };

    std::vector<std::shared_ptr<const Charecter>> kill_history;
    Stats stats;

    template<typename T>
    struct Compare
    {
        bool operator()(const T& a,  const T& b)
        {
            return a.id < b.id;
        };
    };
    std::set<Wound, Compare<Wound>>  wounds;
    std::set<PermanentInjury, Compare<PermanentInjury>> permanent_injuries;
    std::set<Effect, Compare<Effect>> current_effects;

    
    int level;
    int experice;
public:
    //returns false, if wound already present else returns true;
    bool add_wound(Wound wound);

    

};