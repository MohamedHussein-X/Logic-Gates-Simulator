#include "Copy.h"


Copy::Copy(ApplicationManager* pApp) : Action(pApp)
{

}


void Copy::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pManager->UpdateInterface();

	pOut->PrintMsg("Please select a component to copy");
	pIn->GetPointClicked(Cx, Cy);
	pOut->ClearStatusBar();

	if (Comp == NULL)
	{
		pOut->PrintMsg("No component was selected");
		return ;
	}
	else if (dynamic_cast<Connection*>(Comp) != NULL)
	{
		pOut->PrintMsg("Connection can not be copied .");
	}
}

bool  Copy::Execute() {
	ReadActionParameters();
	pManager->SetCopiedComp(Comp);
	pManager->GetOutput()->PrintMsg("Copied");
	pManager->UpdateInterface();
	return true;

}


void Copy::Undo() {
	return;
}


void Copy::Redo() {
	return;
}


Copy::~Copy()
{

}