#pragma once

#include "MBTargetFactor.h"

#include "MBViewTargetFactor.generated.h"

UCLASS()
class UMBViewTargetFactor : public UMBTargetFactor
{
	GENERATED_BODY()
public:
	virtual TArray<AActor*> GetHighPriorityActors_Implementation(const TArray<AActor*>& TestActors, bool bEnableDebug) const override;

public:
	UPROPERTY(EditAnywhere)
	float MaxViewAngle = 120.f;
};

