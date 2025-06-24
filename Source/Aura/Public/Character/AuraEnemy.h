// Copyright Venn Gall

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/InteractionInterface.h"
#include "AuraEnemy.generated.h"

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IInteractionInterface
{
	GENERATED_BODY()
	
public:
	AAuraEnemy();

	/* - Interaction Interface - */
	virtual void HighlighActor() override;
	virtual void UnHighlightActor() override;

	/* - Combat Interface - */
	virtual int32 GetLevel() const override { return Level; }

protected:
	void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level{ 1 };	
};
