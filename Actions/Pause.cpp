#include "Pause.h"
#include "..\ApplicationManager.h"

Pause::Pause(ApplicationManager* pApp) :Action(pApp)
{
	
}

Pause::~Pause(void)
{
}

void Pause::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg(" DDDDDDDDDDDDD");
}

bool Pause::ValidDarwingArea()
{
	return true;
}

bool Pause::Execute()
{
	UI.AppMode = DESIGN;
	return true;
}

void  Pause::Undo()
{}

void  Pause::Redo()
{}