#pragma once

#include "Engine/DataAsset.h"

#include "MBComboAttackData.generated.h"

class UGameplayAbility;

UCLASS()
class UMBComboAttackData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<UGameplayAbility>> ComboAbilities;
};