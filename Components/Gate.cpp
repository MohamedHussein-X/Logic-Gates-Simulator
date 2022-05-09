#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

void Gate::getCoordinates(int& x, int& y)
{
	x = m_GfxInfo.x1  ;
	y = m_GfxInfo.y1  ;
}


void Gate::GetInputPinCoordinates(int& x, int& y, int N) {
	x = m_GfxInfo.x1 - UI.Pinspace;
	y = m_GfxInfo.y1 + UI.Pinspace + UI.Pinarea * N;
}
void Gate::GetOutputPinCoordinates(int& x, int& y) 
{
	x = m_GfxInfo.x2 + UI.Pinspace;
	y = (m_GfxInfo.y1 + m_GfxInfo.y2) / 2;
}