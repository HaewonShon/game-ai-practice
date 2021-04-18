#pragma once

class IScene
{
public:
	virtual ~IScene() {}
	virtual void Init() = 0;
	virtual void Update(double dt) = 0;
	virtual void DrawObjects() = 0;
	virtual void DrawGUI() = 0;
private:
};