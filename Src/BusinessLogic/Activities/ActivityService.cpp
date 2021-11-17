#include "ActivityService.h"

ActivityService::ActivityService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void ActivityService::fetchActivities()
{
    endpoint = Constant::WSEndpoint::ACTIVITIES;
    HttpRequest req {fullPath(Constant::WS_ACTIVITIES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void ActivityService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case Constant::WSEndpoint::ACTIVITIES:
            emit fetchActivitiesFinished(response, status);
            break;
    }
}
