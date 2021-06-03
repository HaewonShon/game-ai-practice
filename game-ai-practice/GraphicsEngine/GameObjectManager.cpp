#include "GameObjectManager.h"

GameObjectManager::~GameObjectManager()
{
	Clear();
}

void GameObjectManager::AddGameObject(GameObject* obj) noexcept
{
	objectList.push_back(obj);
}

void GameObjectManager::Update(float dt)
{
	std::vector<GameObject*> toDelete;
	for (GameObject*& object : objectList)
	{
		object->Update(dt);
		if (object->IsDead())
		{
			toDelete.push_back(object);
		}
	}

	for (GameObject*& object : toDelete)
	{
		objectList.remove(object);
		delete object;
	}
}

void GameObjectManager::Draw() noexcept
{
	for (GameObject*& object : objectList)
	{
		object->Draw();
	}
}

void GameObjectManager::Clear() noexcept
{
	for (GameObject*& object : objectList)
	{
		delete object;
	}
	objectList.clear();
}

GameObject* GameObjectManager::Find(const std::string& objectName) noexcept
{
	for (GameObject* object : objectList)
	{
		if (object->GetName() == objectName)
		{
			return object;
		}
	}
	return nullptr;
}