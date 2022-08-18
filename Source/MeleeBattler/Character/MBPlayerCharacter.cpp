#include "MBPlayerCharacter.h"

void AMBPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &AMBPlayerCharacter::InputAttack);
}

void AMBPlayerCharacter::InputAttack()
{
	Attack();
}
