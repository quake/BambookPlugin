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

    FB::variant sdkVersion();
    FB::variant connect(std::string ip);
    FB::VariantList getPrivBookInfos();
    FB::VariantMap getDeviceInfo();
    FB::variant sendSnbToBambook(std::string path);

    static BambookPluginAPI *instance;
    static void sendSnbToBambookCallback(uint32_t status, uint32_t progress, intptr_t userData);

private:
    BambookPluginWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
    BB_HANDLE handle;

};

#endif // H_BambookPluginAPI

