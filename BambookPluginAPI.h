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

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();
    void set_testString(const std::string& val);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Method echo
    FB::variant echo(const FB::variant& msg);

    FB::variant sdkVersion();
    FB::variant connect(std::string ip);
    FB::variant getPrivBookInfos();
    
    // Method test-event
    void testEvent(const FB::variant& s);

private:
    BambookPluginWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
    BB_HANDLE handle;

    std::string m_testString;
};

#endif // H_BambookPluginAPI

