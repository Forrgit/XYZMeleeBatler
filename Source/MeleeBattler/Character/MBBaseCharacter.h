#pragma once

#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "GameFramework/Character.h"

#include "MBBaseCharacter.generated.h"

class UMBCharacterTargetingComponent;
class UMBCharacterAttributeSet;
class UMBComboAttackComponent;
class UMBEquipComponent;
class UBMAttackAbility;
class UAbilitySystemComponent;

UCLASS()
class AMBBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AMBBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	
	UFUNCTION(BlueprintCallable)
	void UseAbility(TSubclassOf<UGameplayAbility> Ability);
	
	UFUNCTION(BlueprintCallable)
	void StartAttack();

	UFUNCTION(BlueprintCallable)
	void StopAttack();

	UFUNCTION(BlueprintPure)
	bool CanAttack() const;
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBMAttackAbility> AttackAbility;

	UPROPERTY()
	UMBCharacterAttributeSet* CharacterAttributeSet; 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBEquipComponent* EquipComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBComboAttackComponent* ComboAttackComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBCharacterTargetingComponent* TargetingComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystemComponent;
};

