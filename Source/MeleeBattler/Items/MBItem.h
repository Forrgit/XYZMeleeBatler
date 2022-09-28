#pragma once

#include "GameFramework/Actor.h"

#include "MBItem.generated.h"

UCLASS(Abstract)
class AMBItem : public AActor
{
	GENERATED_BODY()
public:
	virtual void GrantAbilitiesToActor(AActor* Actor);
	
};

