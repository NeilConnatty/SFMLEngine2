//
// Created by Neil Connatty on 2016-11-27.
//

#include <states/title_state.h>
#include <states/menu_state.h>
#include <states/game_state.h>
#include <states/pause_state.h>
#include <states/loading_state.h>
#include <states/settings_state.h>
#include "application.h"
#include "states/state.h"
#include "states/state_stack.h"

application::application () :
        engine()
{
	load_textures();
	load_fonts();

	register_states();
	m_stack.push_state(states::TITLE);
}

void application::run()
{
	engine::run();
}

void application::register_states ()
{
    m_stack.register_state<title_state>(states::TITLE);
    m_stack.register_state<menu_state>(states::MENU);
    m_stack.register_state<game_state>(states::GAME);
    m_stack.register_state<pause_state>(states::PAUSE);
    m_stack.register_state<loading_state>(states::LOADING);
    m_stack.register_state<settings_state>(states::SETTINGS);
}

void application::load_textures ()
{
    std::string path(PATH_TO_PROJECT_ROOT);
    m_textures.load(textures::EAGLE, path.append("assets/textures/Eagle.png"));
    path.assign(PATH_TO_PROJECT_ROOT);
    m_textures.load(textures::RAPTOR, path.append("assets/textures/Raptor.png"));
    path.assign(PATH_TO_PROJECT_ROOT);
    m_textures.load(textures::DESERT, path.append("assets/textures/Desert.png"));
    path.assign(PATH_TO_PROJECT_ROOT);
    m_textures.load(textures::TITLE_SCREEN, path.append("assets/textures/TitleScreen.png"));
    path.assign(PATH_TO_PROJECT_ROOT);
    m_textures.load(textures::BUTTON_NORMAL, path.append("assets/textures/ButtonNormal.png"));
    path.assign(PATH_TO_PROJECT_ROOT);
    m_textures.load(textures::BUTTON_PRESSED, path.append("assets/textures/ButtonPressed.png"));
    path.assign(PATH_TO_PROJECT_ROOT);
    m_textures.load(textures::BUTTON_SELECTED, path.append("assets/textures/ButtonSelected.png"));
}

void application::load_fonts ()
{
    std::string path(PATH_TO_PROJECT_ROOT);
    m_fonts.load(fonts::DEFAULT, path.append("assets/Sansation.ttf"));
}
