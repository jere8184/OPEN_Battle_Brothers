#pragma once



#include <string>
#include <memory>

#include "sprite.hpp"
#include "stat.hpp"




class Item
{
    int id; 

    std::string name = "NOT_SET";
    std::string desc = "NOT_SET";
    Sprite& inventory_icon;
    int quantity;
};


struct Augmentation : Item
{
    Sprite augmentation_sprite;
};

class EquipableItem: Item
{
    bool helmet = false;
    bool torso = false;
    bool single_handed = false;
    bool double_handed = false;
    bool ammo_pouch = false;
    bool item_pouch = false;
    bool secondary_slot = false;

    std::shared_ptr<Augmentation> augmentation;
    Sprite* equiped_sprite;
    Sprite* damaged_1_sprite;
    Sprite* damaged_2_sprite;


    Stats stats;
};


class Weapon: EquipableItem
{
    int range;
};

class RangedWeapon: Weapon
{
    //std::unordered_set<EquipableItem*> valid_ammunition;
};
