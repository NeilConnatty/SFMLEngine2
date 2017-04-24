
#include <scene/aircraft.h>

#include "player_impl.h"

struct aircraft_mover
{
	aircraft_mover(float vx, float vy)
		: velocity(vx, vy)
	{
	}

	void operator () (aircraft& craft, sf::Time dt) const
	{
		craft.accelerate(velocity);
	}

	sf::Vector2f velocity;
};

player_impl::player_impl() :
	player()
{
	m_keyBinding[sf::Keyboard::Left] = action::MOVE_LEFT;
	m_keyBinding[sf::Keyboard::Right] = action::MOVE_RIGHT;
	m_keyBinding[sf::Keyboard::Up] = action::MOVE_UP;
	m_keyBinding[sf::Keyboard::Down] = action::MOVE_DOWN;

	initialize_actions();

	for (auto& pair : m_actionBinding)
	{
		pair.second.category = category::PLAYER_AIRCRAFT;
	}
}

void player_impl::initialize_actions()
{
	const float playerSpeed = PLAYER_SPEED;

	m_actionBinding[action::MOVE_LEFT].action = derived_action<aircraft>(aircraft_mover(-playerSpeed, 0.f));
	m_actionBinding[action::MOVE_RIGHT].action = derived_action<aircraft>(aircraft_mover(playerSpeed, 0.f));
	m_actionBinding[action::MOVE_UP].action = derived_action<aircraft>(aircraft_mover(0.f, -playerSpeed));
	m_actionBinding[action::MOVE_DOWN].action = derived_action<aircraft>(aircraft_mover(0.f, playerSpeed));
}

void player_impl::handle_event(const sf::Event &event, command_queue &commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		auto found = m_keyBinding.find(event.key.code);
		if (found != m_keyBinding.end() && !is_realtime_action(found->second))
			commands.push(m_actionBinding[found->second]);
	}
}

void player_impl::handle_realtime_input(command_queue &commands)
{
	for (auto pair : m_keyBinding)
	{
		if (sf::Keyboard::isKeyPressed(pair.first) && is_realtime_action(pair.second)) {
			commands.push(m_actionBinding[pair.second]);
		}
	}
}

void player_impl::assign_key(action::ID act, sf::Keyboard::Key key)
{
	// remove all keys that already map to action
	for (auto itr = m_keyBinding.begin(); itr != m_keyBinding.end(); )
	{
		if (itr->second == act) {
			m_keyBinding.erase(itr++);
		}
		else {
			++itr;
		}
		// insert new binding
		m_keyBinding[key] = act;
	}
}

sf::Keyboard::Key player_impl::get_assigned_key(action::ID act) const
{
	for (auto pair : m_keyBinding)
	{
		if (pair.second == act) {
			return pair.first;
		}
	}

	return sf::Keyboard::Unknown;
}

bool player_impl::is_realtime_action(action::ID act)
{
	using namespace action;

	switch (act)
	{
	case MOVE_DOWN:
	case MOVE_RIGHT:
	case MOVE_UP:
	case MOVE_LEFT:
		return true;

	default:
		return false;
	}
}