#ifndef QUANTUMSPARK_ENTITY_H
#define QUANTUMSPARK_ENTITY_H
#include <vector>

#include "components/component.h"
#include "managed.h"

class Entity : Managed {
private:
	std::vector<Component*> m_aComponents;
protected:
	Entity* m_eParent;
	std::vector<Entity*> m_aChildren;
public:
	void AddComponent(Component* pComponent);

	template<class T>
	Component* FindComponent() {
		for (size_t i = 0; i < components.size(); i++) {
			if (dynamic_cast<T*>(components[i])) {
				return components[i]; 
			}
		}

		return nullptr;
	}

	Entity* GetParent();
	void SetParent(Entity* pParent);
	void AddChild(Entity* pChild);
};

#endif // !QUANTUMSPARK_ENTITY_H