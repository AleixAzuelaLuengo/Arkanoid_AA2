#include "Inputs.h"



Inputs::Inputs()
{
}


Inputs::~Inputs()
{
}

bool Inputs::GetInput(InputType type)
{
	return inputList[type];
}

void Inputs::SetInput(InputType type, bool keyDown)
{
	inputList[type] = keyDown;
}

float Inputs::GetMousePos(MousePosition type)
{
	return mousePos[type];
}

void Inputs::SetMouse(MousePosition axis, float num)
{
	mousePos[axis] = num;
}
