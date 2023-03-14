#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

class ArrayNode : public Node
{
public:
    ArrayNode() = default;
    
    virtual NodeKind kind() const
    {
        return NodeKind::ARRAY;
    }

    virtual std::string print() const override
    {
        return "[]";
    }
};