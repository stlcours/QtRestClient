#ifndef QTRESTCLIENT_GLOBAL_H
#define QTRESTCLIENT_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>
#include <QtCore/qobject.h>
#include <QtCore/qbytearray.h>

#if defined(QT_BUILD_RESTCLIENT_LIB)
#	define Q_RESTCLIENT_EXPORT Q_DECL_EXPORT
#else
#	define Q_RESTCLIENT_EXPORT Q_DECL_IMPORT
#endif

//! The Namespace containing all classes of the QtRestClient module
namespace QtRestClient {

class RestClient;
class RestClass;

//! A typedef for a collection of HTTP-Request headers
typedef QHash<QByteArray, QByteArray> HeaderHash;

//! Makes the given API available under the given name
Q_RESTCLIENT_EXPORT bool addGlobalApi(const QString &name, RestClient *client);
//! Removes a previously added API from the global list
Q_RESTCLIENT_EXPORT void removeGlobalApi(const QString &name, bool deleteClient = true);
//! Returns the client for given API name
Q_RESTCLIENT_EXPORT RestClient *apiClient(const QString &name);
//! Returns the clients root class for the given API name
Q_RESTCLIENT_EXPORT RestClass *apiRootClass(const QString &name);
//! Creates a new API class based on the client for the given API name
Q_RESTCLIENT_EXPORT RestClass *createApiClass(const QString &name, const QString &path, QObject *parent = nullptr);
}

#endif // QTRESTCLIENT_GLOBAL_H
