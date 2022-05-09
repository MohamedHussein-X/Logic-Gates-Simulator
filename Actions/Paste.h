#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Gate.h"

class Paste : public Action
{
private:
	Component* Comp;		// Pointer to the pasted component
	int Cx, Cy;

public:

	Paste(ApplicationManager* pMan);


	virtual void ReadActionParameters();


	virtual bool Execute();


	virtual void Undo();


	virtual void Redo();


	virtual ~Paste();
};
