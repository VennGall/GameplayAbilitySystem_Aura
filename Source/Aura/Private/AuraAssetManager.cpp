// Copyright Venn Gall


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine && GEngine->AssetManager);
	return *Cast<UAuraAssetManager>(GEngine->AssetManager);
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	
	FAuraGameplayTags::InitialiseNativeGameplayTags();
}
