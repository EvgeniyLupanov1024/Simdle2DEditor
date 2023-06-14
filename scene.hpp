#ifndef SCENE_HPP
#define SCENE_HPP

#include "object.hpp"
#include <vector>

using namespace std;

class Scene
{
    private:
        vector<Object*> renderable;
        vector<Object*> updateable;

    public:
        void AddObject(Object *object);
        void RemoveLastObject();
        void Render();
};

#endif