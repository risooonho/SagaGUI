#pragma once

#include "Engine.h"

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetLayoutLibrary.h"

#include "Runtime/Engine/Classes/Engine/UserInterfaceSettings.h"
#include "Runtime/Engine/Classes/Engine/RendererSettings.h"

#include "SagaWidget.h"
#include "FloatingBarWidget.h"
#include "AllyDotWidget.h"
#include "FloatingTextWidget.h"
#include "PlayerHPWidget.h"
#include "InventoryWidget.h"

DECLARE_LOG_CATEGORY_EXTERN(SagaGUI, Log, All);

FORCEINLINE APlayerController* GetPlayerController()
{
	for (TObjectIterator<APlayerController> pc; pc; ++pc)
		if (pc->bActorInitialized) return *pc;

	return nullptr;
}

FORCEINLINE bool IsGameRunning()
{
	return GetPlayerController() ? true : false;
}