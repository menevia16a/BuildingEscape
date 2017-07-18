// Copyright 2017 Veilbreaker Entertainment

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpen);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClose);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		FOnOpen OnOpen;

	UPROPERTY(BlueprintAssignable)
		FOnClose OnClose;

private:
	//UPROPERTY is Unreal engine specific, read documentation.
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 0.f;

	float GetTotalMassOfActorsOnPlate(); //Returns total mass in kg

	AActor* Owner = nullptr;
};
