// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnLifeChanged, float Health, float MaxHealth)
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENTREGAOBLIGATORIA1_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Health = 100.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MinHealth = true;

	UFUNCTION(BlueprintCallable)
	void UpdateHealth(int HealthPoints);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FOnLifeChanged OnLifeChanged;
	
};
