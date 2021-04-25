#pragma once

#include "IScene.h"
#include "Shader.h"
#include <unordered_map>
#include <memory>

struct SDL_Window;

class Engine
{
public:
	void Init();
	void Update();
	inline bool IsDone() { return isDone; }

	template <typename Scene>
	void RegisterScene(int index) { scenes[index] = std::make_unique<Scene>(); }
	void SetNextScene(int index) { nextScene = scenes[index].get(); }

	static Shader& GetShader() { return shader; }
private:
	SDL_Window* window{ nullptr };
	void* glContext{ nullptr };
	bool isDone{ false };

	int windowWidth{};
	int windowHeight{};
	int mouseX{};
	int mouseY{};

	std::unordered_map<int, std::unique_ptr<IScene>> scenes;
	IScene* currentScene;
	IScene* nextScene;

	// graphics
	static Shader shader;
};