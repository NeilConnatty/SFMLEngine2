//
// Created by Neil Connatty on 2016-12-09.
//

#ifndef SFMLENGINE_SETTINGS_STATE_H
#define SFMLENGINE_SETTINGS_STATE_H

#include <array>

#include <gui/container.h>
#include <gui/button.h>
#include <gui/label.h>
#include <player_impl.h>
#include "states/state.h"

class settings_state : public state
{
public:
                        settings_state (state_stack& stack, context cntxt);

    virtual void        draw ();
    virtual bool        update (sf::Time dt);
    virtual bool        handle_event (const sf::Event& event);

private:
    void                update_labels ();
    void                add_button_label (action::ID act, float y, const std::string& text, context cntxt);

private:
    gui::container                                      m_guiContainer;

    std::array<gui::button::ptr, action::ACTION_COUNT>  m_bindingButtons;
    std::array<gui::label::ptr, action::ACTION_COUNT>   m_bindingLabels;

    sf::Sprite                                          m_backgroundSprite;

};


#endif //SFMLENGINE_SETTINGS_STATE_H
