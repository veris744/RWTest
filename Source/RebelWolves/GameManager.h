// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class REBELWOLVES_API UGameManager : public UObject
{
	GENERATED_BODY()

		static UGameManager* Instance;


	UPROPERTY();
	TArray<ABird*> AllBirds;

	UPROPERTY();
	TArray<ARebelWolvesProjectile*> AllPredators;


	UPROPERTY(Transient)
		class URWUserWidget* HUDWidget;


	FTimerHandle TimerHandleTutorial;
	float TutorialTime = 7;

	const float kCohesion = 200;
	const float kSeparation = 350;
	const float kAlignment = 100;
	const float kAvoidance = 10000;
	FVector MapCenter = FVector::ZeroVector;
	FVector CharacterStart;
	FVector2D BuildingDimentions = FVector2D(700, 700);
	float BuildingMargin = 200;
	float HeightMargin = 1000;

public:
	UGameManager()
	{
		Instance = this;
	}


	/////////////////////////////////////////////////////////////////
	/////						MANAGING						/////
	/////////////////////////////////////////////////////////////////


	static UGameManager* GetGameManager();

	FVector2D Size;
	int MaxHeight;
	TArray<float> BuildingHeights;

	inline float GetCohesionFactor() const { return kCohesion; };
	inline float GetSeparationFactor() const { return kSeparation; };
	inline float GetAlignmentFactor() const { return kAlignment; };
	inline float GetAvoidanceFactor() const { return kAvoidance; };
	inline FVector GetMapCenter() const { return MapCenter; };
	inline FVector GetCharacterStart() const { return CharacterStart; };


	UFUNCTION()
		void AddBird(ABird* _bird);

	UFUNCTION()
		void RemoveBird(ABird* _bird);

	UFUNCTION()
		ABird* GetBird(int i);

	UFUNCTION()
		inline int GetNumBird() { return AllBirds.Num(); };


	UFUNCTION()
		void AddPredator(ARebelWolvesProjectile* _predator);

	UFUNCTION()
		void RemovePredator(ARebelWolvesProjectile* _predator);

	UFUNCTION()
		ARebelWolvesProjectile* GetPredator(int i);

	UFUNCTION()
		inline int GetNumPredator() { return AllPredators.Num(); };


	/////////////////////////////////////////////////////////////////
	/////						GAME FLOW						/////
	/////////////////////////////////////////////////////////////////


	UFUNCTION()
		FVector ReversalBehavior(FVector Location, FVector _Velocity, float LookAhead, bool CheckUp);

	UFUNCTION()
		void PrepareforMenu();

	UFUNCTION()
		void StartGame();

	UFUNCTION()
		bool SetConfiguration();

	UFUNCTION()
		void LoadLevel();

	UFUNCTION()
		void HideTutorial();

	/////////////////////////////////////////////////////////////////
	/////							UI							/////
	/////////////////////////////////////////////////////////////////


	UFUNCTION()
		void UpdateAmmoUI(int ammo);

	void SetHudWidget(URWUserWidget* _HUDWidget) { HUDWidget = _HUDWidget; };

	/////////////////////////////////////////////////////////////////
	/////						SPAWNING						/////
	/////////////////////////////////////////////////////////////////


	UPROPERTY()
		TSubclassOf<class ABird> BirdClass;

	UPROPERTY()
		TSubclassOf<class AActor> BuildingClass;

	UPROPERTY()
		TSubclassOf<class AActor> FloorClass;

	UFUNCTION()
		void TransformPredator(ARebelWolvesProjectile* predator);


};
