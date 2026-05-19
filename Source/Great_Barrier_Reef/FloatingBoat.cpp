#include "FloatingBoat.h"

AFloatingBoat::AFloatingBoat()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AFloatingBoat::BeginPlay()
{
    Super::BeginPlay();
    StartLocation = GetActorLocation();
}

void AFloatingBoat::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Increase time counter every frame
    TimeCounter += DeltaTime * BobSpeed;

    // Calculate new Z position using Sin wave
    float NewZ = StartLocation.Z + (FMath::Sin(TimeCounter) * BobHeight);

    // Move boat up and down
    FVector NewLocation = FVector(
        StartLocation.X,
        StartLocation.Y,
        NewZ
    );
    SetActorLocation(NewLocation);

    // Tilt the boat side to side
    float NewRoll = FMath::Sin(TimeCounter * TiltSpeed) * TiltAmount;
    FRotator NewRotation = GetActorRotation();
    NewRotation.Roll = NewRoll;
    SetActorRotation(NewRotation);
}
