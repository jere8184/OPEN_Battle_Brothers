#pragma once


#include<set>
#include<list>

#include "location.hpp"
#include "item.hpp"
#include "band.hpp"


class Location;
class Band;

struct QuestStep
{
    enum class StepType
    {
        NOT_SET = 0,
        DISCOVER_LOCATION = 1,
        DESTROY_LOCATION = 2,
        KILL_BAND = 3,
        PROTECT_BAND = 4,
        PROTECT_LOCATION = 5,
        GO_TO_LOCATION = 6
    };

    StepType type;
    Location* location;
    Band* band;
};

class Quest
{
    enum class Difficulty
    {
        NOT_SET = 0,
        EASY = 1,
        MEDIUM = 2,
        HARD = 3,
        BRUTAL = 4, 
    };

    int id;
    Charecter* const patreon;
    Band* const contractor;

    int reward_gold;
    std::set<Item*> reward_items;

    Difficulty diffculty;

    std::set<Location*> locations;
    std::list<QuestStep> steps;
};