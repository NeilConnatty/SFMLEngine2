//
// Created by Neil Connatty on 2016-11-27.
//

#ifndef SFMLENGINE_APPLICATION_H
#define SFMLENGINE_APPLICATION_H

#include "engine.h"

#define PATH_TO_PROJECT_ROOT "../../"

class application : public engine
{
public:
                        application ();
	void				run() override;

private:
    void                register_states () override;
    void                load_textures () override;
    void                load_fonts () override;

private:
};


#endif //SFMLENGINE_APPLICATION_H
