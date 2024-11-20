
#include "charecter.hpp"
#include "utils.hpp"

Charecter::Charecter(std::string name, Faction* faction, Sprite* face_sprite, Sprite* hair_sprite) : 
id(Utils::id_generator<Charecter>()), name(name), faction(faction), face_sprite(face_sprite), hair_sprite(hair_sprite)
{

}