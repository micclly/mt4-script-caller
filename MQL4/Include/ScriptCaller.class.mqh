#property copyright "Copyright 2014, micclly."
#property link      "https://micclly.info"
#property strict

#import "ScriptCaller.dll"
    int ScriptCaller_create();
    int ScriptCaller_destroy(int handle);
#import

// --------------------------------------------------
// class definition

class ScriptCaller
{
public:
    ScriptCaller();
    virtual ~ScriptCaller();

private:
    int m_handle;
};

// --------------------------------------------------
// public members

ScriptCaller::ScriptCaller()
: m_handle(0)
{
    m_handle = ScriptCaller_create();
}

ScriptCaller::~ScriptCaller()
{
    if (m_handle) {
        ScriptCaller_destroy(m_handle);
    }
}

// --------------------------------------------------
// private members
