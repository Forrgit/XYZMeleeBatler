#include "MBEquipComponent.h"

#include "GameFramework/Character.h"
#include "MeleeBattler/Items/MBMeleeItem.h"

void UMBEquipComponent::EquipItemClassToHand(TSubclassOf<AMBMeleeItem> NewItem)
{
	if(NewItem != nullptr)
	{
		FActorSpawnParameters spawnParameters;
		spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; 
		const auto itemInstance = GetWorld()->SpawnActor<AMBMeleeItem>(NewItem, spawnParameters);

		EquipItemToHand(itemInstance);
	}
}

void UMBEquipComponent::EquipItemToHand(AMBMeleeItem* NewItem)
{
	if(NewItem != nullptr)
	{
		if(ActiveItem != nullptr)
		{
			ActiveItem->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			ActiveItem->Destroy();
		}

		ActiveItem = NewItem;

		const auto meshComponent = GetOwner<ACharacter>()->GetMesh();
		ActiveItem->AttachToComponent(meshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, HandItemAttachSocketName);

		//TODO remove ability on unequip item
		ActiveItem->GrantAbilitiesToActor(GetOwner());
	}
}

AMBMeleeItem* UMBEquipComponent::GetActiveItem() const
{
	return ActiveItem;
}
