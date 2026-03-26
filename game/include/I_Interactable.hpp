#pragma once
#include <string>

namespace Canis
{
    class Entity;
}

class I_Interactable
{
public:
    virtual ~I_Interactable() = default;
    virtual std::string GetMessage(Canis::Entity* _interactingEntity) = 0;
    virtual bool HandleInteraction(Canis::Entity* _interactingEntity) = 0; // return true if interacted with
};
