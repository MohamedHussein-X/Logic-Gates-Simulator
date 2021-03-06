#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

bool AddANDgate2::ValidDarwingArea()
{
	if (Cx < UI.ToolItemWidth + 50 || Cx > UI.width - UI.ToolItemWidth - 50)
		return false;
	if (Cy < UI.ToolBarHeight + 50 || Cy > UI.height - UI.StatusBarHeight - 50)
		return false;
	return true;
}

bool AddANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	if (AddANDgate2::ValidDarwingArea()) {
		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		AND2* pA = new AND2(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);
		pManager->ADDcoo (GInfo.x1, GInfo.y1);
		pManager->settybe("AND2");
	}
	return true;
}

void AddANDgate2::Undo()
{}

void AddANDgate2::Redo()
{}