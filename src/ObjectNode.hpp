#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

class ObjectNode : public Node
{
public:
    ObjectNode() = default;

    virtual NodeKind kind() const
    {
        return NodeKind::OBJECT;
    }

    virtual std::string print() const override
    {
        return "{}";
    }
};
