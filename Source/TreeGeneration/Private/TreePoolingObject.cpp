// Fill out your copyright notice in the Description page of Project Settings.
#include "TreePoolingObject.h"

UTreePoolingObject::UTreePoolingObject(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer)
{
	TotaltreeSize = 1000;
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
		UWorld* const World = GetWorld();
		if (World) 
		{
			FActorSpawnParameters SpawnInfo;
			ATreePoolActor* poolActor = World->SpawnActor<ATreePoolActor>(FVector().ZeroVector, FRotator().ZeroRotator, SpawnInfo);
			poolActor->SetTreeProperties();
			poolActor->bisAvailable = false;
			TreePool.Add(poolActor);
		}
	}

	/*return treePool;*/
}

ATreePoolActor * UTreePoolingObject::GetPooledObject()
{
	for (ATreePoolActor* PoolableActor : TreePool)
	{
		if (!PoolableActor->bisAvailable) {
			return PoolableActor;
		}
	}
	/* pool is drained, no inactive objects found */
	return nullptr;
}

