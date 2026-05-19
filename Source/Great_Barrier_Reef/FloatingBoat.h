#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingBoat.generated.h"

UCLASS()
class GREAT_BARRIER_REEF_API AFloatingBoat : public AActor
{
    GENERATED_BODY()

public:
    AFloatingBoat();
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating")
    float BobHeight = 30.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating")
    float BobSpeed = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating")
    float TiltAmount = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floating")
    float TiltSpeed = 0.8f;

protected:
    virtual void BeginPlay() override;

private:
    FVector StartLocation;
    float TimeCounter = 0.0f;
};
