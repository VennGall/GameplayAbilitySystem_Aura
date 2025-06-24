// Copyright Venn Gall


#include "AbilitySystem/MMC/MMC_MaxMana.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntelligenceDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	IntelligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntelligenceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntelligenceDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvalParams;
	float Intelligence{ 0.f };
	GetCapturedAttributeMagnitude(IntelligenceDef, Spec, EvalParams, Intelligence);
	Intelligence = FMath::Max(Intelligence, 0.f); // Ensure Intelligence is not negative

	ICombatInterface* CombatInterface{ Cast<ICombatInterface>(Spec.GetContext().GetSourceObject()) };
	const int32 Level{ CombatInterface ? CombatInterface->GetLevel() : 1 };

	return 50.f + (2.5f * Intelligence) + (15.f * Level);
}
