#pragma once

#include <list>
#include "GameObject.h"

class GameObjectManager
{
public:
	~GameObjectManager();
	void AddGameObject(GameObject* obj) noexcept;
	void Update(float dt) noexcept;
	void Draw() noexcept;
	void Clear() noexcept;

	GameObject* Find(const std::string& objectName) noexcept;
private:
	std::list<GameObject*> objectList;
};