#pragma once
#include "Engine/AssetManager.h"


#include "MBAssetManager.generated.h"

UCLASS()
class UMBAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	virtual void StartInitialLoading() override;
};
