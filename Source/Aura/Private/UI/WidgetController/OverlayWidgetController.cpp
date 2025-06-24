// Copyright Venn Gall


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "UI/Widget/AuraUserWidget.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet{ CastChecked<UAuraAttributeSet>(AttributeSet) };

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet{ CastChecked<UAuraAttributeSet>(AttributeSet) };

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddLambda(
		[&](const FOnAttributeChangeData& Data){ OnHealthChanged.Broadcast(Data.NewValue); }
	);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[&](const FOnAttributeChangeData& Data) { OnMaxHealthChanged.Broadcast(Data.NewValue); }
	);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).AddLambda(
		[&](const FOnAttributeChangeData& Data) { OnManaChanged.Broadcast(Data.NewValue); }
	);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).AddLambda(
		[&](const FOnAttributeChangeData& Data) { OnMaxManaChanged.Broadcast(Data.NewValue); }
	);

	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[&](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// Check if the tag matches the "Message" tag. Will return true even if the tag is "Message.SomeOtherTag"
				if (Tag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("Message"))))
				{
					const FUIWidgetRow* Row{ GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag) };
					if (!Row) continue;
					MessageWidgetRow.Broadcast(*Row);
				}
			}
		}
	);
}