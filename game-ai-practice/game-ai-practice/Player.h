#pragma once

#include "../GraphicsEngine/GameObject.h"

// will move with W/S, rotate with A/D
//06/05 TODO : implement inputs

class Player : public GameObject
{
public:
	Player(vec2 pos);
	void Update(float dt) override;
	void Draw() override;

private:
	
};