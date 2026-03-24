#include <Environment/BoostPad.hpp>
#include <UI/InfoText.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>
#include <RollABall/PlayerController.hpp>

ScriptConf boostPadConf = {};

void RegisterBoostPadScript(App& _app)
{
    REGISTER_PROPERTY(boostPadConf, BoostPad, yeetForce);

    DEFAULT_CONFIG_AND_REQUIRED(boostPadConf, BoostPad, Transform, BoxCollider);

    boostPadConf.DEFAULT_DRAW_INSPECTOR(BoostPad);

    _app.RegisterScript(boostPadConf);
}

DEFAULT_UNREGISTER_SCRIPT(boostPadConf, BoostPad)

void BoostPad::Create() {}

void BoostPad::Ready() {}

void BoostPad::Destroy() {}

void BoostPad::Update(float _dt)
{
    CheckSensorEnter();
}

void BoostPad::CheckSensorEnter()
{
    if (!entity.HasComponents<BoxCollider,Rigidbody>())
        return;

    Entity* collectingPlayer = nullptr;

    for (Entity* other : entity.GetComponent<BoxCollider>().entered)
    {
        if (!other->active)
            continue;

        if (other->HasComponent<Rigidbody>())
        {
            Rigidbody& playerRigidbody = other->GetComponent<Rigidbody>();

            playerRigidbody.AddForce(
                Vector3(0.0f, -playerRigidbody.linearVelocity.y, 0.0f),
                Rigidbody3DForceMode::VELOCITY_CHANGE);

            playerRigidbody.AddForce(
                Vector3(0.0f, yeetForce, 0.0f),
                Rigidbody3DForceMode::IMPULSE);
            
            if (Entity* info = entity.scene.GetEntityWithTag("INFO_TEXT"))
                if (InfoText* infoText = info->GetScript<InfoText>())
                    infoText->SetText("Boost!!!");

            break;
        }
    }
}
