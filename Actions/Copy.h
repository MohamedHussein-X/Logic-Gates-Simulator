#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"

class Copy : public Action
{
private:

	int Cx, Cy;	//Center point that user clicked .
	Component* Comp;
public:

	virtual ~Copy(void);

	Copy(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};