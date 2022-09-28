#include "MBMeleeItem.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "MeleeBattler/Data/MBComboAttackData.h"

AMBMeleeItem::AMBMeleeItem()
{
	TransformComponent = CreateDefaultSubobject<USceneComponent>("TransformComponent");
	SetRootComponent(TransformComponent);
	
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(TransformComponent);
}

void AMBMeleeItem::GrantAbilitiesToActor(AActor* Actor)
{
	Super::GrantAbilitiesToActor(Actor);

	if(ComboAttackData != nullptr)
	{
		if(const auto abilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor))
		{
			for(const auto ability : ComboAttackData->ComboAbilities)
			{
				//TODO remove ability on unequip item
				abilitySystemComponent->GiveAbility(FGameplayAbilitySpec(ability));
			}
		}	
	}
}
