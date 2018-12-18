#pragma once
enum InputType {LeftArrow, UpArrow, DownArrow, RightArrow, W, A, S, D, SpaceBar, Quit, LeftClick, ENDINPUT};
enum MousePosition {X, Y, ENDMOUSE};
class Inputs
{
public:
	Inputs();
	~Inputs();
	bool GetInput(InputType);
	void SetInput(InputType, bool);
	float GetMousePos(MousePosition);
	void SetMouse(MousePosition, float);
private:
	bool inputList[InputType::ENDINPUT];
	bool mousePos[MousePosition::ENDMOUSE];
};

