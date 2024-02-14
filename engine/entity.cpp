#include "entity.h"

void Entity::AddComponent(Component* pComponent) {
	m_aComponents.push_back(pComponent);
	pComponent->SetOwner(this);
}

Entity* Entity::GetParent() {
	return m_eParent;
}

void Entity::SetParent(Entity* pParent) {
	m_eParent = pParent;
}

void Entity::AddChild(Entity* pChild) {
	m_aChildren.push_back(pChild);
	pChild->SetParent(this);
}