#include "D_BUFFER_G.h"
#include "..\ApplicationManager.h"


D_BUFFER_G::D_BUFFER_G(ApplicationManager* pApp) :Action(pApp)
{
}

D_BUFFER_G::~D_BUFFER_G(void)
{
}

void D_BUFFER_G::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input Buffer Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

bool D_BUFFER_G::ValidDarwingArea()
{
	if (Cx < UI.ToolItemWidth + 50 || Cx > UI.width - UI.ToolItemWidth - 50)
		return false;
	if (Cy < UI.ToolBarHeight + 50 || Cy > UI.height - UI.StatusBarHeight - 50)
		return false;
	return true;
}

bool D_BUFFER_G::Execute() 
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	if (D_BUFFER_G::ValidDarwingArea()) {
		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		BUFFER* pA = new BUFFER(GInfo, BUFFER_FANOUT);
		pManager->AddComponent(pA);
	}
	return true;
}

void D_BUFFER_G::Undo()
{}

void D_BUFFER_G::Redo()
{}

