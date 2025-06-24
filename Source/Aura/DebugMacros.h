#pragma once

#define PRINT_ONSCREEN_DEBUG(Key, Message) \
{ \
	if (GEngine) \
	{ \
		GEngine->AddOnScreenDebugMessage(Key, 5.f, FColor::Red, Message); \
	} \
}