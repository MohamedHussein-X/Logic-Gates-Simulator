#pragma once
#include "Gate.h"
class SWITCH :
    public Gate
{
private:
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//


public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	bool ValidDarwingArea();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class
	void Save(ofstream& OutPutFile);
	void Load(ifstream& InFile);

};

