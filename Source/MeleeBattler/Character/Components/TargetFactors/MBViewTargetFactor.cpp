#include "MBViewTargetFactor.h"

#include "DrawDebugHelpers.h"

TArray<AActor*> UMBViewTargetFactor::GetHighPriorityActors_Implementation(
	const TArray<AActor*>& TestActors, bool bEnableDebug) const
{
	if(const auto actorOwner = GetTypedOuter<AActor>())
	{
		const FVector forwardVector = actorOwner->GetActorForwardVector();
		
		if(bEnableDebug)
		{
			const FVector lineStart = actorOwner->GetActorLocation();
			const float drawDistance = 250.f;
			const float lineThickness = 16.f;

			FRotator lineViewRotation(0.f, MaxViewAngle / 2, 0.f);
			const FVector rightLineDirection = lineViewRotation.RotateVector(forwardVector);
			::DrawDebugLine(actorOwner->GetWorld(), lineStart,lineStart + rightLineDirection * drawDistance, FColor::Orange, false, 0, lineThickness);
			
			lineViewRotation.Yaw *= -1.f;
			const FVector leftLineDirection = lineViewRotation.RotateVector(forwardVector);
			::DrawDebugLine(actorOwner->GetWorld(), lineStart,lineStart + leftLineDirection * drawDistance, FColor::Orange, false, 0, lineThickness);
		}
	
		TArray<AActor*> priorityActors;
		for(const auto testActor : TestActors)
		{
			if(testActor != nullptr)
			{
				const FVector directionToTarget = (testActor->GetActorLocation() - actorOwner->GetActorLocation()).GetSafeNormal();

				const float angle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(forwardVector, directionToTarget)));
				if(angle <= MaxViewAngle / 2)
				{
					priorityActors.Add(testActor);
				}	
			}
		}

		return priorityActors;
	}
	
	return {};
}

