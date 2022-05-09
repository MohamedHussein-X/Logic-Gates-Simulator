#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\D_NOT_G.h"
#include "Actions\D_OR_G.h"
#include "Actions\D_AND3_G.h"
#include "Actions\D_BUFFER_G.h"
#include "Actions\D_XNOR_G.h"
#include "Actions\D_NOR_G.h"
#include "Actions\D_NAND_G.h"
#include "Actions\D_XOR_G.h"
#include "Actions\D_XOR3_G.h"
#include "Actions\D_NOR3_G.h"
#include "Actions\D_LED_G.h"
#include "Actions\D_SWITCH.h"
#include"Actions\Copy.h"
#include"Actions\Delete.h"
#include"Actions\Paste.h"
#include "Actions\Label.h"
#include "Actions\Simulation.h"
#include"Actions/Save.h"
#include"Actions/Pause.h"
#include"Actions/Select.h"
#include"Actions\AddCONNECTION.h"



ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	 Delcount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_not:
			pAct = new D_NOT_G(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new D_OR_G(this);
			break;
		case ADD_AND_GATE_3:
			pAct = new D_AND3_G(this);
			break;
		case ADD_Buff:
			pAct = new D_BUFFER_G(this);
			break;
		case ADD_XNOR_GATE_2 :
			pAct = new D_XNOR_G(this);
			break;
		case ADD_NOR_GATE_2 :
			pAct = new D_NOR_G(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new D_NAND_G(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new D_XOR_G(this);
			break;
		case ADD_XOR3_GATE_3:  
			pAct = new D_XOR3_G(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new D_NOR3_G(this);
			break;
		case ADD_LED:
			pAct = new D_LED_G(this);
			break;
		case ADD_Switch:
			pAct = new D_SWITCH(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddCONNECTION(this);
			break;
	

		case EXIT:
			///TODO: create ExitAction here
			break;
		case DEL:
			pAct = new Delete(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
			/*case CUT:
				pAct = new Cut(this);
				break;*/
		case PASTE:
			pAct = new Paste(this);
			break;
		case ITM_lable:
			pAct = new Label(this);
			break;
		case ITM_start:
			OutputInterface->CreateSimulationToolBar();
			UI.AppMode = SIMULATION;
			pAct = new Simulation(this);
			break;
		case  ITM_save:
			pAct = new ::Save(this);
				break;
		case DSN_MODE:
			UI.AppMode = DESIGN;
		
			OutputInterface->CreateDesignToolBar();
			
			pAct = new Pause(this);
			
			break;
		
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////


void ApplicationManager::SetCopiedComp(Component* pComp)
{
	CopiedComp = pComp;
}
////////////////////////////////////////////////////////////////////

Component* ApplicationManager::GetCopiedComp() const
{
	//AddComponent(CopiedComp);
	return CopiedComp;
}
/*void ApplicationManager::SetSelectComponents(bool s)
{
	for (int i = 0; i < mCompCount; i++)
	{
		CompList[i]->SetSelectCompnent(s);
	}
}*/


/* Returns array of  selected components
Component** ApplicationManager::GetSelectedComps() {
	int c = 0;
	Component* Comps[MaxCompCount];
	for (int i = 0; i < CompCount; i++) {
		if (!CompList[i]->checkDeleted() && CompList[i]->checkDeleted())
		{
			Comps[c] = CompList[i];
			c++
		}
	}

	return Comps;
}*/



/*Connection** ApplicationManager::ConnectionsList()
{
	int c = 0;
	enum { MaxConnCount = 5 };    //Max no of Connections
	Connection* conns[MaxConnCount];
	for (int i = 0; i < CompCount; i++) {
		Connection* ptr = dynamic_cast<Connection*>(CompList[i]);

		if (ptr != NULL && !ptr->checkDeleted())
		{
			conns[c] = ptr;
			c++;
		}
	}
	return conns;
}*/

void ApplicationManager::DelComponents(Component* pComp)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (pComp == NULL)
		{
			GetOutput()->PrintMsg("No component to delete .");
			return;
		}

		if (CompList[i] == pComp)
		{
			GraphicsInfo r_Graphics = pComp->GetGrafxInfo();
			CompList[i]->SetDeleted(1);
			CompList[i] = CompList[CompCount - 1];
			CompList[CompCount - 1] = NULL;
			CompCount--;
			OutputInterface->ClearDrawingArea();
			UpdateInterface();

		}
	}
}

Component* ApplicationManager::getSelectedComp()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->CheckSelection())
			return CompList[i];

		return nullptr;
	}
}

void ApplicationManager::SetDelList(Component* pComp)
{
      DelList[Delcount++]=pComp;
}

void ApplicationManager::Redo() {
	for (int i = 0; i <= RedoCounter; i++) {
		if (m_RedoCounter[i] == NULL)
			return;
	}
	Action* lastAction = m_RedoCounter[RedoCounter];
	lastAction->Redo();
	if (RedoCounter <= -1)
		return;
	m_RedoCounter[RedoCounter] = NULL;
	RedoCounter--;
	UndoCounter++;
	m_UndoCounter[UndoCounter] = lastAction;
}


void ApplicationManager::Save(ofstream& WriteFile) {
	for (int i = 0; i < CompCount; i++) {
		if (!CompList[i]->checkDeleted()) {
			CompList[i]->Save(WriteFile);
		}
	}
}
void ApplicationManager::SelectComp()
{
	int x; int y;
	GetInput()->GetPointClicked(x, y);
	for (int i = 0; i < CompCount; i++)
	{
		GraphicsInfo G = CompList[i]->GetGrafxInfo();
		if (x >= G.x1 && x <= G.x2 && y >= G.y1 && y <= G.y2)
		{
			CompList[i]->SetSelectCompnent(1);
			break;
		}
	}
	UpdateInterface();
}


Component* ApplicationManager::getTheComponentClickedOn()
{
	int selectedCount = 0;
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->SetSelectCompnent(0);
		//SelectedComponents[i] = NULL;
	}
	Action* pAct;
	InputInterface->GetUserAction();
	pAct = new Select(this);
	pAct->Execute();
	UpdateInterface();
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->CheckSelection())
			return CompList[i];
	}
	return NULL;
}




ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}