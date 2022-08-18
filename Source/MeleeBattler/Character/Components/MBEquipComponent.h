#pragma once

#include "Components/ActorComponent.h"

#include "MBEquipComponent.generated.h"

class AMBMeleeItem;

UCLASS()
class UMBEquipComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void EquipItemClassToHand(TSubclassOf<AMBMeleeItem> NewItem);
	
	UFUNCTION(BlueprintCallable)
	void EquipItemToHand(AMBMeleeItem* NewItem);

	UFUNCTION(BlueprintPure)
	AMBMeleeItem* GetActiveItem() const;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName HandItemAttachSocketName;
	
private:
	UPROPERTY()
	AMBMeleeItem* ActiveItem;
};

