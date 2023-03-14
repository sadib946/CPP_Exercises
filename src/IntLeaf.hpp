#pragma once
#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"

class IntLeaf: public Leaf
{
public:
    IntLeaf(int data)
        : data_{data}
    {
    };


    int data() const
    {
        return data_;
    }


    std::string print() const
    {
        return std::to_string(data_);
    }
    

    NodeKind kind() const
    {
        return NodeKind::INT;
    }

private:
    int data_;

};