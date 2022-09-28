#pragma once

#include "MBItem.h"

#include "MBMeleeItem.generated.h"

class USkeletalMeshComponent;
class UMBComboAttackData;

UCLASS(Abstract)
class AMBMeleeItem : public AMBItem
{
	GENERATED_BODY()
public:
	AMBMeleeItem();

	virtual void GrantAbilitiesToActor(AActor* Actor) override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Attack")
	UMBComboAttackData* ComboAttackData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equip")
	FName AttachSocketName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* TransformComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* MeshComponent;
};

