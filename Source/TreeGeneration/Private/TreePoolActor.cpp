// Fill out your copyright notice in the Description page of Project Settings.


#include "TreePoolActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"

// Sets default values
ATreePoolActor::ATreePoolActor(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	TreeMesh = ObjectInitializer.CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(this,TEXT("TreeStaticMesh"));
}

// Called when the game starts or when spawned
void ATreePoolActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATreePoolActor::SetTreeProperties()
{
	if (TreeMesh->GetStaticMesh())
	{
		FVector StaticMeshSize = TreeMesh->GetStaticMesh()->GetBoundingBox().GetExtent();
	}
	
}

void ATreePoolActor::AddActorToWorld()
{
	//TreeMesh->AddInstanceWorldSpace(Transform);
}

