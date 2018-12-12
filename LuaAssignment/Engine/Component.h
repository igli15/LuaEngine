//
// Created by Igli milaqi on 04/10/2018.
//

#ifndef SMFLPROJECT_COMPONENT_H
#define SMFLPROJECT_COMPONENT_H

namespace Engine{

    class Entity;
    class Collider;

    class Component {

    protected:
        Entity* m_parent;

    public:
        void SetParent(Entity* entity);
        Entity * Parent() const;
        virtual void Update(float timeStep);
        virtual void Start();
        virtual void OnCollisionEnter(const Collider& other) const;
        virtual ~Component();

    };
}

#endif //SMFLPROJECT_COMPONENT_H
