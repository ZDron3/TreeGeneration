// Fill out your copyright notice in the Description page of Project Settings.
#include "TreePoolingObject.h"
#include "Engine/World.h"

UTreePoolingObject::UTreePoolingObject(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	TotaltreeSize = 100000;
	FActorSpawnParameters SpawnLocation;
	UWorld* world = GetWorld();
	if (world)
	{
		FActorSpawnParameters SpawnInfo;

		FRotator myRot(0, 0, 0);
		FVector myLoc(0, 0, 100);
		treeSpawnInstanceMeshActor = GetWorld()->SpawnActor<ATreeSpawnActor>( myLoc, myRot, SpawnInfo);
	}
}

void UTreePoolingObject::CreateRandomGeneratedTrees(uint32 TotaltreeCount)
{
	treePool.Reserve(TotaltreeCount);
	std::default_random_engine generator;
	std::uniform_real_distribution<float> positionDistribution(0.0, 100000.0);
	std::uniform_real_distribution<float> heightDistribution(2.0, 10000.0);
	std::uniform_real_distribution<float> canopyRadiusDistribution(1.0, 5000.0);

	for (uint32 i = 0; i < TotaltreeCount; i++)
	{
		FTreeStruct treestruct;
		treestruct.positionX = positionDistribution(generator);
		treestruct.positionY = positionDistribution(generator);
		treestruct.positionZ = positionDistribution(generator);
		treestruct.height = heightDistribution(generator);
		treestruct.canopyRadius = canopyRadiusDistribution(generator);
		treePool.Add(treestruct);
		if (treeSpawnInstanceMeshActor)
		{
			treeSpawnInstanceMeshActor->SetTreePropertiesAndRender(treestruct.positionX, treestruct.positionY, treestruct.positionZ, treestruct.height, treestruct.canopyRadius);
		}

	}
}

TArray<float>& UTreePoolingObject::GetPooledObjectDetails(int TreeIndex)
{
	if (TreeIndex != -1)
	{
		TreeDetails.Empty();
		TreeDetails.Add(treePool[TreeIndex].height);
		TreeDetails.Add(treePool[TreeIndex].canopyRadius);
	}
	return TreeDetails;
}

