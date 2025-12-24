#include "SimpleCppModulePlugin.h"
#include "CppText.h"

#include <qqml.h>

void SimpleCppModulePlugin::registerTypes(const char *uri)
{
    qmlRegisterType<CppText>(uri, 1, 0, "CppText");
}
