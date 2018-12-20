#pragma once

class Inputs
{
public:
	enum InputType { LeftArrow, UpArrow, DownArrow, RightArrow, W, A, S, D, P, SpaceBar, Quit, LeftClick, ENDINPUT };
	enum MousePosition { X, Y, ENDMOUSE };
	Inputs();
	~Inputs();

	bool GetInput(InputType);
	void SetInput(InputType, bool);
	float GetMousePos(MousePosition);
	void SetMouse(MousePosition, float);

private:
	bool inputList[InputType::ENDINPUT];
	float mousePos[MousePosition::ENDMOUSE];
};

