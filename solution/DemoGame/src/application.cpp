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
#include "states/state_identifiers.h"

application::application () :
        engine(std::make_unique<player_impl>(), sf::seconds(1.f / 60.f))
{
	load_textures();
	load_fonts();

	register_states();
	m_stack.push_state(states::title_id());
}

void application::register_states ()
{
    m_stack.register_state<title_state>(states::title_id());
    m_stack.register_state<menu_state>(states::menu_id());
    m_stack.register_state<game_state>(states::game_id());
    m_stack.register_state<pause_state>(states::pause_id());
    m_stack.register_state<loading_state>(states::loading_id());
    m_stack.register_state<settings_state>(states::settings_id());
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

