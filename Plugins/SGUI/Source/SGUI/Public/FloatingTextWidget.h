#pragma once

#include "Blueprint/UserWidget.h"
#include "FloatingTextWidget.generated.h"

/**
 *	Widget for floating text messages.
 *	As of the transient nature of the widget, it doesn't have the Create() method
 *	and won't return its intance. Instead, you will create messages by calling
 *	overloaded static Spawn() methods.
 *	The particular instances of the widget will be destroyed abutomatically.
 */
UCLASS()
class SGUI_API UFloatingTextWidget : public USagaWidget
{
	GENERATED_BODY()
	
public:
	/* Floating speed of the messages. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SagaGUI")
	float FloatingSpeed = 10.f;

	/* How fast the message will fade out. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SagaGUI")
	float FadeSpeed = 1.f;
	                                                                              
	/**
	*	Spawns a floating text message at the center of the screen.
	*	@param message Message to show.
	*	@param color Text color of the message.
	*/
	UFUNCTION(BlueprintCallable, meta = (FriendlyName = "Spawn Floating Text Message"), Category = "SagaGUI|FloatingText")
	static void Spawn(FString message, FLinearColor textColor = FLinearColor::White);

	/**
	*	Spawns a floating text message at the specified screen space position.
	*	@param screenPosition Starting position of the message in the screen space coordinates.
	*	@param message Message to show.
	*	@param color Text color of the message.
	*/
	UFUNCTION(BlueprintCallable, meta = (FriendlyName = "Spawn Floating Text Message At Position"), Category = "SagaGUI|FloatingText")
	static void SpawnAtPosition(FVector2D screenPosition, FString message, FLinearColor textColor = FLinearColor::White);

	/**
	*	Spawns a floating text message relative to the specified target actor.
	*	@param targetActor Actor, which position will be transposed to the sreen space and used as a starting point for the message.
	*	@param message Message to show.
	*	@param offset Offset to the target actor location in world space.
	*	@param color Text color of the message.
	*/
	UFUNCTION(BlueprintCallable, meta = (FriendlyName = "Spawn Floating Text Message At Actor"), Category = "SagaGUI|FloatingText")
	static void SpawnAtActor(AActor* targetActor, FString message, FVector offset = FVector::ZeroVector, FLinearColor textColor = FLinearColor::White);

protected:
	virtual void Tick_Implementation(FGeometry myGeometry, float inDeltaTime) override;

private:
	UPROPERTY() UTextBlock* messageLabel;

	static UFloatingTextWidget* Create(FString message, FLinearColor textColor);
	void SetColor(const FLinearColor& color);
	
};
