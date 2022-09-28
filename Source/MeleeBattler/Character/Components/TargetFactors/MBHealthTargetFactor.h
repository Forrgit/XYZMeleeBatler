#pragma once

#include "MBTargetFactor.h"

#include "MBHealthTargetFactor.generated.h"

UCLASS()
class UMBHealthTargetFactor : public UMBTargetFactor
{
	GENERATED_BODY()
public:
	virtual TArray<AActor*> GetHighPriorityActors_Implementation(const TArray<AActor*>& TestActors, bool bEnableDebug = false) const override;
};

