#ifndef OBJECT_HPP
#define OBJECT_HPP

enum class UpdateStatus
{
    Update,
    NotUpdate,
    EndUpdate
};

class Object
{
    public:
        UpdateStatus status = UpdateStatus::Update;
        virtual void Update() = 0;
        virtual void Render() = 0;
};

#endif