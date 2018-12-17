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
