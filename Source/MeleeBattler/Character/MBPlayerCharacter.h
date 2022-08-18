#pragma once

#include "MBBaseCharacter.h"

#include "MBPlayerCharacter.generated.h"

UCLASS()
class AMBPlayerCharacter : public AMBBaseCharacter
{
	GENERATED_BODY()
public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void InputAttack();
};
