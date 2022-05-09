#pragma once
#include "Action.h"

#include "..\Components\labelcom.h"



class Label :
    public Action
{
private:
    string s;
    int Cx, Cy;	
    int x1, y1, x2, y2;	
public:
    Label(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    //Execute action (code depends on action type)
    bool ValidDarwingArea();
    virtual bool Execute();

    virtual void Undo();
    virtual void Redo();

};

