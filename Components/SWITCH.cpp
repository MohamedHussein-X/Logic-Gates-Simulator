#include"SWITCH.h"




SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut) {
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void SWITCH::Operate()
{
	m_OutputPin.setStatus(HIGH);
}

bool SWITCH::ValidDarwingArea()
{
	if (Cx < UI.ToolItemWidth + 50 || Cx > UI.width - UI.ToolItemWidth - 50)
		return false;
	if (Cy < UI.ToolBarHeight + 50 || Cy > UI.height - UI.StatusBarHeight - 50)
		return false;
	return true;
}

void SWITCH::Draw(Output* pOut)
{
	if (SWITCH::ValidDarwingArea()) {
		pOut->Drawswitch(m_GfxInfo, Selected);

	}

}

int SWITCH::GetOutPinStatus()
{
	return HIGH;
}

int SWITCH::GetInputPinStatus(int n)
{
	return -1;
}

void SWITCH::setInputPinStatus(int n, STATUS s)
{
	
}

void SWITCH ::Save(ofstream& OutPutFile)
{
	OutPutFile.open("Label.txt", ios::app);
	OutPutFile << "SWITCH" << "\n";
	OutPutFile << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
	OutPutFile.close();
}

void SWITCH ::Load(ifstream& InFile)
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

