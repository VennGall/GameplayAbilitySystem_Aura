// Copyright Venn Gall

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Templates/UniquePtr.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

struct FGameplayEffectModCallbackData;
struct FGameplayEffectContextHandle;

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() {};

	UPROPERTY()
	FGameplayEffectContextHandle EffectContextHandle;
	
	UPROPERTY()
	UAbilitySystemComponent* SourceASC;

	UPROPERTY()
	AActor* SourceAvatarActor;

	UPROPERTY()
	AController* SourceController;

	UPROPERTY()
	ACharacter* SourceCharacter;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC;

	UPROPERTY()
	AActor* TargetAvatarActor;

	UPROPERTY()
	AController* TargetController;

	UPROPERTY()
	ACharacter* TargetCharacter;
};

UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	/*
	** - Vital Attributes
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes");
	FGameplayAttributeData Health;
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);		// Generates getters and setters for Health according to macros defined at the top. Note: Init is for setting both values at same time

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes");
	FGameplayAttributeData Mana;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	/*
	** - Primary Attributes
	*/
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
	FGameplayAttributeData Resilience;
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Attributes")
	FGameplayAttributeData Vigor;
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor);

	/*
	** - Secondary Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes");
	FGameplayAttributeData MaxHealth;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes");
	FGameplayAttributeData MaxMana;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Vital Attributes");
	FGameplayAttributeData HealthRegeneration;
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegeneration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Vital Attributes");
	FGameplayAttributeData ManaRegeneration;
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegeneration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armour, Category = "Vital Attributes");
	FGameplayAttributeData Armour;
	UFUNCTION()
	void OnRep_Armour(const FGameplayAttributeData& OldArmour) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armour);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Vital Attributes");
	FGameplayAttributeData BlockChance;
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmourPenetration, Category = "Vital Attributes");
	FGameplayAttributeData ArmourPenetration;
	UFUNCTION()
	void OnRep_ArmourPenetration(const FGameplayAttributeData& OldArmourPenetration) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmourPenetration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalChance, Category = "Vital Attributes");
	FGameplayAttributeData CriticalChance;
	UFUNCTION()
	void OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalDamage, Category = "Vital Attributes");
	FGameplayAttributeData CriticalDamage;
	UFUNCTION()
	void OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalResistance, Category = "Vital Attributes");
	FGameplayAttributeData CriticalResistance;
	UFUNCTION()
	void OnRep_CriticalResistance(const FGameplayAttributeData& OldCriticalResistance) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalResistance);

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
