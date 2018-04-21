// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterDamageHandler.h"
#include "ZombieShooter.h"

UCharacterDamageInterface::UCharacterDamageInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void ICharacterDamageInterface::ReceiveDamage(float Damage)
{
	
}