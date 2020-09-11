// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CELEDBasic.h"
#include "CEPlayerInteractions.h"
#include "GameFramework/Actor.h"
#include "CEInteractiveCrank.generated.h"

UENUM()
enum class ECEInteractiveCrankMaterial
{
	OpaqueEmissive,
    OrangeShiny
};

UENUM()
enum class ECEInteractiveCrankStaticMesh
{
	Crank,
	Wheel
};

UCLASS()
class CONTENTEXAMPLESCPP_API ACEInteractiveCrank : public AActor, public ICEPlayerInteractions
{
	GENERATED_BODY()

	UPROPERTY()
	UStaticMeshComponent* WheelBase;

	UPROPERTY()
	UStaticMeshComponent* Wheel;

	UPROPERTY()
	UStaticMeshComponent* WheelHighlighted;

	UPROPERTY()
	class UBoxComponent* InteractTrigger;

	UPROPERTY()
	class UTextRenderComponent* TextRender1;

	float Rotation;

	FVector PlayerDragInteraction;

	UPROPERTY(EditAnywhere)
	class ACELEDBasic* TargetLED;

	float TotalRotation;

	UPROPERTY()
	TMap<ECEInteractiveCrankMaterial, UMaterialInterface*> Materials;

	UPROPERTY()
	TMap<ECEInteractiveCrankStaticMesh, UStaticMesh*> StaticMeshes;

private:
	void InitializeAssets();

	void InitializeStaticMeshes();

	void InitializeMaterials();

	UFUNCTION()
	void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ACEInteractiveCrank();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual FVector GrabInteract(FVector2D PlayerAimMovement, bool bIsInteracting) override;
};