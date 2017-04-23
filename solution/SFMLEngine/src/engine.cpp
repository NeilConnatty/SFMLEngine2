//
// Created by Neil Connatty on 2016-11-27.
//

#include <states/title_state.h>
#include <states/menu_state.h>
#include <states/game_state.h>
#include <states/pause_state.h>
#include <states/loading_state.h>
#include <states/settings_state.h>
#include "engine.h"
#include "states/state.h"
#include "states/state_stack.h"

engine::engine() :
	m_window(sf::VideoMode(640, 480), "SFML Application"),
	m_player(),
	m_fonts(),
	m_textures(),
	m_stack(state::context(m_window, m_textures, m_fonts, m_player)),
	TIME_PER_FRAME(sf::seconds(1.f / 60.f))
{
	m_window.setKeyRepeatEnabled(false);
}

void engine::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			timeSinceLastUpdate -= TIME_PER_FRAME;

			process_input();
			update(TIME_PER_FRAME);

			if (m_stack.is_empty())
				m_window.close();
		}

		render();
	}
}

void engine::process_input()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		m_stack.handle_event(event);

		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

void engine::update(sf::Time dt)
{
	m_stack.update(dt);
}

void engine::render()
{
	m_window.clear();

	m_stack.draw();

	m_window.setView(m_window.getDefaultView());

	m_window.display();
}
