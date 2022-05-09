#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{

	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_XOR3_GATE_3,		//Add 3-input OR gate
	ADD_not,//Add 1-input Buffer gate
	ADD_Buff,
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_LED,			//Add LED
	ADD_Switch,			//Add Switch
	ADD_CONNECTION,		//Add Wire Connection ............................///////////
	SIM_MODE,	//Switch to Simulatiom mode --------- 15
	DSN_MODE,	//Switch to Design mode
	LOAD,		//Load a Circuit from a file
	SAVE,		//Save the whole Circuit to a file  
	Create_TruthTable,	//Create Truth Table of the Circuit
	DEL,		//Delete a Component, a Connection
	EXIT,		//Exit the application
	EDIT,//Edit Label of a Component, a Connection    

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	COPY,
	PASTE,
	CUT,
	lable,

	Change_Switch,		//Change Switch Status in Simulation Mode
	SELECT,		//Select a Component, a Connection

	MOVE,		//Move a Component, a Connection




	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH,
	NON = -1
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_AND2,
	ITM_and3,         //AND gate item in menu
	ITM_OR2,		//OR gate item in menu
	ITM_XOR3,
	ITM_not,
	ITM_buffer,
	ITM_nor,
	ITM_nor3,
	ITM_nand,
	ITM_xnor,
	ITM_xor,
	ITM_led,
	ITM_swich,
	ITM_wire,
	ITM_start, // 15 Sim 
	ITM_pause,
	ITM_load,
	ITM_save,
	ITM_table,
	ITM_de,
	ITM_EXIT,
	ITM_edit,
	ITM_undo,
	ITM_redo,
	ITM_copy,
	ITM_paste,
	ITM_cut,
	ITM_lable,
	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_SIM,	//Simulate menu item
	ITM_TRUTH,	//Truth table menu item

	//TODO:Add more items names here

	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5,	//Default fan out of 2-input AND gate
	NOT_FANOUT = 10,

	OR_FANOUT = 15,
	AND3_FANOUT = 20,
	BUFFER_FANOUT = 25,
	XNOR_FANOUT = 30,
	NOR_FANOUT = 35,
	NAND_FANOUT = 40,
	XOR_FANOUT = 45,
	XOR3_FANOUT = 50,
	NOR3_FANOUT = 55,
	LED_FANOUT = 1, 
	SWITCH_FANOUT=2,

};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif