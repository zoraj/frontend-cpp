#include "SegmentationService.h"

SegmentationService::SegmentationService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void SegmentationService::fetchClientTypes()
{
    endpoint = constant::WSEndpoint::CLIENT_TYPES;
    HttpRequest req {fullPath(constant::WS_CLIENT_TYPES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void SegmentationService::fetchSegmentations()
{
    endpoint = constant::WSEndpoint::SEGMENTATION;
    HttpRequest req {fullPath(constant::WS_SEGMENTATION),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void SegmentationService::fetchPrescripteurs()
{
    endpoint = constant::WSEndpoint::PRESCRIPTEUR;
    HttpRequest req {fullPath(constant::WS_PRESCRIPTEUR),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}



void SegmentationService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::CLIENT_TYPES:
            emit fetchClientTypesFinished(response, status);
            break;
        case constant::WSEndpoint::SEGMENTATION:
            emit fetchSegmentationsFinished(response, status);
            break;
        case constant::WSEndpoint::PRESCRIPTEUR:
            emit fetchPrescripteursFinished(response, status);
            break;
    }
}
