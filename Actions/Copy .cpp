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

	
}

bool  Copy::Execute() {
	ReadActionParameters();


	string c = pManager->gettybe ();


	pManager->SetCopiedComp(c);

	
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