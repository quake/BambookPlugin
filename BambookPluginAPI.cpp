/**********************************************************\

  Auto-generated BambookPluginAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"

#include "BambookPluginAPI.h"
#include "BambookCore.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn BambookPluginAPI::BambookPluginAPI(BambookPluginPtr plugin, FB::BrowserHostPtr host)
///
/// @brief  Constructor for your JSAPI object.  You should register your methods, properties, and events
///         that should be accessible to Javascript from here.
///
/// @see FB::JSAPIAuto::registerMethod
/// @see FB::JSAPIAuto::registerProperty
/// @see FB::JSAPIAuto::registerEvent
///////////////////////////////////////////////////////////////////////////////
BambookPluginAPI::BambookPluginAPI(BambookPluginPtr plugin, FB::BrowserHostPtr host) : m_plugin(plugin), m_host(host)
{
    registerMethod("echo",       make_method(this, &BambookPluginAPI::echo));
    registerMethod("testEvent",  make_method(this, &BambookPluginAPI::testEvent));
    registerMethod("sdkVersion", make_method(this, &BambookPluginAPI::sdkVersion));
    registerMethod("connect",    make_method(this, &BambookPluginAPI::connect));
    registerMethod("getPrivBookInfos",    make_method(this, &BambookPluginAPI::getPrivBookInfos));

    // Read-write property
    registerProperty("testString",
                     make_property(this,
                        &BambookPluginAPI::get_testString,
                        &BambookPluginAPI::set_testString));

    // Read-only property
    registerProperty("version",
                     make_property(this,
                        &BambookPluginAPI::get_version));
    
    
    registerEvent("onfired");    
}

///////////////////////////////////////////////////////////////////////////////
/// @fn BambookPluginAPI::~BambookPluginAPI()
///
/// @brief  Destructor.  Remember that this object will not be released until
///         the browser is done with it; this will almost definitely be after
///         the plugin is released.
///////////////////////////////////////////////////////////////////////////////
BambookPluginAPI::~BambookPluginAPI()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @fn BambookPluginPtr BambookPluginAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
BambookPluginPtr BambookPluginAPI::getPlugin()
{
    BambookPluginPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}



// Read/Write property testString
std::string BambookPluginAPI::get_testString()
{
    return m_testString;
}
void BambookPluginAPI::set_testString(const std::string& val)
{
    m_testString = val;
}

// Read-only property version
std::string BambookPluginAPI::get_version()
{
    return "CURRENT_VERSION";
}

// Method echo
FB::variant BambookPluginAPI::echo(const FB::variant& msg)
{
    return msg;
}

FB::variant BambookPluginAPI::sdkVersion()
{
    uint32_t version;
    if(BambookGetSDKVersion(&version) == BR_SUCC){
        return version;
    }
    return false;
}

FB::variant BambookPluginAPI::connect(std::string ip)
{
    return BambookConnect(ip.c_str(), 1000 * 30, &handle);
}

FB::variant BambookPluginAPI::getPrivBookInfos()
{
    PrivBookInfo info;
    info.cbSize = sizeof(PrivBookInfo);
    if(BambookGetFirstPrivBookInfo(handle, &info) == BR_SUCC){
	std::string bookName = info.bookName;
        return bookName;
/*
        temp.append(QTime::currentTime().toString()).append(":").append("\n");
        temp.append("Book Name:").append(QString::fromUtf8(info.bookName)).append("\n");
        temp.append("Author:").append(QString::fromUtf8(info.bookAuthor)).append("\n");
        temp.append("Book Guid:").append(QString::fromUtf8(info.bookGuid)).append("\n");
    }

    info.cbSize = sizeof(PrivBookInfo);
    while(BambookGetNextPrivBookInfo(handle, &info) != BR_EOF){
        info.cbSize = sizeof(PrivBookInfo);
        temp.append("Book Name:").append(QString::fromUtf8(info.bookName)).append("\n");
        temp.append("Author:").append(QString::fromUtf8(info.bookAuthor)).append("\n");
        temp.append("Book Guid:").append(QString::fromUtf8(info.bookGuid)).append("\n");
    }
*/
    }else{
        return false;
    }
}

void BambookPluginAPI::testEvent(const FB::variant& var)
{
    FireEvent("onfired", FB::variant_list_of(var)(true)(1));
}

