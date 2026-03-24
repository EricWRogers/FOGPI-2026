#include <Items/Gold.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>


ScriptConf goldConf = {};

void RegisterGoldScript(App& _app)
{
    DEFAULT_CONFIG_AND_REQUIRED(goldConf, Gold, RectTransform);

    goldConf.DEFAULT_DRAW_INSPECTOR(Gold);

    _app.RegisterScript(goldConf);
}

DEFAULT_UNREGISTER_SCRIPT(goldConf, Gold)

void Gold::Create() {}

void Gold::Ready() {}

void Gold::Destroy() {}

void Gold::Update(float _dt) {}

std::string Gold::GetName() {
    return "Gold";
}