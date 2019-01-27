#include "script_component.hpp"
/*
 * Author: ACRE2Team
 * Handles turning the intercom knob.
 *
 * Arguments:
 * 0: Unused
 * 1: Key direction. O: left, 1: right <NUMBER>
 *
 * Return Value:
 * RETURN VALUE <TYPE>
 *
 * Example:
 * [idc, 0] call acre_sys_intercom_fnc_vic3ffcsOnIntercomKnobPress
 *
 * Public: No
 */

params ["", "_key"];

private _currentDirection = -1;
if (_key == 0) then {
    // Left click
    _currentDirection = 1;
};

private _vehicle = vehicle acre_player;
private _intercomPos = [_vehicle, acre_player, GVAR(activeIntercom), "intercomKnob"] call FUNC(getStationConfiguration);
private _newIntercomPos = ((_intercomPos + _currentDirection) max 0) min 3;

if (_newIntercomPos != _intercomPos) then {
    [_vehicle, acre_player, GVAR(activeIntercom), "intercomKnob", _newIntercomPos] call FUNC(setStationConfiguration);

    if (_intercomPos > 1) then {
        _intercomPos = 1;  // VOX and O/R are not supported at the moment in the UI. O/R is supported through keybind
    };

    [_vehicle, acre_player, GVAR(activeIntercom), "voiceActivation", _intercomPos == 1] call FUNC(setStationConfiguration);

    [MAIN_DISPLAY] call FUNC(vic3ffcsRender);
};
