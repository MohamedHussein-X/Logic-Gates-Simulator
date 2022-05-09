#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	
	
	Component* CopiedComp;		// Pointer to the last copied/cut component
	int k = 0;
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	int Delcount;
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Action* m_UndoCounter[20];
	Action* m_RedoCounter[20];
	const int MaxActions = 20;
	Component* DelList[MaxCompCount];
	int RedoCounter = -1;
	int UndoCounter = -1;
public:


public:
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	//destructor
	~ApplicationManager();
	void Redo();
	void Undo();
	void Load(ifstream& ReadFile);
	void Save(ofstream& WriteFile);
	void SetCopiedComp(Component* pComp);
	Component* GetCopiedComp() const;
	void SelectComp();
	void DelComponents(Component* pComp);
	Component* getSelectedComp();
	Component*  getTheComponentClickedOn();
	void SetDelList(Component* pComp);
};

#endif
