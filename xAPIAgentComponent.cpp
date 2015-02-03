

#include "xAPIIntegration.h"
#include "xAPIAgentComponent.h"

DEFINE_LOG_CATEGORY(xAPILog);

UxAPIAgentComponent::UxAPIAgentComponent(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP), ifi_type(EAgentIFIType::MBOX)
{

}


const TSharedPtr<FJsonObject> UxAPIAgentComponent::toAgent() const
{
	// initialize the object we'll be returning
	TSharedPtr<FJsonObject> agent(new FJsonObject());

	// specify that the return object is an Agent
	agent->SetStringField(TEXT("objectType"), TEXT("Agent"));

	// add the general-purpose name if specified
	if (!Name.IsEmpty()){
		agent->SetStringField(TEXT("name"), Name);
	}

	// add the IFI specified by ifi_type
	switch (ifi_type){
	case EAgentIFIType::MBOX:

		agent->SetStringField(TEXT("mbox"), Mbox);
		break;

	case EAgentIFIType::MBOX_SHA1SUM:

		agent->SetStringField(TEXT("mbox_sha1sum"), MboxSha1Sum);
		break;

	case EAgentIFIType::OPENID:

		agent->SetStringField(TEXT("openid"), OpenID);
		break;

	case EAgentIFIType::ACCOUNT:

		TSharedPtr<FJsonObject> accountObj(new FJsonObject());
		accountObj->SetStringField(TEXT("homePage"), Account.Homepage);
		accountObj->SetStringField(TEXT("name"), Account.Name);

		agent->SetObjectField(TEXT("account"), accountObj);
		break;
	}

	return agent;
}
