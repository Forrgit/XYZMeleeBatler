#include "MBComboAttackComponent.h"

#include "MBEquipComponent.h"
#include "MeleeBattler/Character/MBBaseCharacter.h"
#include "MeleeBattler/Data/MBComboAttackData.h"
#include "MeleeBattler/Items/MBMeleeItem.h"

void UMBComboAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	OwningCharacter = GetOwner<AMBBaseCharacter>();
	if(OwningCharacter.IsValid())
	{
		EquipComponent = OwningCharacter->EquipComponent;
	}
}

void UMBComboAttackComponent::Attack()
{
	const auto activeItem = GetActiveItem();
	
	if(!OwningCharacter.IsValid() || activeItem == nullptr
		|| activeItem->ComboAttackData == nullptr || activeItem->ComboAttackData->ComboAbilities.Num() == 0)
	{
		return;
	}

	const auto comboAttackData = activeItem->ComboAttackData;
	OwningCharacter->UseAbility(comboAttackData->ComboAbilities[0]);
}

AMBMeleeItem* UMBComboAttackComponent::GetActiveItem() const
{
	if(EquipComponent.IsValid())
	{
		return EquipComponent->GetActiveItem();
	}
	return nullptr;
}
