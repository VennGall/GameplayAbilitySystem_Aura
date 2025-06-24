// Copyright Venn Gall

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
	
public:
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/* - Combat Interface - */
	virtual int32 GetLevel() const override;

private:
	virtual void InitAbilityActorInfo() override;

	/* Components */
	UPROPERTY(EditAnywhere, Category = Camera)
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditAnywhere, Category = Camera)
	TObjectPtr<USpringArmComponent> SpringComponent;
};
