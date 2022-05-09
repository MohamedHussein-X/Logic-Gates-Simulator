#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

							//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
						// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(85, 85, 1100, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

							//You can draw the tool bar icons in any way you want.

							//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\and.jpg";
	MenuItemImages[ITM_and3] = "images\\Menu\\and3.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\or.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\xor3.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\exit.jpg";
	MenuItemImages[ITM_start] = "images\\Menu\\start.jpg";
	MenuItemImages[ITM_not] = "images\\Menu\\not.jpg";
	MenuItemImages[ITM_buffer] = "images\\Menu\\buffer.jpg";
	MenuItemImages[ITM_nor] = "images\\Menu\\nor.jpg";
	MenuItemImages[ITM_nor3] = "images\\Menu\\nor3.jpg";
	MenuItemImages[ITM_nand] = "images\\Menu\\nand.jpg";
	MenuItemImages[ITM_xor] = "images\\Menu\\xor.jpg";
	MenuItemImages[ITM_xnor] = "images\\Menu\\xnor.jpg";
	MenuItemImages[ITM_wire] = "images\\Menu\\wire.jpg";
	MenuItemImages[ITM_led] = "images\\Menu\\led.jpg";
	MenuItemImages[ITM_swich] = "images\\Menu\\switch.jpg";
	MenuItemImages[ITM_pause] = "images\\Menu\\pause.jpg";
	MenuItemImages[ITM_load] = "images\\Menu\\load.jpg";
	MenuItemImages[ITM_save] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_table] = "images\\Menu\\table.jpg";
	MenuItemImages[ITM_de] = "images\\Menu\\delete.jpg";
	MenuItemImages[ITM_edit] = "images\\Menu\\edit.jpg";
	MenuItemImages[ITM_undo] = "images\\Menu\\undo.jpg";
	MenuItemImages[ITM_redo] = "images\\Menu\\redo.jpg";
	MenuItemImages[ITM_copy] = "images\\Menu\\copy.jpg";
	MenuItemImages[ITM_paste] = "images\\Menu\\paste.jpg";
	MenuItemImages[ITM_cut] = "images\\Menu\\cut.jpg";
	MenuItemImages[ITM_lable]= "images\\Menu\\label.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < 14; i++) {
		pWind->DrawImage(MenuItemImages[i], i * 85, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}
	int k = 1;
	for (int i = 14; i < 21; i++) {
		pWind->DrawImage(MenuItemImages[i], 1105, 85 * k, UI.ToolItemWidth, UI.ToolBarHeight);
		k++;
	}
	int q = 1;
	for (int i = 21; i < ITM_DSN_CNT; i++) {

		pWind->DrawImage(MenuItemImages[i], 0, q * 85, UI.ToolItemWidth, UI.ToolBarHeight);

		q++;
	}

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, 82, UI.width, 82);

	pWind->DrawLine(85, 82, 85, 700);

	pWind->DrawLine(1100, 82, 1100, 700);


}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu2\\and.jpg";
	MenuItemImages[ITM_and3] = "images\\Menu2\\and3.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu2\\or.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu2\\xor3.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\exit.jpg";
	MenuItemImages[ITM_start] = "images\\Menu2\\start.jpg";
	MenuItemImages[ITM_not] = "images\\Menu2\\not.jpg";
	MenuItemImages[ITM_buffer] = "images\\Menu2\\buffer.jpg";
	MenuItemImages[ITM_nor] = "images\\Menu2\\nor.jpg";
	MenuItemImages[ITM_nor3] = "images\\Menu2\\nor3.jpg";
	MenuItemImages[ITM_nand] = "images\\Menu2\\nand.jpg";
	MenuItemImages[ITM_xor] = "images\\Menu2\\xor.jpg";
	MenuItemImages[ITM_xnor] = "images\\Menu2\\xnor.jpg";
	MenuItemImages[ITM_wire] = "images\\Menu2\\wire.jpg";
	MenuItemImages[ITM_led] = "images\\Menu2\\led.jpg";
	MenuItemImages[ITM_swich] = "images\\Menu2\\switch.jpg";
	MenuItemImages[ITM_pause] = "images\\Menu\\pause.jpg";
	MenuItemImages[ITM_load] = "images\\Menu2\\load.jpg";
	MenuItemImages[ITM_save] = "images\\Menu2\\save.jpg";
	MenuItemImages[ITM_table] = "images\\Menu\\table.jpg";
	MenuItemImages[ITM_de] = "images\\Menu2\\delete.jpg";
	MenuItemImages[ITM_edit] = "images\\Menu2\\edit.jpg";
	MenuItemImages[ITM_undo] = "images\\Menu2\\undo.jpg";
	MenuItemImages[ITM_redo] = "images\\Menu2\\redo.jpg";
	MenuItemImages[ITM_copy] = "images\\Menu2\\copy.jpg";
	MenuItemImages[ITM_paste] = "images\\Menu2\\paste.jpg";
	MenuItemImages[ITM_cut] = "images\\Menu2\\cut.jpg";
	MenuItemImages[ITM_lable] = "images\\Menu2\\label.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < 14; i++) {
		pWind->DrawImage(MenuItemImages[i], i * 85, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}
	int k = 1;
	for (int i = 14; i < 21; i++) {
		pWind->DrawImage(MenuItemImages[i], 1105, 85 * k, UI.ToolItemWidth, UI.ToolBarHeight);
		k++;
	}
	int q = 1;
	for (int i = 21; i < ITM_DSN_CNT; i++) {

		pWind->DrawImage(MenuItemImages[i], 0, q * 85, UI.ToolItemWidth, UI.ToolBarHeight);

		q++;
	}

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, 82, UI.width, 82);

	pWind->DrawLine(85, 82, 85, 700);

	pWind->DrawLine(1100, 82, 1100, 700);

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\and.jpg";
	else
		GateImage = "Images\\Gate\\and.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\and3.jpg";
	else
		GateImage = "Images\\Gate\\and3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawbuffer(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\buffer.jpg";
	else
		GateImage = "Images\\Gate\\buffer.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawnand(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\nand.jpg";
	else
		GateImage = "Images\\Gate\\nand.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawnor(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\nor.jpg";
	else
		GateImage = "Images\\Gate\\nor.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawnor3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\nor3.jpg";
	else
		GateImage = "Images\\Gate\\nor3.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawnot(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\not.jpg";
	else
		GateImage = "Images\\Gate\\not.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawor(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\or.jpg";
	else
		GateImage = "Images\\Gate\\or.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawxnor(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\xnor.jpg";
	else
		GateImage = "Images\\Gate\\xnor.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawxor(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\xor.jpg";
	else
		GateImage = "Images\\Gate\\xor.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawxor3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\xor3.jpg";
	else
		GateImage = "Images\\Gate\\xor3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawled(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\led.jpg";
	else
		GateImage = "Images\\Gate\\led.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::Drawledh(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\ledh.jpg";
	else
		GateImage = "Images\\Gate\\ledh.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::Drawswitch(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gateh\\switch.jpg";
	else
		GateImage = "Images\\Gate\\switch.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}



