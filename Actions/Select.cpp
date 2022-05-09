#include "Select.h"

#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"


Select::Select(ApplicationManager* pApp) : Action(pApp)
{
}

Select::~Select(void)
{
}

void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	//pOut->PrintMsg(" Click to delete the component .");

	//Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

bool Select::Execute()
{
	//Selected = true;
	pManager->SelectComp();
	return true;
}

void Select::Undo()
{
}

void Select::Redo()
{
}
