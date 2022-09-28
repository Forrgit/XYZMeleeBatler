#include "MBCharacterTargetingComponent.h"

#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MeleeBattler/Character/MBBaseCharacter.h"
#include "TargetFactors/MBTargetFactor.h"

UMBCharacterTargetingComponent::UMBCharacterTargetingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

AActor* UMBCharacterTargetingComponent::GetTarget() const
{
	const FVector traceStart = GetOwner()->GetActorLocation();
	const FVector traceEnd = traceStart + FVector::OneVector;
	
	const TArray<AActor*> ignoreActors = { GetOwner() };
	TArray<FHitResult> hitResults;
	UKismetSystemLibrary::SphereTraceMulti(this, traceStart, traceEnd, MaxTargetRadius, TraceType, false, ignoreActors, EDrawDebugTrace::None, hitResults, true);

	TArray<AActor*> potentialTargets;
	for(const auto& hitResult : hitResults)
	{
		if(const auto character = Cast<AMBBaseCharacter>(hitResult.GetActor()))
		{
			potentialTargets.Add(character);
		}
	}

	if(potentialTargets.Num() == 0)
	{
		return nullptr;
	}
	
	for(const auto targetFactor : TargetFactors)
	{
		if(targetFactor != nullptr)
		{
			potentialTargets = targetFactor->GetHighPriorityActors(potentialTargets, bIsEnableDebug);
		}
	}

	if(potentialTargets.Num() != 0)
	{
		return potentialTargets[0];
	}
	return nullptr;
}

void UMBCharacterTargetingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(bIsEnableDebug)
	{
		DrawDebug();
	}
}

void UMBCharacterTargetingComponent::DrawDebug()
{
	if(const auto target = GetTarget())
	{
		::DrawDebugCircle(GetWorld(), GetOwner()->GetActorLocation(), MaxTargetRadius, 32, FColor::Green, false, -1, 0, 6.f, FVector(0, 1, 0), FVector(1, 0, 0));
		::DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), target->GetActorLocation(), FColor::Green, false);
	}
}
