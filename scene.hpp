#ifndef SCENE_HPP
#define SCENE_HPP

#include "object.hpp"
#include <vector>
#include <list>

using namespace std;

class Scene
{
    private:
        vector<Object*> renderable;
        list<Object*> updateable;

    public:
        void AddObject(Object *object);
        void RemoveLastObject();
        void Render();
        void Update();
};

#endif