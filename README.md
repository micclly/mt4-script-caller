mt4-script-caller
==================

This is script caller class library for MetaTrader4 (**only for build 600 and later**).

This library enables script calling from indicators and expert advisors.


Installation
--------------

1. Copy ``MQL4\Library\ScriptCaller.dll`` to ``<MT4_DATA_FOLDER>\MQL4\Library\``
1. Copy ``MQL4\Include\ScriptCaller.class.mqh`` to ``<MT4_DATA_FOLDER>\MQL4\Include\``

How to
--------

1. Add the following include line to your indicator or expert advisor

   ```cpp
   #include <ScriptCaller.class.mqh>
   ```
1. Add the following code to initialize/deinitialize class instance.

   ```cpp
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
   ```
1. Finally, put the following code to call script!

   ```cpp
   g_scriptCaller.callScript("ScriptName"); // Do not end with .mq4
   ```
1. If the script shows input dialog, and you want to close it automatically, call as follows.

   ```cpp
   g_scriptCaller.callScript("ScriptName", true); // if the 2nd parameter is true, dialog will be closed automatically.
   ```

Samples
---------

Under ``MQL4\Indicators``, 2 sample indicators, which calls scripts under ``MQL4\Scripts``.

License
---------

This software is licensed under GNU General Public License Version 3.
