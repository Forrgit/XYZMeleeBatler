#pragma once

#include "Components/ActorComponent.h"

#include "MBCharacterTargetingComponent.generated.h"

class UMBTargetFactor;

UCLASS()
class UMBCharacterTargetingComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UMBCharacterTargetingComponent();
	
	UFUNCTION(BlueprintPure)
	AActor* GetTarget() const;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsEnableDebug = false;

protected:
	void DrawDebug();
	
protected:
	UPROPERTY(EditAnywhere)
	float MaxTargetRadius = 300.f;
	
	UPROPERTY(EditAnywhere)
	TEnumAsByte<ETraceTypeQuery> TraceType;
	
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UMBTargetFactor*> TargetFactors;
};
