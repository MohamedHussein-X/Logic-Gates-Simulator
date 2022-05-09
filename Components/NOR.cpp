#include "NOR.h"
NOR::NOR(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR::Operate()
{
	int c = 0;
	for (int i = 0; i < m_Inputs; i++) {
		if (m_InputPins[i].getStatus() == HIGH) {
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
void NOR::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->Drawnor(m_GfxInfo, Selected);
}

//returns status of outputpin
int NOR::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR::Save(ofstream& OutPutFile)
{
	OutPutFile.open("Label.txt", ios::app);
	OutPutFile << "AND Gate2" << "\n";
	OutPutFile << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
	OutPutFile.close();
}

void NOR::Load(ifstream& InFile)
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
