#include "Button.h"



Button::Button()
{
}


Button::~Button()
{
}

void Button::ChangeSurfaceOnSelected(Button button)
{
}

Vector2 Button::GetPosition()
{
	return buttonRect.position;
}

void Button::SetPosition(Vector2 newPos)
{
	buttonRect.position = newPos;
}
