#pragma once

#include "Abilities/GameplayAbility.h"
#include "Components/ActorComponent.h"

#include "MBComboAttackComponent.generated.h"

class AMBMeleeItem;
class AMBBaseCharacter;
class UMBEquipComponent;

UCLASS()
class UMBComboAttackComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	void NextAttackAbility();
	void ResetCombo();
	
	TSubclassOf<UGameplayAbility> GetNextComboAbility() const;

private:
	AMBMeleeItem* GetActiveItem() const;

private:
	TWeakObjectPtr<AMBBaseCharacter> OwningCharacter;
	TWeakObjectPtr<UMBEquipComponent> EquipComponent;

	TWeakObjectPtr<AMBMeleeItem> LastAbilityItem;
	int32 LastComboAttackAbilityIndex;
};


