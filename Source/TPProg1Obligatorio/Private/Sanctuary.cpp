// Fill out your copyright notice in the Description page of Project Settings.


#include "Sanctuary.h"

#include "HealthComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASanctuary::ASanctuary()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	RootComponent = TriggerZone;
	TriggerZone->SetCollisionProfileName(TEXT("Trigger"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ASanctuary::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetMaterial(0, AvailableMaterial);

}

// Called every frame
void ASanctuary::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ASanctuary::Interact_Implementation(AActor* Interactor)
{
	UE_LOG(LogTemp, Warning, TEXT("Sanctuary: Interact called"));

	if (!bIsAvailable)
	{
		UE_LOG(LogTemp, Warning, TEXT("Sanctuary: Not available (cooldown active)"));
		return;
	}

	if (!Interactor)
	{
		UE_LOG(LogTemp, Error, TEXT("Sanctuary: Interactor is null"));
		return;
	}

	
	APawn* Pawn = Cast<APawn>(Interactor);
	if (!Pawn)
	{
		UE_LOG(LogTemp, Error, TEXT("Sanctuary: Interactor is not a Pawn"));
		return;
	}

	UHealthComponent* HealthComp = Pawn->FindComponentByClass<UHealthComponent>();
	if (!HealthComp)
	{
		UE_LOG(LogTemp, Error, TEXT("Sanctuary: Pawn has no HealthComponent"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Sanctuary: Healing %s for %f"),
		*Pawn->GetName(),
		HealAmount);

	HealthComp->UpdateHealth(HealAmount);

	bIsAvailable = false;
	Mesh->SetMaterial(0, CooldownMaterial);
	UE_LOG(LogTemp, Warning, TEXT("Sanctuary: Entering cooldown (%f seconds)"), CoolDown);


	GetWorldTimerManager().SetTimer(
		CooldownTimer,
		this,
		&ASanctuary::ResetCooldownTimer,
		CoolDown,
		false
	);
}

void ASanctuary::ResetCooldownTimer()
{
	UE_LOG(LogTemp, Warning, TEXT("Sanctuary: Cooldown finished, available again"));

	bIsAvailable = true;
	Mesh->SetMaterial(0, AvailableMaterial);
	if (HasAuthority())
	{
		Multicast_PlaySanctuaryEffect();
	}
}

void ASanctuary::Multicast_PlaySanctuaryEffect_Implementation()
{
	UGameplayStatics::PlaySoundAtLocation(this, ActivateSound, GetActorLocation());
}