#pragma once

#include <unordered_map>


#include "band.hpp"
#include "charecter.hpp"
#include "location.hpp"


class Diplomacy
{
private:
    std::unordered_map<Band*, int> band_relationship;
    std::unordered_map<Charecter*, int> charecter_relationship;
    std::unordered_map<Location*, int> location_relationship;
    enum class relationship_status
    {
        hostile = -20,
        neutral = 0,
        friends = 20,
        good_friends = 40,
        allies = 60
    };

    bool is_hostile(Band* other_band);
    
};