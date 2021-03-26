// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreePoolActor.generated.h"

UCLASS()
class TREEGENERATION_API ATreeSpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATreeSpawnActor();

protected:

public:	
	// Called every frame
	
	//Tree Specific Properties

	/** We use HierarchicalInstancedStaticMeshComponent instead of Instancedstaticmesh for our static mesh as this
	reduces the draw calls by drawing in batches but maintaining the LOD integrity at the same time*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UHierarchicalInstancedStaticMeshComponent* TreeMesh;

private:
	float TreeRadiusScaleFactor;

	float TreeLengthScaleFactor;

public:

	//Functions
	UFUNCTION(BlueprintCallable,Category="SetProperties")
	void SetTreePropertiesAndRender(float positionX, float positionY, float positionZ, float height, float canopyRadius); //replace with tree struct later

};
