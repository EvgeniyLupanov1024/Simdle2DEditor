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