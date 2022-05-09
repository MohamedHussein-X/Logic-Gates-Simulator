#ifndef _COMPONENT_H
#define _COMPONENT_H
#include "..\Defs.h"
#include "..\GUI\Output.h"
#include <fstream>
//Base class for classes Gate, Switch, and LED.
class Component
{
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	string m_Label;
	bool Selected=false;
	bool Deleted=false;
public:
	Component();
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	bool CheckSelection();
	bool checkDeleted();
	void SetSelectCompnent(bool S);
	void CreatLabel(string* Label);
	string GetData();
	void SelectElemnt();
	virtual void Save(ofstream& Outfile)=0;
	virtual void Load(ifstream& Infile) = 0;
	void SetGraphicsInfo(GraphicsInfo& r_GfxInfo);


	
	GraphicsInfo GetGrafxInfo();
	void SetDeleted(bool s);
	//Destructor must be virtual
	virtual ~Component();
};

#endif
