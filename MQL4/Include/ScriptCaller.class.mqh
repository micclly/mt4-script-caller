#property copyright "Copyright 2014, micclly."
#property link      "https://micclly.info"
#property strict

#import "ScriptCaller.dll"
    int ScriptCaller_create(int chartWindowHandle);
    int ScriptCaller_callScript(int classHandle, string scriptName);
    int ScriptCaller_callScript2(int classHandle, string scriptName, bool closeConfigDialog);
    int ScriptCaller_destroy(int classHandle);
#import

// --------------------------------------------------
// class definition

class ScriptCaller
{
public:
    ScriptCaller();
    virtual ~ScriptCaller();

    bool callScript(string scriptName);
    bool callScript(string scriptName, bool closeConfigDialog);

private:
    int m_handle;
};

// --------------------------------------------------
// public members

ScriptCaller::ScriptCaller()
: m_handle(0)
{
    m_handle = ScriptCaller_create(WindowHandle(_Symbol, _Period));
}

ScriptCaller::~ScriptCaller()
{
    if (m_handle) {
        ScriptCaller_destroy(m_handle);
    }
}

bool ScriptCaller::callScript(string scriptName)
{
    return ScriptCaller_callScript(m_handle, scriptName);
}

bool ScriptCaller::callScript(string scriptName, bool closeConfigDialog)
{
    return ScriptCaller_callScript2(m_handle, scriptName, closeConfigDialog);
}

// --------------------------------------------------
// private members
