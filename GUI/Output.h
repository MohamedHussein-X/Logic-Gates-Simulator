#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window


														   // Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawbuffer(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawnand(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawnor(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawnor3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawnot(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawor(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawxnor(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawxor(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawxor3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawled(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawledh(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawswitch(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void Drawmsg(GraphicsInfo r_GfxInfo, string s) const;
	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc

	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void PrintMsg(string msg) const;	//Print a message on Status bar

	void DrawRectangle(GraphicsInfo r_Graphics) const;
	~Output();
};
