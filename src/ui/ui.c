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
#include <memory.h>
#include <stdlib.h>
#include <ui/ui.h>

void ui_init(struct UI_INIT_FLAGS *flags, struct UI_STATE *state) {
    memset(state, 0, sizeof(*state));
    state->stdscr = initscr();
    /* Register function pointer */
    state->func_init = flags->register_event_init;
    state->func_tick = flags->register_event_tick;

    /* Activate flags. */
    if (flags->cbreak) {
        cbreak();
    }

    if (flags->echo) {
        echo();
    } else {
        noecho();
    }

    if (flags->keypad) {
        keypad(state->stdscr, UI_TRUE);
    }
}

void ui_shutdown(void) {
    if (endwin() != OK) {
        fprintf(stderr, "Failed to shutdown the ui properly");
    }
}

struct UI_RETURN ui_run_loop(struct UI_STATE *state) {
    // error object
    struct UI_RETURN ret;
    ret.has_errors = UI_FALSE;
    memset(ret.last_error_codes, 0, sizeof(int[MAX_ERRORS]));

    /* Register custom events with ui_event_tick(*function)*/
    ui_bool exit = UI_FALSE;
    while (!exit) {
        ui_internal_event_tick(state);

        /* Refresh screen. */
        refresh();
    }

    return ret;
}
