#include "../namechanger_i.h"
#include <dolphin/dolphin.h>

static void namechanger_scene_save_success_popup_callback(void* context) {
    NameChanger* namechanger = context;
    view_dispatcher_send_custom_event(namechanger->view_dispatcher, NameChangerCustomEventBack);
}

void namechanger_scene_save_success_on_enter(void* context) {
    NameChanger* namechanger = context;
    Popup* popup = namechanger->popup;

    popup_set_icon(popup, 32, 5, &I_DolphinNice_96x59);
    popup_set_header(popup, "Saved!", 5, 7, AlignLeft, AlignTop);

    popup_set_callback(popup, namechanger_scene_save_success_popup_callback);
    popup_set_context(popup, namechanger);
    popup_set_timeout(popup, 5000);
    popup_enable_timeout(popup);

    view_dispatcher_switch_to_view(namechanger->view_dispatcher, NameChangerViewPopup);
}

bool namechanger_scene_save_success_on_event(void* context, SceneManagerEvent event) {
    //UNUSED(context);
    NameChanger* namechanger = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        consumed = true;
        if(event.event == NameChangerCustomEventBack) {
            scene_manager_search_and_switch_to_previous_scene(
                namechanger->scene_manager, NameChangerSceneSaveName);
            //furi_hal_power_reset();
        }
    }

    return consumed;
}

void namechanger_scene_save_success_on_exit(void* context) {
    NameChanger* namechanger = context;
    Popup* popup = namechanger->popup;

    popup_set_text(popup, NULL, 0, 0, AlignCenter, AlignTop);
    popup_set_icon(popup, 0, 0, NULL);

    popup_disable_timeout(popup);
    popup_set_context(popup, NULL);
    popup_set_callback(popup, NULL);
}
