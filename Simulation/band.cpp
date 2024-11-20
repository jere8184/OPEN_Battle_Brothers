
#include "band.hpp"
#include "utils.hpp"

Band::Band(std::string& name, Sprite* banner, Sprite* map_icon, Faction* faction, std::vector<Item*> starting_items, std::unordered_set<Charecter*> members):
id(Utils::id_generator<Band>()), name(name), banner(banner), map_icon(map_icon), faction(faction), inventory(starting_items), members(members)
{

}
