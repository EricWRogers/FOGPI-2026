#include <Environment/IceBlock.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>
#include <Canis/InputManager.hpp>

ScriptConf iceBlockConf = {};

void RegisterIceBlockScript(App& _app)
{
    DEFAULT_CONFIG(iceBlockConf, IceBlock);
    REGISTER_PROPERTY(iceBlockConf, IceBlock, dropPrefab);

    iceBlockConf.DEFAULT_DRAW_INSPECTOR(IceBlock);

    _app.RegisterScript(iceBlockConf);
}

DEFAULT_UNREGISTER_SCRIPT(iceBlockConf, IceBlock)

void IceBlock::Create() {}

void IceBlock::Ready() {}

void IceBlock::Destroy() {}

void IceBlock::Update(float _dt) {}

std::string IceBlock::GetName()
{
    return "Ice Block";
}

std::string IceBlock::GetMessage(Canis::Entity* _interactingEntity)
{
    return std::string("Left Click to Break ") + GetName();
}

bool IceBlock::HandleInteraction(Canis::Entity* _interactingEntity)
{
    InputManager& input = entity.scene.GetInputManager();
    if (!input.LeftClickReleased())
        return false;

    const Vector3 spawnOffset = entity.HasComponent<Transform>()
        ? entity.GetComponent<Transform>().GetGlobalPosition()
        : Vector3(0.0f);
    Scene& scene = entity.scene;

    entity.Destroy();

    for (Entity *root : scene.Instantiate(dropPrefab))
    {
        if (root != nullptr && root->HasComponent<Transform>())
            root->GetComponent<Transform>().position += spawnOffset;
    }

    return true;
}
