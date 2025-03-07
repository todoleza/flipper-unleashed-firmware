#pragma once
#include "../lfrfid_app.h"

class LfRfidAppSceneRawRead : public GenericScene<LfRfidApp> {
public:
    void on_enter(LfRfidApp* app, bool need_restore) final;
    bool on_event(LfRfidApp* app, LfRfidApp::Event* event) final;
    void on_exit(LfRfidApp* app) final;

private:
    string_t string_file_name;
    FuriTimer* timer;
    bool is_psk;
    bool error;
};
