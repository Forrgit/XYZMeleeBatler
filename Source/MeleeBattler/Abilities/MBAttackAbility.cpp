#include "MBAttackAbility.h"

#include "AbilitySystemComponent.h"
#include "MeleeBattler/Character/MBBaseCharacter.h"
#include "MeleeBattler/Character/Components/MBComboAttackComponent.h"

void UBMAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                       const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                       const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if(const auto owningCharacter = Cast<AMBBaseCharacter>(ActorInfo->OwnerActor.Get()))
	{
		ComboAttackComponent = owningCharacter->ComboAttackComponent;
	}

	if(ComboAttackComponent.IsValid())
	{
		ComboAttackComponent->ResetCombo();
		GetWorld()->GetTimerManager().SetTimer(AttackTimer, this, &UBMAttackAbility::UseAttack, ComboAttackInterval, true, 0.f);
	}
}

void UBMAttackAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	GetWorld()->GetTimerManager().ClearTimer(AttackTimer);
}

void UBMAttackAbility::UseAttack()
{
	const auto abilitySystem = GetAbilitySystemComponentFromActorInfo(); 
	TArray<FGameplayAbilitySpec*> comboAttackAbilities;
	abilitySystem->GetActivatableGameplayAbilitySpecsByAllMatchingTags(ComboAbilityAttackTags, comboAttackAbilities, false);

	// bool bHasActiveCombo = false;
	// for(const auto abilitySpec : comboAttackAbilities)
	// {
	// 	if(abilitySpec != nullptr && abilitySpec->IsActive())
	// 	{
	// 		bHasActiveCombo = true;
	// 		break;
	// 	}
	// }

	const auto activeComboAbilitySpec = Algo::FindByPredicate(comboAttackAbilities, [](const FGameplayAbilitySpec* Spec)
	{
		return Spec != nullptr && Spec->IsActive();
	});

	if(activeComboAbilitySpec == nullptr)
	{
		if(const auto comboAbility = ComboAttackComponent->GetNextComboAbility())
		{
			abilitySystem->TryActivateAbilityByClass(comboAbility);
		}
		ComboAttackComponent->NextAttackAbility();
	}
}
