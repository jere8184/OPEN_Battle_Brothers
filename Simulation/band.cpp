
#include "band.hpp"
#include "utils.hpp"

Band::Band(std::string& name, Sprite* banner, Sprite* map_icon, Faction* faction, std::vector<Item*> starting_items, std::unordered_set<Charecter*> members):
id(Utils::id_generator<Band>()), name(name), banner(banner), map_icon(map_icon), faction(faction), inventory(starting_items), members(members)
{

}

bool Band::add_fighter(Deployable_Charecter * fighter)
{
    return fighters.insert(fighter).second;
}

void Band::move_away(Coordinate map_postion, float speed)
{
    Coordinate a =  this->map_postion - map_postion;
    float magnitude = a.calculate_magnitude();
    this->map_postion = this->map_postion + a / magnitude * speed;
}


void Band::move_towards(Coordinate target_postion, float speed)
{
    Coordinate a = target_postion - this->map_postion;
    float magnitude = a.calculate_magnitude();
    if (magnitude <= speed || magnitude == 0f)
    {
        this->map_postion = target_postion;
    }
    this->map_postion = this->map_postion + a / magnitude * speed;
}

void Band::attack(Band* other_band)
{
    //fight
}

void Band::attack(Location* location)
{
    //fight
}

void Band::enter_location(Location* Location)
{
    //enter location
}

void Band::interact_with(Band* other_band)
{
    if(this->diplomacy->is_hostile(other_band))
}
