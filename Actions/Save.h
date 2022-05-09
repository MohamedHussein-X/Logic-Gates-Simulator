#pragma once

#include "..\ApplicationManager.h"
#include "Action.h"
#include <fstream>

class Save :
    public Action
{
private:
	ofstream WriteFile;

public:
	/* Constructor */
	Save(ApplicationManager* APM);
	virtual void ReadActionParameters();
	virtual bool Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Save();

};

