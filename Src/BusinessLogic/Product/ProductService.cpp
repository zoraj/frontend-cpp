#include "ProductService.h"

ProductService::ProductService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void ProductService::fetchPosGroupProducts()
{
    endpoint = constant::WSEndpoint::POS_GROUP_PRODUCTS;
    HttpRequest req {fullPath(constant::WS_POS_GROUP_PRODUCTS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void ProductService::fetchPosProducts()
{
    endpoint = constant::WSEndpoint::POS_PRODUCTS;
    HttpRequest req {fullPath(constant::WS_POS_PRODUCTS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}


void ProductService::callback(constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case constant::WSEndpoint::POS_GROUP_PRODUCTS:
            emit fetchPosGroupProductsFinished(response, status);
            break;
        case constant::WSEndpoint::POS_PRODUCTS:
            emit fetchPosProductsFinished(response, status);
            break;
    }
}
