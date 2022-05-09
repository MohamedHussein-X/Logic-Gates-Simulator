#include "AND2.h"

AND2::AND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND2::Operate()
{
	int c = 0;
	for (int i = 0; i < m_Inputs; i++) {
		if (m_InputPins[i].getStatus() == LOW) {
			c = 1;
		}
	}
	if (c == 1) {
		m_OutputPin.setStatus(LOW);
	}
	else {
		m_OutputPin.setStatus(HIGH);
	}

}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo, Selected);
}

//returns status of outputpin
int AND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void AND2::Save(ofstream& OutPutFile)
{
	
	OutPutFile << "AND Gate2" << " ";
	OutPutFile << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;

}

void AND2::Load(ifstream& InFile)
{
	if (InFile.is_open())
	{
		getline(InFile, m_Label);
		double x, y;
		InFile >> x >> y;
		m_GfxInfo.x1 = x - 25;
		m_GfxInfo.x2 = x + 25;
		m_GfxInfo.y1 = y - 25;
		m_GfxInfo.y2 = y + 25;
	}
}