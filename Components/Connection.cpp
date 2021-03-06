#include "Connection.h"
#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include "..\Defs.h"
#include "..\GUI\Output.h"
#include <fstream>
Connection::Connection(const GraphicsInfo& r_GfxInfo,OutputPin* pSrcPin, InputPin* pDstPin)
	:Component(r_GfxInfo)
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
Connection::Connection(const GraphicsInfo& r_GfxInfo, Component* pS , Component* pD , int Pin )
	:Component(r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	SrcCmpnt = pS;
	dstPin = Pin;
	DstCmpnt = pD;
}
void Connection::setSourcePin(OutputPin* pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin* Connection::getSourcePin()
{
	return SrcPin;
}


void Connection::setDestPin(InputPin* pDstPin)
{
	DstPin = pDstPin;
}

InputPin* Connection::getDestPin()
{
	return DstPin;
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{

	pOut->DrawConnection(m_GfxInfo, CheckSelection());
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{

	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::Save(ofstream& Outfile)
{
}

void Connection::Load(ifstream& Infile)
{
}
