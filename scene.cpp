#include "scene.hpp"

void Scene::AddObject(Object *object)
{
    objects.push_back(object);
}
        
void Scene::Render()
{
    for (Object *object : objects)
    {
        object->Render();
    }
}

void Scene::RemoveLastObject()
{
    if (objects.size() > 0) {
        delete objects.back();
        objects.pop_back();
    }
}