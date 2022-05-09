#include "NOTT.h"


NOTT::NOTT(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOTT::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH)
		m_OutputPin.setStatus(LOW);

	if (m_InputPins[0].getStatus() == LOW)
		m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 2-input AND gate
void NOTT::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->Drawnot(m_GfxInfo, Selected);
}

//returns status of outputpin
int NOTT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOTT::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOTT::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOTT::Save(ofstream& OutPutFile)
{
	OutPutFile.open("Label.txt", ios::app);
	OutPutFile << "AND Gate2" << "\n";
	OutPutFile << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
	OutPutFile.close();
}

void NOTT::Load(ifstream& InFile)
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
