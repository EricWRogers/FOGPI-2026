#pragma once
#include <I_Interactable.hpp>
#include <SuperPupUtilities/I_Item.hpp>
#include <Canis/Entity.hpp>

class Uranium : public Canis::ScriptableEntity, public SuperPupUtilities::I_Item, public I_Interactable
{
public:
    static constexpr const char* ScriptName = "Uranium";

    Uranium(Canis::Entity &_entity) : Canis::ScriptableEntity(_entity) {}

    void Create();
    void Ready();
    void Destroy();
    void Update(float _dt);

    // SuperPupUtilities::I_Item
    std::string GetName() override;

    // I_Interactable
    std::string GetMessage(Canis::Entity* _interactingEntity) override;
    bool HandleInteraction(Canis::Entity* _interactingEntity) override;
};

extern void RegisterUraniumScript(Canis::App& _app);
extern void UnRegisterUraniumScript(Canis::App& _app);
