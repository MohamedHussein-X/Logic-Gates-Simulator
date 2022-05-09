#pragma once
#include "action.h"
#include "..\Components\connection.h"

class AddCONNECTION : public Action
{
private:
	
	Connection* _Connection;		// Pointer to the connection
	int DstPinIndex;				// The index stands for  the destination pin
	string Label = "Connection ";					// The label of the component
	GraphicsInfo r_GfxInfo;			//  (coordinates) to draw the connection
	InputPin* mDstPin;					// Pointer to the destination pin
	OutputPin* mSrcPin; // Pointer to the source pin 
	bool ValidConn;
	int x1, x2, y1, y2;
public:
	AddCONNECTION(ApplicationManager* pApp);
	virtual ~AddCONNECTION(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();
	bool IsSourceGate();

	virtual void Undo();
	virtual void Redo();


};
