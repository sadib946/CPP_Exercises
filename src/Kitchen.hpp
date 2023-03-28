#pragma once
#include "../lib/Unit.hpp"
#include <set>


class Kitchen
{
    public:

    const Unit& register_unit(Unit unit){
        units.insert(std::move(unit));
        return unit;
    }

    const Unit* find_unit(const std::string& name) const
    {
        for (const auto& unit : units){
            if (unit.name == name){
                return &unit;
            }
        }
        return nullptr;
    }


    private:
    std::set<Unit> units;
};