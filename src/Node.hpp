#pragma once
#include <string>
#include "InstanceCounter.hpp"


class Node : public InstanceCounter
{
private:
    // std::string type = "Node";

public:

    virtual std::string print() const = 0;

};