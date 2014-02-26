#property copyright "Copyright 2014, micclly."
#property link      "https://micclly.info"
#property strict
#property indicator_chart_window

#include <ScriptCaller.class.mqh>

ScriptCaller* g_scriptCaller = NULL;

int OnInit()
{
    g_scriptCaller = new ScriptCaller();
    return INIT_SUCCEEDED;
}

void OnDeinit(const int reason)
{
    if (g_scriptCaller) {
        delete g_scriptCaller;
    }
}

int OnCalculate(const int rates_total,
                const int prev_calculated,
                const datetime &time[],
                const double &open[],
                const double &high[],
                const double &low[],
                const double &close[],
                const long &tick_volume[],
                const long &volume[],
                const int &spread[])
{
    return rates_total;
}
