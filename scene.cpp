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
        Object *obj = renderable.back();
        if (obj->status == UpdateStatus::EndUpdate) {
            delete obj;
        }

        renderable.pop_back();
    }
}

void Scene::Update()
{
    for (auto iterObj = updateable.begin(); iterObj != updateable.end(); ++iterObj)
    {
        switch ((*iterObj)->status)
        {
        case UpdateStatus::Update:
            (*iterObj)->Update();
            break;

        case UpdateStatus::EndUpdate:
            iterObj = updateable.erase(iterObj);
            break;
        
        default:
            break;
        }
    }
}