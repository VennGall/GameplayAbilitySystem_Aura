// Copyright Venn Gall

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class AURA_API IInteractionInterface
{
	GENERATED_BODY()

public:
	virtual void HighlighActor() = 0;
	virtual void UnHighlightActor() = 0;
};
