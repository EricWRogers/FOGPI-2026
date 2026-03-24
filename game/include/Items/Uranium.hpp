#pragma once
#include <Items/Item.hpp>
#include <Canis/Entity.hpp>

class Uranium : public Canis::ScriptableEntity, public I_Item
{
public:
    static constexpr const char* ScriptName = "Uranium";

    Uranium(Canis::Entity &_entity) : Canis::ScriptableEntity(_entity) {}

    void Create();
    void Ready();
    void Destroy();
    void Update(float _dt);

    std::string GetName() override;
};

extern void RegisterUraniumScript(Canis::App& _app);
extern void UnRegisterUraniumScript(Canis::App& _app);
