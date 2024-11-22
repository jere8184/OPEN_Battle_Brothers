#include "diplomacy.hpp"

bool Diplomacy::is_hostile(Band *other_band)
{
    if(this->band_relationship[other_band] <= (int)relationship_status::hostile)
    {
        return true;
    }
    else
    {
        return false;
    }
}