#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>


enum class E_Stat
{
    NOT_SET = 0,
    HEALTH = 1,
    FATIUGE = 2
};

enum class E_Ability
{
    NOT_SET = 0,
    SWAP = 1,
    IORN_LUNGS = 2
};

struct Stat
{
    std::string name;
    int max_value;
    int current_value;
};


using Stats = std::unordered_map<E_Stat, Stat>;
using Abilities = std::unordered_set<E_Ability>;