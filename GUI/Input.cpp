//#include "Input.h"
#include "Output.h"
#include<iostream>
using namespace std;
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut)
{
	const int ESCAPE = 27;
	const int ENTER = 13;
	const int BACKSPACE = 8;

	char c;
	string s;

	pWind->FlushKeyQueue();

	do {
		pOut->PrintMsg(" " + s);
		pWind->WaitKeyPress(c);

		switch (c) {
		case BACKSPACE:
			if (!s.empty()) s.pop_back();
			break;
		case ESCAPE:
			s.clear();
			break;
		case ENTER:

			break;
		default:
			s.push_back(c);
			break;
		}

	} while (c != ESCAPE && c != ENTER);

	return s;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / 85);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_and3: return   ADD_AND_GATE_3;
			case ITM_OR2: return ADD_OR_GATE_2;
			case  ITM_XOR3: return ADD_XOR3_GATE_3;
			case ITM_not: return ADD_not;
			case ITM_buffer: return ADD_Buff;
			case ITM_nor: return ADD_NOR_GATE_2;
			case  ITM_nor3: return ADD_NOR_GATE_3;
			case  ITM_nand: return ADD_NAND_GATE_2;
			case  ITM_xnor: return ADD_XNOR_GATE_2;
			case  ITM_xor: return ADD_XOR_GATE_2;
			case  ITM_led: return ADD_LED;
			case  ITM_swich: return ADD_Switch;
			case  ITM_wire: return ADD_CONNECTION;

			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}




		if (x <= 85 && x > 0)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = ((y / 85) + 20);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{

			case ITM_edit: return EDIT;
			case ITM_undo: return  UNDO;
			case ITM_redo: return  REDO;
			case ITM_copy: return   COPY;
			case ITM_paste: return  PASTE;
			case ITM_cut: return   CUT;
			case ITM_lable: return lable;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}


		if (x > 1105 && x < 1200) {
			int ClickedItemOrder = ((y / 85) + 13);
			switch (ClickedItemOrder)
			{
			case  ITM_start: return SIM_MODE;
			case  ITM_pause: return    DSN_MODE;
			case  ITM_load: return LOAD;
			case  ITM_save: return SAVE;
			case  ITM_table: return Create_TruthTable;
			case  ITM_de: return DEL;
			case  ITM_EXIT: return  EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	



		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
