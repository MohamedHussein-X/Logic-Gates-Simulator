#include "Save.h"
Save::Save(ApplicationManager* APM) : Action(APM) {

}
void Save::ReadActionParameters() { return; }

bool Save::Execute() {

	WriteFile.open("Data.txt");
	WriteFile.clear();

	pManager->Save(WriteFile);

	WriteFile << "-1\n";
	return false;
}

void Save::Undo() {
	return;
}

void Save::Redo() {
	return;
}
Save::~Save() {
	WriteFile.close();
}