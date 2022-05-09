#include "Label.h"
#include "..\ApplicationManager.h"

Label::Label(ApplicationManager* pApp) :Action(pApp)
{
}


void Label::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	s= pIn->GetSrting(pOut);

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}








bool Label::ValidDarwingArea()
{
	if (Cx < UI.ToolItemWidth + 50 || Cx > UI.width - UI.ToolItemWidth - 50)
		return false;
	if (Cy < UI.ToolBarHeight + 50 || Cy > UI.height - UI.StatusBarHeight - 50)
		return false;
	return true;
}


bool Label::Execute() {

	ReadActionParameters();
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	if (Label::ValidDarwingArea()) {
		GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;

		labelcom* pA = new labelcom(GInfo, AND2_FANOUT,s);
		pManager->AddComponent(pA);
	}
	return true;

}















void Label::Undo()
{}

void Label::Redo()
{}

