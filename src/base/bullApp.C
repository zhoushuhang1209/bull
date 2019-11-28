#include "bullApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<bullApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

bullApp::bullApp(InputParameters parameters) : MooseApp(parameters)
{
  bullApp::registerAll(_factory, _action_factory, _syntax);
}

bullApp::~bullApp() {}

void
bullApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"bullApp"});
  Registry::registerActionsTo(af, {"bullApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
bullApp::registerApps()
{
  registerApp(bullApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
bullApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  bullApp::registerAll(f, af, s);
}
extern "C" void
bullApp__registerApps()
{
  bullApp::registerApps();
}
