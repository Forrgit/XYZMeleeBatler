#include "MBHealthTargetFactor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "MeleeBattler/Abilities/MBCharacterAttributeSet.h"

TArray<AActor*> UMBHealthTargetFactor::GetHighPriorityActors_Implementation(
	const TArray<AActor*>& TestActors, bool bEnableDebug) const
{
	AActor* actorWithLowestHealth = nullptr;
	float minHealth = 0.f;
	for(const auto testActor : TestActors)
	{
		if(testActor != nullptr)
		{
			bool bFoundAttribute = false;
			const float health = UAbilitySystemBlueprintLibrary::GetFloatAttribute(testActor, UMBCharacterAttributeSet::GetHealthAttribute(),bFoundAttribute);

			if(bFoundAttribute && (actorWithLowestHealth == nullptr || minHealth >health))
			{
				actorWithLowestHealth = testActor;
				minHealth = health;
			}
		}
	}
	return { actorWithLowestHealth };
}
