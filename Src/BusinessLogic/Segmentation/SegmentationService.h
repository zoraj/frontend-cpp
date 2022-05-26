#pragma once

#include "Src/Application/Base/BaseService.h"
#include <QObject>

class SegmentationService : public BaseService
{
    Q_OBJECT
public:
    SegmentationService(const QString &apiKey, const QString &token);
    void fetchClientTypes();
    void fetchSegmentations();
    void fetchPrescripteurs();

    void callback(constant::WSEndpoint endpoint, const QByteArray &response, int status) override;

signals:
    void fetchClientTypesFinished(const QByteArray &, int);
    void fetchSegmentationsFinished(const QByteArray &, int);
    void fetchPrescripteursFinished(const QByteArray &, int);
};
