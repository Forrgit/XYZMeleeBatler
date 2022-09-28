#include "MBPlayerCharacter.h"

void AMBPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &AMBPlayerCharacter::InputStartAttack);
	PlayerInputComponent->BindAction("Attack", EInputEvent::IE_Released, this, &AMBPlayerCharacter::InputStopAttack);

}

void AMBPlayerCharacter::InputStartAttack()
{
	StartAttack();
}

void AMBPlayerCharacter::InputStopAttack()
{
	StopAttack();
}