#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"

class Delete : public Action
{
private:
	Component** DeletedComps;
	Connection** Connections;
	int Cx, Cy;


public:

	Delete(ApplicationManager* pApp);


	virtual void ReadActionParameters();


	virtual bool Execute();


	virtual void Undo();


	virtual void Redo();


	virtual ~Delete();
};
