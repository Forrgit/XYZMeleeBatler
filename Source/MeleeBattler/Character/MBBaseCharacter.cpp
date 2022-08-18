#include "MBBaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "Components/MBComboAttackComponent.h"
#include "Components/MBEquipComponent.h"

AMBBaseCharacter::AMBBaseCharacter()
{
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

void AMBBaseCharacter::Attack()
{
	if(CanAttack())
	{
		ComboAttackComponent->Attack();
	}
}

bool AMBBaseCharacter::CanAttack() const
{
	return EquipComponent->GetActiveItem() != nullptr;
}
