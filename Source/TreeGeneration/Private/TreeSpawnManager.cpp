// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeSpawnManager.h"

// Sets default values
ATreeSpawnManager::ATreeSpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	ActorPooler = CreateDefaultSubobject<UTreePoolingObject>(TEXT("ActorPooler"));
	TotalTreesCount = 100000;
}

// Called when the game starts or when spawned
void ATreeSpawnManager::BeginPlay()
{
	Super::BeginPlay();	
	SpawnTrees();
}


void ATreeSpawnManager::SpawnTrees()
{
	ActorPooler->CreateRandomGeneratedTrees(TotalTreesCount);
}

