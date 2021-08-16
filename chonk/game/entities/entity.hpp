#pragma once

#include <ge/ge.hpp>
#include "../../DEFINITIONS.hpp"

namespace herbglitch {
    class Entity : public ge::Object {
    public:
        Entity(ge::Data *data, EntityType entityType): ge::Object(data, (unsigned int)entityType), select(false){}
        virtual ~Entity(){ delete sprite; }

        virtual void update() = 0;
        virtual void render(){ sprite->draw(data->renderer); }

        void setSelect(bool select = true){ this->select = select; }

        SDL_Rect &getBounds(){ return sprite->getBounds(); }

    protected:
        ge::resource::Sprite *sprite;

        bool select;
    };
}