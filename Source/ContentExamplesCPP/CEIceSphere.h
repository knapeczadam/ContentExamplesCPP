#pragma once

#include "CoreMinimal.h"
#include "CEElementalProjectiles.h"
#include "GameFramework/Actor.h"
#include "CEIceSphere.generated.h"

UENUM()
enum class ECEIceSphereStaticMesh
{
	Sphere
};

UENUM()
enum class ECEIceSphereParticleSystem
{
	IceSteam,
    SteamPuff,
    WaterDrips
};

UENUM()
enum class ECEIceSphereMaterial
{
	IceInteractive
};

UCLASS()
class CONTENTEXAMPLESCPP_API ACEIceSphere : public AActor, public ICEElementalProjectiles
{
	GENERATED_BODY()

	UPROPERTY()
	USceneComponent* Base;

	UPROPERTY()
	UStaticMeshComponent* IceSphere;

	UPROPERTY()
	UParticleSystemComponent* Drips;

	UPROPERTY()
	UParticleSystemComponent* Steam;

	UPROPERTY()
	UMaterialInstanceDynamic* IceMaterial;

	float Melted;

	float Wetness;

	float Icicles;

	float Heat;
	
	UPROPERTY()
	TMap<ECEIceSphereMaterial, UMaterialInterface*> Materials;

	UPROPERTY()
	TMap<ECEIceSphereParticleSystem, UParticleSystem*> ParticleSystems;

	UPROPERTY()
	TMap<ECEIceSphereStaticMesh, UStaticMesh*> StaticMeshes;

private:
	void InitializeAssets();

	void InitializeMaterials();

	void InitializeParticleSystems();

	void InitializeStaticMeshes();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ACEIceSphere();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void ElementalDamage(float HeatDamage, float WaterDamage) override;
};