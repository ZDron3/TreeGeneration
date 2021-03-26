// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreePoolingObject.h"
#include "TreeSpawnManager.generated.h"

UCLASS()
class TREEGENERATION_API ATreeSpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATreeSpawnManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintCallable, Category ="SpawnTree")
	void SpawnTrees();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	UTreePoolingObject* ActorPooler;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Spawner")
	int TotalTreesCount;

};
