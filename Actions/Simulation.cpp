
#include "Simulation.h"


#include "..\ApplicationManager.h"

Simulation::Simulation(ApplicationManager* pApp) :Action(pApp)
{
	UI.AppMode = SIMULATION;
}

Simulation::~Simulation(void)
{
}

void Simulation::ReadActionParameters()
{

}

bool Simulation::ValidDarwingArea()
{
	return true;
}

bool Simulation::Execute()
{
	UI.AppMode = SIMULATION;
	return true;
}

void  Simulation::Undo()
{}

void  Simulation::Redo()
{}