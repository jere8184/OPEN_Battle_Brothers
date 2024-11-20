
#include "charecter.hpp"
#include "utils.hpp"

Charecter::Charecter(std::string name, Faction* faction, Sprite* face_sprite, Sprite* hair_sprite, Sprite* wounded_1, Sprite* wounded_2, Sprite* wounded_3) : 
id(Utils::id_generator<Charecter>()), name(name), faction(faction), face_sprite(face_sprite), hair_sprite(hair_sprite), wounded_1_sprite(wounded_1),
wounded_2_sprite(wounded_2), wounded_3_sprite(wounded_3) {}

void Charecter::add_scar(Sprite* scar)
{
    this->scar_sprite = scar;
}

EquipableItem* Charecter::change_head_gear(EquipableItem * head_gear)
{
    return this->inventory.head_gear.place(head_gear, 0);
}

EquipableItem * Charecter::change_torso_gear(EquipableItem * torso_gear)
{
    return this->inventory.torso_gear.place(torso_gear, 0);
}

EquipableItem * Charecter::change_left_hand(EquipableItem * left_hand)
{
    return this->inventory.left_hand.place(left_hand, 0);
}

EquipableItem * Charecter::change_right_hand(EquipableItem * right_hand)
{
    return this->inventory.right_hand.place(right_hand, 0);
}

EquipableItem * Charecter::change_ammo_pouch(EquipableItem * ammo_pouch)
{
    return this->inventory.ammo_pouch.place(ammo_pouch, 0);
}

EquipableItem * Charecter::change_item_pouch(EquipableItem * item_pouch)
{
    return this->inventory.item_pouch.place(item_pouch, 0);
}

EquipableItem * Charecter::change_secondary(EquipableItem * secodary)
{
    return this->inventory.secodary.place(secodary, 0);
}

bool Deployable_Charecter::add_wound(Wound wound)
{
    this->wounds.insert(wound);
    return false;
}
