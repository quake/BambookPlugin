/**********************************************************\

  Auto-generated BambookPluginAPI.h

\**********************************************************/

#include <string>
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
    BambookPluginAPI(boost::shared_ptr<BambookPlugin> plugin, FB::BrowserHostPtr host);
    virtual ~BambookPluginAPI();

    boost::shared_ptr<BambookPlugin> getPlugin();

    int getSdkVersion();
    std::string getPluginVersion();
    std::string getErrorString(int errorCode);
    bool connect(std::string ip, const FB::JSObjectPtr &callback);
    void doConnect_thread(std::string ip, const FB::JSObjectPtr &callback);
    int disconnect();
    int getConnectStatus();
    FB::VariantList getPrivBookInfos();
    FB::VariantMap getDeviceInfo();
    int addPrivBook(std::string path);
    int deletePrivBook(std::string guid);
    int replacePrivBook(std::string guid, std::string path);
    int fetchPrivBook(std::string guid, std::string path);

    int addPrivBookByRawData(std::string guid, std::string data);
    int replacePrivBookByRawData(std::string guid, std::string data);
    int fetchPrivBookByRawData(std::string guid);

    void firePrivBookTransByRawData();

    static BambookPluginAPI *instance;
    static void privBookTransCallback(uint32_t status, uint32_t progress, intptr_t userData);
    static void fetchPrivBookByRawDataCallback(uint32_t status, uint32_t progress, intptr_t userData);

    inline char * tmpdir(){
        char *dirname;
        dirname = std::getenv("TMP");
        if(NULL == dirname)
            dirname = std::getenv("TMPDIR");
        if(NULL == dirname)
            dirname = std::getenv("TEMP");
        if(NULL == dirname){
            dirname = ".";
        }
        return dirname;
    }

private:
    FB::BrowserHostPtr m_host;
    boost::weak_ptr<BambookPlugin> m_pluginWeak;
    BB_HANDLE handle;
    std::string current_guid;
};

#endif // H_BambookPluginAPI

