#include "Delete.h"
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"

Delete::Delete(ApplicationManager* pApp) : Action(pApp)
{
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	
	
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg(" Click to delete the component .");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearDrawingArea();
}

bool Delete::Execute()
{
	ReadActionParameters();
	Component* Comp = pManager->getSelectedComp();
	pManager->SetDelList(Comp);
	pManager->DelComponents(Comp);
	pManager->GetOutput()->PrintMsg("Component deleted .");
	
	return false;
}

void Delete::Undo()
{
}

void Delete::Redo()
{
}

Delete::~Delete()
{
}
