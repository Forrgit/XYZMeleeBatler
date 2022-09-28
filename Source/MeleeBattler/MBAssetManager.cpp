#include "MBAssetManager.h"

#include "AbilitySystemGlobals.h"

void UMBAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	UAbilitySystemGlobals::Get().InitGlobalData();
}
