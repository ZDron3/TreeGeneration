// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreePoolActor.generated.h"

UCLASS()
class TREEGENERATION_API ATreePoolActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATreePoolActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	
	//Tree Specific Properties

	/** We use HierarchicalInstancedStaticMeshComponent instead of Instancedstaticmesh for our static mesh as this
	reduces the draw calls by drawing in batches but maintaining the LOD integrity at the same time*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UHierarchicalInstancedStaticMeshComponent* TreeMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float TreeLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TreeCanopyRadius;

	bool bisAvailable;

	FTransform TreeTransform;

	UStaticMesh* MAsset;

		//Functions

	/*UFUNCTION(BlueprintCallable, Category = "YourGame")
	FVector GetStaticMeshSize(class UStaticMesh* Mesh);
*/
	UFUNCTION(BlueprintCallable,Category="SetProperties")
	void SetTreeProperties(float positionX, float positionY, float positionZ, float height, float canopyRadius); //replace with tree struct later

	UFUNCTION(BlueprintCallable, Category = "SetProperties")
	void AddActorToWorld();
};
