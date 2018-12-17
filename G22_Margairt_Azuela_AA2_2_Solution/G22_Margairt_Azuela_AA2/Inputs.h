#pragma once
enum InputType { LeftClick, UpArrow, DownArrow, W, S, SpaceBar, END};
class Inputs
{
public:
	Inputs();
	~Inputs();
	bool GetInput(InputType);
	void SetInput(InputType, bool);
private:
	bool inputList[InputType::END];
};

