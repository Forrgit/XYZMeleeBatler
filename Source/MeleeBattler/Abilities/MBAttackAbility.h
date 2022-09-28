#pragma once

#include "Abilities/GameplayAbility.h"

#include "MBAttackAbility.generated.h"

class AMBBaseCharacter;
class UMBComboAttackComponent;

UCLASS()
class UBMAttackAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

private:
	void UseAttack();

protected:
	UPROPERTY(EditAnywhere)
	float ComboAttackInterval = 0.1;

	UPROPERTY(EditAnywhere)
	FGameplayTagContainer ComboAbilityAttackTags;
	
private:
	TWeakObjectPtr<UMBComboAttackComponent> ComboAttackComponent;

	FTimerHandle AttackTimer;
};

