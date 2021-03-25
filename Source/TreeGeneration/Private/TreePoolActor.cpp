// Fill out your copyright notice in the Description page of Project Settings.


#include "TreePoolActor.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"

// Sets default values
ATreePoolActor::ATreePoolActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	TreeMesh = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("TreeStaticMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	TreeMesh->SetStaticMesh(MAsset);

	MAsset = MeshAsset.Object;

	RootComponent = TreeMesh;
}

// Called when the game starts or when spawned
void ATreePoolActor::BeginPlay()
{
	Super::BeginPlay();
	
	TreeMesh->SetStaticMesh(MAsset);
}

void ATreePoolActor::SetTreeProperties(float positionX, float positionY, float positionZ, float height, float canopyRadius)
{
	if (!TreeMesh->GetStaticMesh())
	{
		UE_LOG(LogTemp, Error, TEXT("Static mesh for instanced component was not set in TreeSpawner!"));
		return;
	}
		FVector StaticMeshSize = TreeMesh->GetStaticMesh()->GetBoundingBox().GetExtent();
		TreeCanopyRadius = (StaticMeshSize.Y + StaticMeshSize.X) / 4;
		TreeLength = StaticMeshSize.Z;

		FVector TreeLocation = FVector(positionX, positionY, positionZ);
			// Scale the tree to match the canopy radius and height requirements. E.g., apply a ratio of the current static mesh
			// radius, to the desired one
			FVector TreeScale = FVector(canopyRadius / TreeCanopyRadius,
				canopyRadius / TreeCanopyRadius,
				height / TreeLength);

			TreeTransform = FTransform(FRotator::ZeroRotator, TreeLocation, TreeScale);
}


void ATreePoolActor::AddActorToWorld()
{
	TreeMesh->AddInstanceWorldSpace(TreeTransform);
}

