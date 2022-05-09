#include "D_SWITCH.h"
#include "..\ApplicationManager.h"


D_SWITCH::D_SWITCH(ApplicationManager* pApp) :Action(pApp)
{
	pApp = pApp;
}

D_SWITCH::~D_SWITCH(void)
{
}

void D_SWITCH::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" Switch: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

bool D_SWITCH ::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.SWITCH_Height;
	int Wdth = UI.SWITCH_Width;

	GraphicsInfo GInfo;

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	SWITCH* pA = new SWITCH(GInfo, SWITCH_FANOUT);
	pManager->AddComponent(pA);

	return true;
}

void D_SWITCH::Undo()
{}

void D_SWITCH::Redo()
{}