#pragma once
#include <Items/Item.hpp>
#include <Canis/Entity.hpp>

class Gold : public Canis::ScriptableEntity, public I_Item
{
private:

public:
    static constexpr const char* ScriptName = "Gold";

    Gold(Canis::Entity &_entity) : Canis::ScriptableEntity(_entity) {}

    void Create();
    void Ready();
    void Destroy();
    void Update(float _dt);

    std::string GetName() override;
};

extern void RegisterGoldScript(Canis::App& _app);
extern void UnRegisterGoldScript(Canis::App& _app);