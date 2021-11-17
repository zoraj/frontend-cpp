#include "ProductService.h"

ProductService::ProductService(const QString &apiKey, const QString &token): BaseService(apiKey, token)
{

}

void ProductService::fetchPosGroupProducts()
{
    endpoint = Constant::WSEndpoint::POS_GROUP_PRODUCTS;
    HttpRequest req {fullPath(Constant::WS_POS_GROUP_PRODUCTS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}

void ProductService::fetchPosProducts()
{
    endpoint = Constant::WSEndpoint::POS_PRODUCTS;
    HttpRequest req {fullPath(Constant::WS_POS_PRODUCTS),
        "GET",
        nullptr,
        apiKey,
        bearerToken
    };
    executeRequest(req);
}


void ProductService::callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status)
{
    switch (endpoint) {
        case Constant::WSEndpoint::POS_GROUP_PRODUCTS:
            emit fetchPosGroupProductsFinished(response, status);
            break;
        case Constant::WSEndpoint::POS_PRODUCTS:
            emit fetchPosProductsFinished(response, status);
            break;
    }
}
