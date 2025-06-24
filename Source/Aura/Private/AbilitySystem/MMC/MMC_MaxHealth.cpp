// Copyright Venn Gall


#include "AbilitySystem/MMC/MMC_MaxHealth.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	VigorDef.AttributeToCapture = UAuraAttributeSet::GetVigorAttribute();
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VigorDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(VigorDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// You can acquire the tags captured from both the source and target of the effect through the Spec.
	// You can do it like this: Spec.CapturedSourceTags.GetAggregatedTags() or Spec.CapturedTargetTags.GetAggregatedTags() - they need to be stored in FGameplayTagContainer.
	// In this case, we only need the target's Level and Vigor attribute to calculate Max Health.
	// If you do need the tags, you can add them to EvalParams and use them in the calculation.

	FAggregatorEvaluateParameters EvalParams;
	float Vigor{ 0.f };
	GetCapturedAttributeMagnitude(VigorDef, Spec, EvalParams, Vigor);
	Vigor = FMath::Max(Vigor, 0.f); // Ensure Vigor is not negative

	ICombatInterface* CombatInterface{ Cast<ICombatInterface>(Spec.GetContext().GetSourceObject()) };
	const int32 Level{ CombatInterface ? CombatInterface->GetLevel() : 1 };

	return 80.f + (Vigor * 2.5f) + (10.f * Level);
}