void Output::Drawmsg(GraphicsInfo r_GfxInfo, string s) const
{
	pWind->SetPen(BLACK, 2);
	string s1 = s;
	pWind->DrawString ( r_GfxInfo.x1, r_GfxInfo.y1,s1);
}



//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	if (selected) {
		pWind->SetPen(RED, 2);
	}
	else {
		pWind->SetPen(BLACK, 2);
	}
	float x1, x2, y1, y2;
	x1 = r_GfxInfo.x1;
	x2 = r_GfxInfo.x2;
	y1 = r_GfxInfo.y1;
	y2 = r_GfxInfo.y2;

	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x2) - (r_GfxInfo.x2 / 9), r_GfxInfo.y1);
	pWind->DrawLine((r_GfxInfo.x2) - (r_GfxInfo.x2 / 9), r_GfxInfo.y1, (r_GfxInfo.x2) - (r_GfxInfo.x2 / 9), r_GfxInfo.y2);
	pWind->DrawLine((r_GfxInfo.x2) - (r_GfxInfo.x2 / 9), r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	//TODO: Add code to draw connection
}
void Output::DrawRectangle(GraphicsInfo r_Graphics) const
{
	pWind->SetPen(color(0, 0, 0), 1);
	pWind->SetBrush(color(0, 0, 0));
	pWind->DrawRectangle(r_Graphics.x1, r_Graphics.y1, r_Graphics.x2, r_Graphics.y2);
}



Output::~Output()
{
	delete pWind;
}
