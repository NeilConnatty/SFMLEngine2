//
// Created by Neil Connatty on 2016-11-25.
//

#ifndef SFMLENGINE_PLAYERIMPL_H
#define SFMLENGINE_PLAYERIMPL_H

#include "player.h"
#include "commands/action.h"

#define PLAYER_SPEED 200.f

class player_impl : public player
{
public:
	player_impl();

	void                assign_key(action::ID act, sf::Keyboard::Key key);
	sf::Keyboard::Key   get_assigned_key(action::ID act) const;

	void				handle_event(const sf::Event& event, command_queue& commands) override;
	void				handle_realtime_input(command_queue& commands) override;


private:
	static bool         is_realtime_action(action::ID act);
	void                initialize_actions();

private:
	std::map<sf::Keyboard::Key, action::ID>     m_keyBinding;
	std::map<action::ID, command>               m_actionBinding;
};


#endif //SFMLENGINE_PLAYERIMPL_H
