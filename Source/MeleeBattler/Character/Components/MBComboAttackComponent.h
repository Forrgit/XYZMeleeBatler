#pragma once

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

	void Attack();

private:
	AMBMeleeItem* GetActiveItem() const;

private:
	TWeakObjectPtr<AMBBaseCharacter> OwningCharacter;
	TWeakObjectPtr<UMBEquipComponent> EquipComponent;
};


