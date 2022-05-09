#include "Paste.h"




Paste::Paste(ApplicationManager* pApp) : Action(pApp)
{

}


void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" Click to paste the component .");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

/* Executes action */
bool  Paste::Execute()
{
	ReadActionParameters();
	Comp = pManager->GetCopiedComp();
	pManager->AddComponent(Comp);
	pManager->UpdateInterface();
	pManager->GetOutput()->PrintMsg("Pasted");
	
	return false;
}

/* Undo action */
void Paste::Undo() {

}

/* Redo action */
void Paste::Redo()
{

}

/* Destructor */
Paste::~Paste()
{}