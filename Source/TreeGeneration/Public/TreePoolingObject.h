// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <random>
#include "TreePoolActor.h"
#include "TreePoolingObject.generated.h"

/**
 * 
 */
 using namespace std;
 USTRUCT()
	 struct FTreeStruct
 {
	 GENERATED_BODY()

	 float positionX;
	 float positionY;
	 float positionZ;
	 float height;
	 float canopyRadius;
 };


UCLASS()
class TREEGENERATION_API UTreePoolingObject : public UObject
{
	GENERATED_BODY()

	public:

	UTreePoolingObject(const FObjectInitializer& ObjectInitializer);

	TArray<FTreeStruct> treePool;

	uint32 TotaltreeSize;

	void CreateRandomGeneratedTrees(uint32 TotaltreeCount);	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	ATreeSpawnActor* treeSpawnInstanceMeshActor;

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	TArray<float>& GetPooledObjectDetails(int TreeIndex);

	TArray<float> TreeDetails;

};
