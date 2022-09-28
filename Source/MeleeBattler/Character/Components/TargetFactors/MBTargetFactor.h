#pragma once

#include "UObject/Object.h"

#include "MBTargetFactor.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, DefaultToInstanced)
class UMBTargetFactor : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent)
	TArray<AActor*> GetHighPriorityActors(const TArray<AActor*>& TestActors, bool bEnableDebug = false) const;
};