#include "SegmentationService.h"

SegmentationService::SegmentationService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}


void SegmentationService::fetchClientTypes()
{
    endpoint = Constant::WSEndpoint::CLIENT_TYPES;
    HttpRequest req {fullPath(Constant::WS_CLIENT_TYPES),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void SegmentationService::fetchSegmentations()
{
    endpoint = Constant::WSEndpoint::SEGMENTATION;
    HttpRequest req {fullPath(Constant::WS_SEGMENTATION),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void SegmentationService::fetchPrescripteurs()
{
    endpoint = Constant::WSEndpoint::PRESCRIPTEUR;
    HttpRequest req {fullPath(Constant::WS_PRESCRIPTEUR),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}



void SegmentationService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case Constant::WSEndpoint::CLIENT_TYPES:
            emit fetchClientTypesFinished(response, status);
            break;
        case Constant::WSEndpoint::SEGMENTATION:
            emit fetchSegmentationsFinished(response, status);
            break;
        case Constant::WSEndpoint::PRESCRIPTEUR:
            emit fetchPrescripteursFinished(response, status);
            break;
    }
}
