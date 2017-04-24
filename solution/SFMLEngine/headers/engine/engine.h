//
// Created by Neil Connatty on 2016-11-27.
//

#ifndef SFMLENGINE_ENGINE_H
#define SFMLENGINE_ENGINE_H

#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

#include "states/state_stack.h"
#include "player.h"

class engine
{
public:
	// this takes possession on of the player passed in
	engine(std::unique_ptr<player> thePlayer, sf::Time timePerFrame);

	virtual void        run();

private:
	virtual void        register_states() = 0;

	void				process_input();
	void				update(sf::Time dt);
	void				render();

private:
	virtual void		load_textures() = 0;
	virtual void		load_fonts() = 0;

protected:

	state_stack         m_stack;
	
	font_holder         m_fonts;
	texture_holder      m_textures;

private:
	const sf::Time				TIME_PER_FRAME;

	std::unique_ptr<player>		m_player;
	sf::RenderWindow			m_window;
	
	bool						m_isPaused;
};


#endif //SFMLENGINE_APPLICATION_H
