// Copyright 2020 Ramon Janousch


#include "OculusGoFunctionLibrary.h"

#include "Engine.h"


void UOculusGoFunctionLibrary::OculusGoQuitGame(UObject* WorldContextObject)
{
	bool bIsTestingOnWindows = UGameplayStatics::GetPlatformName().Equals("Windows");
	if (bIsTestingOnWindows)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
		UKismetSystemLibrary::QuitGame(WorldContextObject, World->GetFirstPlayerController(), EQuitPreference::Quit, true);
	}
	else
	{
		FPlatformMisc::RequestExit(true);
	}
}

FString UOculusGoFunctionLibrary::GetVersion()
{
	FString ProjectVersion;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		ProjectVersion,
		GGameIni
	);

	if (ProjectVersion.IsEmpty()) {
		ProjectVersion = "0.0.0";
	}

	return ProjectVersion;
}