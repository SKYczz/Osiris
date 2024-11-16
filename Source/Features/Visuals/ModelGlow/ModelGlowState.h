#pragma once

#include <cstdint>
#include <CS2/Classes/Entities/C_CSPlayerPawn.h>

enum class PlayerModelGlowColorType : std::uint8_t {
    PlayerOrTeamColor,
    TeamColor,
};

struct ModelGlowState {
    enum class State : std::uint8_t {
        Enabled,
        Disabling,
        Disabled
    };

    State masterSwitch{State::Disabled};
    State playerModelGlow{State::Enabled};
    PlayerModelGlowColorType playerModelGlowColorType{PlayerModelGlowColorType::PlayerOrTeamColor};
    bool showOnlyEnemies{true};

    std::uint64_t(*originalPlayerPawnSceneObjectUpdater)(cs2::C_CSPlayerPawn* playerPawn, void*, bool){nullptr};
};