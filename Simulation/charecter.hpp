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

struct CharecterInventory
{
    std::shared_ptr<EquipableItem> head_gear;
    std::shared_ptr<EquipableItem> torso_gear;
    std::shared_ptr<EquipableItem> left_hand;
    std::shared_ptr<EquipableItem> right_hand;
    std::shared_ptr<EquipableItem> ammo_pouch;
    std::shared_ptr<EquipableItem> item_pouch;
    std::shared_ptr<EquipableItem> secodary;
};

class Charecter
{
    int id;
    std::string name;
    const Faction* faction;
    CharecterInventory inventory;

    Sprite& face_sprite;
    Sprite& hair_sprite;
    Sprite& scar_sprite;
    Sprite& wounded_1_sprite;
    Sprite& wounded_2_sprite;
    Sprite& wounded_3_sprite;
    Sprite& recovering_sprite;
};

class Deployable_Charecter : Charecter
{
    struct Wound
    {
        int days_left;
        std::string name;
        Sprite& icon;
        std::set<Stat> effects;
    };

    struct PermanentInjury
    {
        std::string name;
        Sprite& icon;
        std::set<Stat> effects;
    };

    struct Effect
    {
        int turns_left;
        std::string name;
        Sprite& icon;
        std::set<Stat> effects;
    };

    struct Ability
    {
        std::string name;
        Sprite& icon;
        std::set<Stat> effects;
        Abilities abilites;
    };

    std::vector<std::shared_ptr<const Charecter>> kill_history;
    Stats stats;
    std::set<Wound> wounds;
    std::set<PermanentInjury> permanent_injuries;
    std::set<Effect> current_effects;
};