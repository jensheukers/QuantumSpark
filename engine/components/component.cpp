#include "component.h"
#include "entity.h"

void Component::SetOwner(Entity* pOwner) {
	m_eOwner = pOwner;
}

Entity* Component::GetOwner() {
	return m_eOwner;
}