//
// Created by Neil Connatty on 2016-11-03.
//

#ifndef SFMLENGINE_AIRCRAFT_H
#define SFMLENGINE_AIRCRAFT_H

#include "scene/entity.h"
#include <SFML/Graphics.hpp>
#include "resources/textures.h"
#include "scene/category.h"

class aircraft : public entity
{
public:
    enum type 
	{
        EAGLE,
        RAPTOR,
    };

public:
    explicit                    aircraft (aircraft::type m_type, const texture_holder &textures);

    virtual void                draw_current (sf::RenderTarget &target, sf::RenderStates states) const;
    virtual unsigned int        get_category () const;

private:
    type                        m_type;
    sf::Sprite                  m_sprite;
};


#endif //SFMLENGINE_AIRCRAFT_H
