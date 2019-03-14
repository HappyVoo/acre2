#include "script_component.hpp"

class CfgWeapons {
    class CBA_MiscItem;
    class CBA_MiscItem_ItemInfo;

    class ACRE_VHF30108: CBA_MiscItem {
        author[] = {"RanTa"};
        scope = 2;
        displayName = "VHF30108 GSM";
        descriptionShort = "VHF30108 Ground Spike Antenna with Mast";
        model = QPATHTOF(data\models\acre_antennaBag.p3d);
        //picture = QPATHTOF(data\icons\icon_rf3080.paa);
        //editorPreview = QPATHTOF(data\icons\icon_rf3080.paa);

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 58;
        };
    };
    class ACRE_VHF30108SPIKE: CBA_MiscItem {
        author[] = {"RanTa"};
        scope = 2;
        displayName = "VHF30108 GS";
        descriptionShort = "VHF30108 Ground Spike Antenna";
        model = QPATHTOF(data\models\acre_antennaBag.p3d);
        //picture = QPATHTOF(data\icons\icon_rf3080.paa);
        //editorPreview = QPATHTOF(data\icons\icon_rf3080.paa);

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 58;
        };
    };

    class ACRE_VHF30108MAST: CBA_MiscItem {
        author[] = {"RanTa"};
        scope = 2;
        displayName = "VHF30108 Mast";
        descriptionShort = "VHF30108 Mast";
        model = QPATHTOF(data\models\acre_antennaBag.p3d);
        //picture = QPATHTOF(data\icons\icon_rf3080.paa);
        //editorPreview = QPATHTOF(data\icons\icon_rf3080.paa);

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 58;
        };
    };
};
