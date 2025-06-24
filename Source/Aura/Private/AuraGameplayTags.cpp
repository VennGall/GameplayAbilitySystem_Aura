// Copyright Venn Gall


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitialiseNativeGameplayTags()
{
	// Primary Attributes
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength")
		, FString("Increases the physical damage."));
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence")
		, FString("Increases the magical damage, and Max Mana."));
	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience")
		, FString("Increases Armour and Armour Penetration"));
	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vigor")
		, FString("Increases Max Health."));

	// Secondary Attributes
	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth")
		, FString("Increases the maximum limit of Health."));
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana")
		, FString("Increases the maximum limit of Mana."));
	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegeneration")
		, FString("Amount of Health regenerated per second."));
	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegeneration")
		, FString("Amount of Mana regenerated per second."));
	GameplayTags.Attributes_Secondary_Armour = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armour")
		, FString("Reduces damage taken, and improves Block Chance."));
	GameplayTags.Attributes_Secondary_ArmourPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmourPenetration")
		, FString("Ignores a percentage of the target's Armour, and increases Critical Hit Chance."));
	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance")
		, FString("Chance to block incoming damage, reducing it by half."));
	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance")
		, FString("Chance to deal critical damage (damage multiplied by Critical Hit Damage) on a hit."));
	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage")
		, FString("Multiplier that increases the damage dealt on a critical hit."));
	GameplayTags.Attributes_Secondary_CriticalResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalResistance")
		, FString("Reduces the probability of taking critical hits from enemies."));
}
