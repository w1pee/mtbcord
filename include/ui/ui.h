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
#ifndef UI_H
#define UI_H
#include <ncurses.h>
#include <ui/events.h>

typedef int ui_bool;

#define UI_TRUE 1
#define UI_FALSE 0

#define MAX_ERRORS 20

/* Error Codes. */
#define UI_OK 0

/* Stores the global state of the ui. */
struct UI_STATE {
    WINDOW *stdscr;
    ui_event_init func_init;
    ui_event_tick func_tick;
};
/* Flags that *have* to be specified before initialisation. */
struct UI_INIT_FLAGS {
    ui_bool cbreak;
    ui_bool echo;
    ui_bool keypad;
    ui_event_init register_event_init;
    ui_event_tick register_event_tick;
};
/* Return type of ui_run_loop. If has_errors is true something did go wrong. */
struct UI_RETURN {
    ui_bool has_errors;
    int message_code;
    int last_error_codes[MAX_ERRORS];
};

/* Initialises the ui framework. */
void ui_init(struct UI_INIT_FLAGS *flags, struct UI_STATE *state);

/* Restore original state. This has to be the last ui_* function call*/
void ui_shutdown(void);

/* Run the main event loop. */
struct UI_RETURN ui_run_loop(struct UI_STATE *state);
#endif // !UI_H
