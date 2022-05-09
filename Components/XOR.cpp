#include "XOR.h"
XOR::XOR(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR::Operate()
{
	if (m_InputPins[0].getStatus() == m_InputPins[1].getStatus())
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);

}


// Function Draw
// Draws 2-input AND gate
void XOR::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->Drawxor(m_GfxInfo, Selected);
}

//returns status of outputpin
int XOR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR::Save(ofstream& OutPutFile)
{
	OutPutFile.open("Label.txt", ios::app);
	OutPutFile << "AND Gate2" << "\n";
	OutPutFile << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
	OutPutFile.close();
}

void XOR::Load(ifstream& InFile)
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

