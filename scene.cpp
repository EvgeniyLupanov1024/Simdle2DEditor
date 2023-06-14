#include "scene.hpp"

void Scene::AddObject(Object *object)
{
    renderable.push_back(object);
    if (object->status == UpdateStatus::Update) {
        updateable.push_back(object);
    }
}
        
void Scene::Render()
{
    for (Object *object : renderable)
    {
        object->Render();
    }
}

void Scene::RemoveLastObject()
{
    if (renderable.size() > 0) {
        delete renderable.back();
        renderable.pop_back();
    }
}