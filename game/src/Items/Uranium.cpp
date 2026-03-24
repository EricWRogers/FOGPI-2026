#include <Items/Uranium.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>

ScriptConf uraniumConf = {};

void RegisterUraniumScript(App& _app)
{
    DEFAULT_CONFIG_AND_REQUIRED(uraniumConf, Uranium, RectTransform);

    uraniumConf.DEFAULT_DRAW_INSPECTOR(Uranium);

    _app.RegisterScript(uraniumConf);
}

DEFAULT_UNREGISTER_SCRIPT(uraniumConf, Uranium)

void Uranium::Create() {}

void Uranium::Ready() {}

void Uranium::Destroy() {}

void Uranium::Update(float _dt) {}

std::string Uranium::GetName()
{
    return "Uranium";
}
