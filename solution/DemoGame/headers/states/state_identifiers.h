//
// Created by Neil Connatty on 2016-11-27.
//

#ifndef SFMLENGINE_STATE_IDENTIFIERS_H
#define SFMLENGINE_STATE_IDENTIFIERS_H

#include "states/state.h"

namespace states
{

enum ID
{
	TITLE = 0,
	MENU = 1,
	LOADING = 2,
	GAME = 3,
	PAUSE = 4,
	SETTINGS = 5
};

struct title_id : public state_id
{
	ID getID() override
	{
		return TITLE;
	}
};

struct menu_id : public state_id
{
	ID getID() override
	{
		return MENU;
	}
};

struct loading_id : public state_id
{
	ID getID() override
	{
		return LOADING;
	}
};

struct game_id : public state_id
{
	ID getID() override
	{
		return GAME;
	}
};

struct pause_id : public state_id
{
	ID getID() override
	{
		return PAUSE;
	}
};

struct settings_id : public state_id
{
	ID getID() override
	{
		return SETTINGS;
	}
};


} // states

#endif //SFMLENGINE_STATE_IDENTIFIERS_H
