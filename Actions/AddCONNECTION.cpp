#include "AddCONNECTION.h"
#include "..\ApplicationManager.h"
#include"..\Components\Gate.h"
#include"..\Components\LED.h"
#include"..\Components\SWITCH.h"
AddCONNECTION::AddCONNECTION(ApplicationManager* pApp) :Action(pApp)
{
	_Connection = NULL;
	mSrcPin = NULL;
	mDstPin = NULL;
}

AddCONNECTION::~AddCONNECTION(void)
{
}

void AddCONNECTION::ReadActionParameters()
{
	Gate* Comp1 = NULL;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Connection : please select the Source component");
	


		Comp1 = dynamic_cast<Gate*> (pManager->getTheComponentClickedOn());
	if (Comp1 == NULL)
	{
		pOut->PrintMsg("Invalid area your action has been cancelled");
		ValidConn = 1;
		return;
	}
	if (dynamic_cast<LED*>(Comp1) != NULL)
	{
		pOut->PrintMsg(" Led cannot be used  as a source pin , your action has been cancelled");
		ValidConn = 1;
		return;
	}

	Comp1->getCoordinates(x1, y1);
	Gate* Comp2;
	
	
	pOut->PrintMsg("Connection : please select the distination component");
	

	Comp2 = dynamic_cast<Gate*> (pManager->getTheComponentClickedOn());


	if (Comp2 == NULL)
	{
		pOut->PrintMsg("Invalid area your action has been cancelled");
		ValidConn = 1;
		return;
	}
	if (dynamic_cast<SWITCH*>(Comp2) != NULL)
	{
		pOut->PrintMsg("Switch can not be used distination pin , your action has been cancelled");
		ValidConn = 1;
		return;
	}
	if (Comp2 == Comp1)
	{
		pOut->PrintMsg("You can't connec to to the same gate , your action has been cancelled");
		ValidConn = 1;
		return;
	}

	Comp2->getCoordinates(x2, y2);
	//mDstPin->setStatus((STATUS)Comp2->GetInputPinStatus(DstPinIndex));

	/*if (mDstPin == NULL)
	{
		pOut->PrintMsg("you chose a wrong distination gate , your action has been cancelled");
		ValidConn = 1;
		return;
	}*/

	

}

bool AddCONNECTION::Execute()
{
	ReadActionParameters();
	if (ValidConn)
		
	if (mDstPin == NULL || mSrcPin == NULL) {
		
		
		GraphicsInfo r_GInfo;

		r_GInfo.x1 = x1 +50;
		r_GInfo.x2 = x2;
		r_GInfo.y1 = y1+25;
		r_GInfo.y2 = y2+25;
		Output* pOut = pManager->GetOutput();
		Connection* pA = new Connection(r_GInfo, mSrcPin, mDstPin);
		pManager->AddComponent(pA);
		pManager->ADDcoo(r_GInfo.x1, r_GInfo.y1);

		return true;
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMsg("Invalid area to draw : ");
		return false;
	}
	return false;
}

void AddCONNECTION::Undo()
{}

void AddCONNECTION::Redo()
{}
