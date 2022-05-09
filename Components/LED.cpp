#include"LED.h"



LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut) {
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void LED::Operate()
{
	
}

bool LED::ValidDarwingArea()
{
	if (Cx < UI.ToolItemWidth + 50 || Cx > UI.width - UI.ToolItemWidth - 50)
		return false;
	if (Cy < UI.ToolBarHeight + 50 || Cy > UI.height - UI.StatusBarHeight - 50)
		return false;
	return true;
}

void LED::Draw(Output* pOut)
{
	
		pOut->Drawled(m_GfxInfo, Selected);

	// مفروض هنا لو متحققش الشرط مفروض يطبع ليد بينور لازم نحط صورة ونستدعيها
}

int LED::GetOutPinStatus()
{
	return -1;
}

int LED::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();	//n starts from 1 but array index starts from 0.
}

void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}


void LED::Save(ofstream& OutPutFile)
{
	OutPutFile.open("Label.txt", ios::app);
	OutPutFile << "LED" << "\n";
	OutPutFile << (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 << " " << (m_GfxInfo.y1 + m_GfxInfo.y2) / 2 << endl;
	OutPutFile.close();
}

void LED::Load(ifstream& InFile)
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

void LED::LedStatus(Output* pOut)
{
	if (m_InputPins[0].getStatus() == HIGH) 
		pOut->Drawledh(m_GfxInfo, Selected);

	
}

