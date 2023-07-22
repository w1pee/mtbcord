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
#ifndef EVENTS_H
#define EVENTS_H

/* Forward declaration. */
struct UI_STATE;
struct UI_RETURN;

typedef void (*ui_event_init)(struct UI_STATE *);
typedef void (*ui_event_tick)(struct UI_STATE *);

void ui_internal_event_init(struct UI_STATE *state);
void ui_internal_event_tick(struct UI_STATE *state);

#endif // !EVENTS_H
