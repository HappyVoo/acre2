#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if (hasInterface) then {
    DGVAR(showSignalHint) = false;
    DGVAR(terrainScaling) = 1;
    DGVAR(omnidirectionalRadios) = 0;
    DGVAR(signalModel) = SIGNAL_MODEL_LOS_MULTIPATH;
};

// CBA Settings
#include "initSettings.sqf"

ADDON = true;
