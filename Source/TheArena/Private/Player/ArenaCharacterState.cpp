// Fill out your copyright notice in the Description page of Project Settings.

#include "TheArena.h"
#include "Net/UnrealNetwork.h"
#include "ArenaCharacterState.h"

UArenaCharacterState::UArenaCharacterState(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	SetIsReplicated(true);
	bReplicates = true;

	PlayerState = EPlayerState::Default;
	CoverState = ECoverState::Default;
	CombatState = ECombatState::Passive;
}

void UArenaCharacterState::Reset()
{
	PlayerState = EPlayerState::Default;
	CoverState = ECoverState::Default;
	CombatState = ECombatState::Passive;
}

class AArenaCharacter* UArenaCharacterState::GetMyPawn() const
{
	return MyPawn;
}
void UArenaCharacterState::SetMyPawn(AArenaCharacter* Pawn)
{
	MyPawn = Pawn;
}

bool UArenaCharacterState::GetIsNearCover() const
{
	return IsNearCover;
}
void UArenaCharacterState::SetIsNearCover(bool Value)
{
	IsNearCover = Value;
}

bool UArenaCharacterState::GetIsNearLeftEdge() const
{
	return IsNearLeftEdge;
}
void UArenaCharacterState::SetIsNearLeftEdge(bool Value)
{
	IsNearLeftEdge = Value;
}

bool UArenaCharacterState::GetIsNearRightEdge() const
{
	return IsNearRightEdge;
}
void UArenaCharacterState::SetIsNearRightEdge(bool Value)
{
	IsNearRightEdge = Value;
}

bool UArenaCharacterState::GetCanClimb() const
{
	return CanClimb;
}
void UArenaCharacterState::SetCanClimb(bool Value)
{
	CanClimb = Value;
}

bool UArenaCharacterState::GetCanVault() const
{
	return CanVault;
}
void UArenaCharacterState::SetCanVault(bool Value)
{
	CanVault = Value;
}

EPlayerState::Type UArenaCharacterState::GetPlayerState() const
{
	return PlayerState;
}
void UArenaCharacterState::SetPlayerState(EPlayerState::Type State)
{
	PlayerState = State;
}

ECoverState::Type UArenaCharacterState::GetCoverState() const
{
	return CoverState;
}
void UArenaCharacterState::SetCoverState(ECoverState::Type State)
{
	CoverState = State;
}

ECombatState::Type UArenaCharacterState::GetCombatState() const
{
	return CombatState;
}
void UArenaCharacterState::SetCombatState(ECombatState::Type NewState)
{
	CombatState = NewState;
}

void UArenaCharacterState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UArenaCharacterState, PlayerState);
	DOREPLIFETIME(UArenaCharacterState, CoverState);
	DOREPLIFETIME(UArenaCharacterState, CombatState);
}
