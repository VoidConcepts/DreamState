#include "EditorSystemsModule.h"

#define LOCTEXT_NAMESPACE "FEditorSystemsModuleModule"
DEFINE_LOG_CATEGORY(LogEditorSystemsModule)

void FEditorSystemsModuleModule::StartupModule()
{
}

void FEditorSystemsModuleModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FEditorSystemsModuleModule, EditorSystemsModule)
