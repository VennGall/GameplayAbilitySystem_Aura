// Copyright Venn Gall


#include "Character/AuraCharacter.h"
#include "Player/AuraPlayerState.h"
#include "Player/AuraPlayerController.h"
#include "UI/HUD/AuraHUD.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	SpringComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringComponent->SetupAttachment(GetRootComponent());
	SpringComponent->TargetArmLength = 750.f;
	SpringComponent->bEnableCameraLag = true;
	SpringComponent->bInheritPitch = false;
	SpringComponent->bInheritYaw = false;
	SpringComponent->bInheritRoll = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringComponent);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// InitAbilityActorInfo for the Server
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// InitAbilityActorInfo for the Client
	InitAbilityActorInfo();
}

int32 AAuraCharacter::GetLevel() const
{
	return GetPlayerState<AAuraPlayerState>()->GetPlayerLevel();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState{ GetPlayerState<AAuraPlayerState>() };
	check(AuraPlayerState);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
	AttributeSet = AuraPlayerState->GetAttributeSet();

	AAuraPlayerController* AuraPlayerController{ Cast<AAuraPlayerController>(GetController()) };
	if (AuraPlayerController)
	{
		if (AAuraHUD* AuraHUD{ Cast<AAuraHUD>(AuraPlayerController->GetHUD()) })
		{
			AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	InitialiseDefaultAttributes();
}
