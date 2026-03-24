#pragma once
#include <Items/Item.hpp>
#include <Canis/Entity.hpp>

class Rock : public Canis::ScriptableEntity, public I_Item
{
public:
    static constexpr const char* ScriptName = "Rock";

    Rock(Canis::Entity &_entity) : Canis::ScriptableEntity(_entity) {}

    void Create();
    void Ready();
    void Destroy();
    void Update(float _dt);

    std::string GetName() override;
};

extern void RegisterRockScript(Canis::App& _app);
extern void UnRegisterRockScript(Canis::App& _app);
