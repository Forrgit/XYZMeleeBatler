#include "MBBaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "Components/MBComboAttackComponent.h"
#include "Components/MBEquipComponent.h"
#include "MeleeBattler/Abilities/MBAttackAbility.h"
#include "MeleeBattler/Abilities/MBCharacterAttributeSet.h"


AMBBaseCharacter::AMBBaseCharacter()
{
	CharacterAttributeSet = CreateDefaultSubobject<UMBCharacterAttributeSet>("CharacterAttributeSet");
	
	EquipComponent = CreateDefaultSubobject<UMBEquipComponent>("EquipComponent");

	ComboAttackComponent = CreateDefaultSubobject<UMBComboAttackComponent>("ComboAttackComponent");

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
}

void AMBBaseCharacter::UseAbility(TSubclassOf<UGameplayAbility> Ability)
{
	if(Ability != nullptr)
	{
		AbilitySystemComponent->TryActivateAbilityByClass(Ability);
	}
}

void AMBBaseCharacter::StartAttack()
{	
	UseAbility(AttackAbility);
}

void AMBBaseCharacter::StopAttack()
{
	if(const auto abilitySpec = AbilitySystemComponent->FindAbilitySpecFromClass(AttackAbility))
	{
		AbilitySystemComponent->CancelAbility(abilitySpec->Ability);
	}
}

bool AMBBaseCharacter::CanAttack() const
{
	return EquipComponent->GetActiveItem() != nullptr;
}
