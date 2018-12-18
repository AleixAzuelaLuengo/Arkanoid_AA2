#pragma once
#include "Types.h"
class Button
{
public:
	Button();
	~Button();
	void ChangeSurfaceOnSelected(Button button);
	Vector2 GetPosition();
	void SetPosition(Vector2 );
private:
	Rect buttonRect;
	
};

