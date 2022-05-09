#pragma once
#include "Action.h"
#include "..\Components\BUFFER.h"
class D_BUFFER_G :
    public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	D_BUFFER_G(ApplicationManager* pApp);
	virtual ~D_BUFFER_G(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	bool ValidDarwingArea();
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();
};

