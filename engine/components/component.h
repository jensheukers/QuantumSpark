#ifndef QUANTUMSPARK_COMPONENT_H
#define QUANTUMSPARK_COMPONENT_H
#include "managed.h"

class Entity; // We need to forwardly declare entity class.

class Component : Managed {
protected:
	Entity* m_eOwner;
public:
	void SetOwner(Entity* pOwner);
	Entity* GetOwner();
};

#endif // !QUANTUMSPARK_COMPONENT_H