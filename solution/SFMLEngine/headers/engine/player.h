//
// Created by Neil Connatty on 2016-11-25.
//

#ifndef SFMLENGINE_PLAYER_H
#define SFMLENGINE_PLAYER_H

#include "commands/command_queue.h"
#include "commands/command.h"

class player
{
public:
	virtual void		handle_event(const sf::Event& event, command_queue& commands) = 0;
	virtual void		handle_realtime_input(command_queue& commands) = 0;    
};


#endif //SFMLENGINE_PLAYER_H
