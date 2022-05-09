#include "labelcom.h"
#include "..\ApplicationManager.h"

labelcom::labelcom(const GraphicsInfo& r_GfxInfo, int r_FanOut, string s1) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	s = s1;
}


void labelcom::Operate()
{


}


// Function Draw
// Draws 2-input AND gate
void labelcom::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->Drawmsg (m_GfxInfo,s);
}

//returns status of outputpin
int labelcom::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int labelcom ::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void labelcom::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void labelcom::Save(ofstream& OutPutFile)
{
	
}

void labelcom::Load(ifstream& InFile)
{
	
}
