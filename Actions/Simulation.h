
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Components\LED.h"
#include "..\Components\Switch.h"
#include "..\Components\Gate.h"
#include "..\Components\Connection.h"




class Simulation :
    public Action
{
private:
	
	bool mStopSimulation;
public:
	Simulation(ApplicationManager* pApp);
	virtual ~Simulation(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	bool ValidDarwingArea();
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};
