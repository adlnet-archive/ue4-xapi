

#pragma once


#include "Components/ActorComponent.h"
#include "Json.h"
#include "xAPIAgentComponent.generated.h"


/*UENUM(BlueprintType)
enum class EAgentIFIType : uint8
{
	MBOX			UMETA(DisplayName = "mbox"),
	MBOX_SHA1SUM	UMETA(DisplayName = "mbox_sha1sum"),
	OPENID			UMETA(DisplayName = "openid"),
	ACCOUNT			UMETA(DisplayName = "account")
};*/

UENUM(BlueprintType)
namespace EAgentIFIType
{
	enum Type {
		MBOX UMETA(DisplayName = "mbox"),
		MBOX_SHA1SUM UMETA(DisplayName = "mbox_sha1sum"),
		OPENID UMETA(DisplayName = "openid"),
		ACCOUNT UMETA(DisplayName = "account")
	};
}

USTRUCT()
struct FAgentAccountInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ExperienceAPI)
		FString Homepage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ExperienceAPI)
		FString Name;
};

/**
 * A component representing an xAPI Agent, i.e. a learner
 */
UCLASS(BlueprintType)
class XAPIINTEGRATION_API UxAPIAgentComponent : public UActorComponent
{
	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(EditAnywhere, Category = ExperienceAPI)
		FString Name;

	UPROPERTY(EditAnywhere, Category = ExperienceAPI)
		//EAgentIFIType ifi_type;
		TEnumAsByte<EAgentIFIType::Type> ifi_type;

	UPROPERTY(EditAnywhere, Category = ExperienceAPI)
		FString Mbox;

	UPROPERTY(EditAnywhere, Category = ExperienceAPI)
		FString MboxSha1Sum;

	UPROPERTY(EditAnywhere, Category = ExperienceAPI)
		FString OpenID;

	UPROPERTY(EditAnywhere, Category = ExperienceAPI)
		FAgentAccountInfo Account;

	const TSharedPtr<FJsonObject> toAgent() const;
};
