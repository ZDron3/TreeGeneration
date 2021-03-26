// Fill out your copyright notice in the Description page of Project Settings.


#include "TreePoolActor.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"

// Sets default values
ATreeSpawnActor::ATreeSpawnActor()
{
	if (!TreeMesh)
	{
		TreeMesh = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("TreeStaticMesh"));

		static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/FBX/TreeMesh.TreeMesh'"));

		TreeMesh->SetStaticMesh(MeshAsset.Object);

		RootComponent = TreeMesh;

		TreeMesh->InstanceStartCullDistance = 100000;

		TreeMesh->InstanceEndCullDistance = 10000;

		TreeMesh->bUseAsOccluder = true;
	}
}

void ATreeSpawnActor::SetTreePropertiesAndRender(float positionX, float positionY, float positionZ, float height, float canopyRadius)
{

	if(!TreeMesh->GetStaticMesh())
	{
		UE_LOG(LogTemp, Error, TEXT("Static Mesh not set in Hierarchical Instanced Static Mesh reference"));
		return;
	}
	FVector TreeMeshExtent = TreeMesh->GetStaticMesh()->GetBoundingBox().GetExtent();

	int TreeRadiusExtent = TreeMeshExtent.X *0.5;

	int TreeLengthExtent = TreeMeshExtent.Z;

	TreeRadiusScaleFactor = (canopyRadius / TreeRadiusExtent);

	TreeLengthScaleFactor = (height / TreeLengthExtent);

	FVector TreeLocation = FVector(positionX, positionY, positionZ);
		
	FVector TreeScale = FVector(TreeRadiusScaleFactor, TreeRadiusScaleFactor, TreeLengthScaleFactor);

	TreeMesh->AddInstanceWorldSpace(FTransform(FRotator::ZeroRotator, TreeLocation, TreeScale));
}

		
