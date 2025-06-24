// Copyright Venn Gall


#include "Player/AuraPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Interaction/InteractionInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}


void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem{ ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()) };
	if (Subsystem) 
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent{ CastChecked<UEnhancedInputComponent>(InputComponent) };
	
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
	
	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	// Line trace from cursor. There are several scenarios:
	// A. LastActor null && ThisActor null									- Do Nothing
	// B. LastActor null && ThisActor valid									- Highlight ThisActor
	// C. LastActor valid && ThisActor null									- UnHighlight LastActor
	// D. LastActor valid && ThisActor valid && LastActor != ThisActor		- UnHighlight LastActor, Highlight ThisActor
	// E. LastAcotr valid && ThisActor valid								- Do Nothing

	if (!LastActor)
	{
		if (ThisActor)						// Case B
		{
			ThisActor->HighlighActor();
		}
		else								// Case A
		{
		}
	}
	else			// LastActor is valid
	{
		if (!ThisActor)						// Case C
		{
			LastActor->UnHighlightActor();
		}
		else		// Both valid
		{
			if (LastActor != ThisActor)		// Case D
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlighActor();
			}
			else							// Case E
			{
			}	
		}
	}
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector{ InputActionValue.Get<FVector2D>() };
	const FRotator YawRotation{ 0.f, GetControlRotation().Yaw, 0.f };
	const FVector ForwardDirection{ FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X) };
	const FVector RightDirection{ FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y) };

	if (APawn * ControlledPawn{ GetPawn<APawn>() })
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
