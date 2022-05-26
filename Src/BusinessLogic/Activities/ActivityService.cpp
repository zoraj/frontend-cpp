#include "ActivityService.h"

ActivityService::ActivityService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void ActivityService::fetchActivities()
{
    endpoint = constant::WSEndpoint::ACTIVITIES;
    HttpRequest req {fullPath(constant::WS_ACTIVITIES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

// Main callback methods
void ActivityService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::ACTIVITIES:
            emit fetchActivitiesFinished(response, status);
            break;
    }
}
