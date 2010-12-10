/**********************************************************\

  Auto-generated BambookPluginAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "BambookPlugin.h"
#include "BambookCore.h"

#ifndef H_BambookPluginAPI
#define H_BambookPluginAPI

class BambookPluginAPI : public FB::JSAPIAuto
{
public:
    BambookPluginAPI(BambookPluginPtr plugin, FB::BrowserHostPtr host);
    virtual ~BambookPluginAPI();

    BambookPluginPtr getPlugin();

    int getSdkVersion();
    int connect(std::string ip);
    int disconnect();
    int getConnectStatus();
    FB::VariantList getPrivBookInfos();
    FB::VariantMap getDeviceInfo();
    int addPrivBook(std::string path);
    int deletePrivBook(std::string guid);
    int replacePrivBook(std::string guid, std::string path);
    int fetchPrivBook(std::string guid, std::string path);    

    static BambookPluginAPI *instance;
    static void addPrivBookCallback(uint32_t status, uint32_t progress, intptr_t userData);
    static void replacePrivBookCallback(uint32_t status, uint32_t progress, intptr_t userData);
    static void fetchPrivBookCallback(uint32_t status, uint32_t progress, intptr_t userData);    

private:
    BambookPluginWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
    BB_HANDLE handle;

};

#endif // H_BambookPluginAPI

