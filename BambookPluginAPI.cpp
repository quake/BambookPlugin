/**********************************************************\

  Auto-generated BambookPluginAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"

#include "BambookPluginAPI.h"
#include "BambookCore.h"

BambookPluginAPI *BambookPluginAPI::instance = NULL;

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
    registerMethod("getSdkVersion",         make_method(this, &BambookPluginAPI::getSdkVersion));
    registerMethod("connect",               make_method(this, &BambookPluginAPI::connect));
    registerMethod("disconnect",            make_method(this, &BambookPluginAPI::disconnect));
    registerMethod("getConnectStatus",      make_method(this, &BambookPluginAPI::getConnectStatus));
    registerMethod("getPrivBookInfos",      make_method(this, &BambookPluginAPI::getPrivBookInfos));
    registerMethod("getDeviceInfo",         make_method(this, &BambookPluginAPI::getDeviceInfo));
    registerMethod("addPrivBook",           make_method(this, &BambookPluginAPI::addPrivBook));
    registerMethod("deletePrivBook",        make_method(this, &BambookPluginAPI::deletePrivBook));
    registerMethod("replacePrivBook",       make_method(this, &BambookPluginAPI::replacePrivBook));
    registerMethod("fetchPrivBook",         make_method(this, &BambookPluginAPI::fetchPrivBook));
    
    registerEvent("onprivbooktrans");
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


int BambookPluginAPI::getSdkVersion()
{
    uint32_t version;
    if(BambookGetSDKVersion(&version) == BR_SUCC){
        return version;
    }else{
        return 0;    
    }
}

int BambookPluginAPI::connect(std::string ip)
{
    instance = this;
    return BambookConnect(ip.c_str(), 1000 * 30, &handle);
}

int BambookPluginAPI::disconnect()
{
    return BambookDisconnect(handle);
}

int BambookPluginAPI::getConnectStatus()
{
    uint32_t status;
    BambookGetConnectStatus(handle, &status);
    return status;
}

FB::VariantList BambookPluginAPI::getPrivBookInfos()
{
    FB::VariantList books;
    PrivBookInfo info;
    info.cbSize = sizeof(PrivBookInfo);
    if(BambookGetFirstPrivBookInfo(handle, &info) == BR_SUCC){
        FB::VariantMap book;
        book["name"] = info.bookName;
        book["author"] = info.bookAuthor;
        book["guid"] = info.bookGuid;
        book["abstract"] = info.bookAbstract;

        books.push_back(book); 
    }

    info.cbSize = sizeof(PrivBookInfo);
    while(BambookGetNextPrivBookInfo(handle, &info) == BR_SUCC){
        info.cbSize = sizeof(PrivBookInfo);
        FB::VariantMap book;
        book["name"] = info.bookName;
        book["author"] = info.bookAuthor;
        book["guid"] = info.bookGuid;
        book["abstract"] = info.bookAbstract;

        books.push_back(book); 
    }
    
    return books;
}

FB::VariantMap BambookPluginAPI::getDeviceInfo()
{
    FB::VariantMap device;
    DeviceInfo info;
    info.cbSize = sizeof(DeviceInfo);
    if(BambookGetDeviceInfo(handle, &info) == BR_SUCC){
        device["sn"] = info.sn;
        device["firmwareVersion"] = info.firmwareVersion;
        device["deviceVolume"] = info.deviceVolume;
        device["spareVolume"] = info.spareVolume;
    }
    
    return device;
}

int BambookPluginAPI::addPrivBook(std::string path)
{
    return BambookAddPrivBook(handle, path.c_str(), privBookTransCallback, 0);
}

int BambookPluginAPI::deletePrivBook(std::string guid)
{
    return BambookDeletePrivBook(handle, guid.c_str());
}

int BambookPluginAPI::replacePrivBook(std::string guid, std::string path)
{
    return BambookReplacePrivBook(handle, path.c_str(), guid.c_str(), privBookTransCallback, 0);
}

int BambookPluginAPI::fetchPrivBook(std::string guid, std::string path)
{
    return BambookFetchPrivBook(handle, guid.c_str(), path.c_str(), privBookTransCallback, 0);
}

void BambookPluginAPI::privBookTransCallback(uint32_t status, uint32_t progress, intptr_t userData)
{
    BambookPluginAPI::instance->FireEvent("onprivbooktrans", FB::variant_list_of(status)(progress)(userData));
}
