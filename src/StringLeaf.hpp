#pragma once

#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"

class StringLeaf: public Leaf
{
public:
    StringLeaf(std::string data)
        : data_{data}
    {
    };


    std::string data() const
    {
        return data_;
    }


    std::string print() const override
    {
        return '\"' + data() + "\"";
    }


    NodeKind kind() const
    {
        return NodeKind::STRING;
    }

private:
    std::string data_;

};