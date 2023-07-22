// mtbcord a terminal based discord client
// Copyright (C) 2023 Motoko Kusanagi (https://github.com/MotokoKusanagii)
// 
//                   GNU GENERAL PUBLIC LICENSE
//                     Version 3, 29 June 2007
//
// This program is free software; you can redistribute it and/or modify it 
// under the terms of the GNU General Public License as published by the Free 
// Software Foundation; version 3 of the License 
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
// FITNESS FOR A PARTICULAR PURPOSE.See the GNU General Public License for more 
// details.
#include <ui/ui.h>
#include <ui/events.h>

void ui_internal_event_tick(struct UI_STATE *state) {
    if (state->func_tick != NULL) {
        state->func_tick(state);
    }
}

void ui_internal_event_init(struct UI_STATE *state) {
    if (state->func_init != NULL) {
        state->func_init(state);
    }
}
