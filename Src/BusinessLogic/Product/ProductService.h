#pragma once

#include "Src/Application/Base/BaseService.h"
#include "PosGroupProductModel.h"

class ProductService : public BaseService
{
    Q_OBJECT
public:
    ProductService(const QString &apiKey, const QString &token);

    void fetchPosGroupProducts();
    void fetchPosProducts();

    void callback(Constant::WSEndpoint endpoint, const QByteArray &response, int status) override;

signals:
    void fetchPosGroupProductsFinished(const QByteArray &, int);
    void fetchPosProductsFinished(const QByteArray &, int);
};
