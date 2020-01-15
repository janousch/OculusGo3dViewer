// Copyright 2020 Ramon Janousch

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OculusGoFunctionLibrary.generated.h"

/**
 * Simple functions for the Oculus Go
 */
UCLASS()
class GOTEMPLATE_API UOculusGoFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	/*
	Workaround for the Quit Bug in 4.22
	*/
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void OculusGoQuitGame(UObject* WorldContextObject);

	/*
	Get the current project version
	*/
	UFUNCTION(BlueprintPure)
		static FString GetVersion();
};
