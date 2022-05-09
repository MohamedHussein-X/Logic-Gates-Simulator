#include "D_LED_G.h"
#include "..\ApplicationManager.h"
D_LED_G::D_LED_G(ApplicationManager* pApp) :Action(pApp)
{
	pApp = pApp;
}

D_LED_G::~D_LED_G(void)
{
}

void D_LED_G::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg(" Led : Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

bool D_LED_G::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.LED_Height;
	int Wdth = UI.LED_Width;

	GraphicsInfo GInfo;

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	LED* pA = new LED(GInfo, LED_FANOUT);
	pManager->AddComponent(pA);
	return true;
}

void D_LED_G::Undo()
{}

void D_LED_G::Redo()
{}