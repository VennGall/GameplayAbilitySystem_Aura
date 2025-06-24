#pragma once

#define PRINT_ONSCREEEN_DEBUG(Text, Key) \
	if (GEngine) \
	{ \
		GEngine->AddOnScreenDebugMessage(Key, 5.f, FColor::Red, Text); \
	}