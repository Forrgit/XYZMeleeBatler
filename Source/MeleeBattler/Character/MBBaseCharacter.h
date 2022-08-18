#pragma once

#include "Abilities/GameplayAbility.h"
#include "GameFramework/Character.h"

#include "MBBaseCharacter.generated.h"

class UMBComboAttackComponent;
class UMBEquipComponent;
class UAbilitySystemComponent;

UCLASS()
class AMBBaseCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	AMBBaseCharacter();

	UFUNCTION(BlueprintCallable)
	void UseAbility(TSubclassOf<UGameplayAbility> Ability);
	
	UFUNCTION(BlueprintCallable)
	void Attack();

	UFUNCTION(BlueprintPure)
	bool CanAttack() const;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBEquipComponent* EquipComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBComboAttackComponent* ComboAttackComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystemComponent;
};

