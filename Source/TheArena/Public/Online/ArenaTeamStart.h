// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerStart.h"
#include "ArenaTeamStart.generated.h"

/**
 * 
 */
UCLASS()
class THEARENA_API AArenaTeamStart : public APlayerStart
{
	GENERATED_BODY()

	AArenaTeamStart(const class FObjectInitializer& PCIP);

public:
	
	/** Which team can start at this point */
	UPROPERTY(EditInstanceOnly, Category = Team)
	int32 SpawnTeam;

	/** Whether players can start at this point */
	UPROPERTY(EditInstanceOnly, Category = Team)
	uint32 bNotForPlayers : 1;

	/** Whether bots can start at this point */
	UPROPERTY(EditInstanceOnly, Category = Team)
	uint32 bNotForBots : 1;
	
};
