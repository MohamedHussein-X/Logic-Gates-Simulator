#include "Component.h"
#define _COMPONENT_H
#include "..\Defs.h"
#include "..\GUI\Output.h"
#include <fstream>
Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
}
bool Component::checkDeleted() { return Deleted; }
void Component::SetSelectCompnent(bool S)
{
	Selected = S;
}
void Component::CreatLabel(string* Label)
{
	m_Label = *Label;
}
string Component::GetData()
{
	return m_Label;
}
void Component::SelectElemnt()
{
	if (UI.AppMode == MODE::DESIGN) {
		if (Selected == true)
			Selected = false;
		else
			Selected = true;
	}
}
void Component::SetGraphicsInfo(GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
}
GraphicsInfo Component::GetGrafxInfo()
{
	return m_GfxInfo;
}
bool Component::CheckSelection() { return Selected; }



void Component::SetDeleted(bool s)
{
	Deleted = s;
}

Component::Component()
{}

Component::~Component()
{}

