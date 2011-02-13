/**********************************************************\

  Auto-generated BambookPluginAPI.cpp

\**********************************************************/

#include "fstream"
#include "stdio.h"
#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "BambookPluginAPI.h"
#include "BambookPlugin.h"
#include "BambookCore.h"
#include "base64.h"
#include <boost/make_shared.hpp>

BambookPluginAPI *BambookPluginAPI::instance = NULL;

BambookPluginAPI::BambookPluginAPI(boost::shared_ptr<BambookPlugin> plugin, FB::BrowserHostPtr host) : m_host(host), m_pluginWeak(plugin)
{
    registerMethod("getSdkVersion",         make_method(this, &BambookPluginAPI::getSdkVersion));
    registerMethod("getErrorString",        make_method(this, &BambookPluginAPI::getErrorString));    
    registerMethod("connect",               make_method(this, &BambookPluginAPI::connect));
    registerMethod("disconnect",            make_method(this, &BambookPluginAPI::disconnect));
    registerMethod("getConnectStatus",      make_method(this, &BambookPluginAPI::getConnectStatus));
    registerMethod("getPrivBookInfos",      make_method(this, &BambookPluginAPI::getPrivBookInfos));
    registerMethod("getDeviceInfo",         make_method(this, &BambookPluginAPI::getDeviceInfo));
    registerMethod("addPrivBook",           make_method(this, &BambookPluginAPI::addPrivBook));
    registerMethod("deletePrivBook",        make_method(this, &BambookPluginAPI::deletePrivBook));
    registerMethod("replacePrivBook",       make_method(this, &BambookPluginAPI::replacePrivBook));
    registerMethod("fetchPrivBook",         make_method(this, &BambookPluginAPI::fetchPrivBook));

    registerMethod("addPrivBookByRawData",      make_method(this, &BambookPluginAPI::addPrivBookByRawData));
    registerMethod("replacePrivBookByRawData",  make_method(this, &BambookPluginAPI::replacePrivBookByRawData));
    registerMethod("fetchPrivBookByRawData",    make_method(this, &BambookPluginAPI::fetchPrivBookByRawData));

    registerProperty("version", make_property(this, &BambookPluginAPI::getPluginVersion));

    registerEvent("onprivbooktrans");
    registerEvent("onprivbooktransbyrawdata");
}

BambookPluginAPI::~BambookPluginAPI()
{
}

boost::shared_ptr<BambookPlugin> BambookPluginAPI::getPlugin()
{
    boost::shared_ptr<BambookPlugin> plugin = m_pluginWeak.lock();
    if (!plugin)
        throw FB::script_error("The plugin object has been destroyed");
    return plugin;
}

std::string BambookPluginAPI::getPluginVersion()
{
    return "1.0.5";
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

std::string BambookPluginAPI::getErrorString(int errorCode)
{
    return BambookGetErrorString(errorCode);
}

bool BambookPluginAPI::connect(std::string ip, const FB::JSObjectPtr &callback)
{
    boost::thread t(boost::bind(&BambookPluginAPI::doConnect_thread,
         this, ip, callback));
    return true;
}

void BambookPluginAPI::doConnect_thread(std::string ip, const FB::JSObjectPtr &callback)
{
    instance = this;
    int result = BambookConnect(ip.c_str(), 1000 * 30, &handle);
    callback->InvokeAsync("", FB::variant_list_of(shared_ptr())(result));
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
    BambookBookInfo info;
    info.cbSize = sizeof(BambookBookInfo);
    if(BambookGetFirstPrivBookInfo(handle, &info) == BR_SUCC){
        FB::VariantMap book;
        book["name"] = info.bookName;
        book["author"] = info.bookAuthor;
        book["guid"] = info.bookGuid;
        book["abstract"] = info.bookAbstract;

        books.push_back(book); 
    }
    
    info.cbSize = sizeof(BambookBookInfo);
    while(BambookGetNextPrivBookInfo(handle, &info) == BR_SUCC){
        info.cbSize = sizeof(BambookBookInfo);
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

int BambookPluginAPI::fetchPrivBookByRawData(std::string guid)
{
    std::string tmpFolder = tmpdir();
    std::string tmpFileName = tmpFolder + "/" + guid;
    current_guid = guid;
    return BambookFetchPrivBook(handle, guid.c_str(), tmpFolder.c_str(), fetchPrivBookByRawDataCallback, 0);
}

int BambookPluginAPI::addPrivBookByRawData(std::string guid, std::string rawdata)
{
    std::string decoded = base64_decode(rawdata);
    std::string tmpFolder = tmpdir();
    std::string tmpFileName = tmpFolder + "/" + guid;
    current_guid = guid;
    std::ofstream file(tmpFileName.c_str(), std::ios_base::binary);
    file << decoded;
    file.close();
    return BambookAddPrivBook(handle, tmpFileName.c_str(), privBookTransCallback, 0);
}

int BambookPluginAPI::replacePrivBookByRawData(std::string guid, std::string rawdata)
{
    std::string decoded = base64_decode(rawdata);
    std::string tmpFolder = tmpdir();
    std::string tmpFileName = tmpFolder + "/" + guid;
    current_guid = guid;
    std::ofstream file(tmpFileName.c_str(), std::ios_base::binary);
    file << decoded;
    file.close();
    return BambookReplacePrivBook(handle, tmpFileName.c_str(), guid.c_str(), privBookTransCallback, 0);
}

void BambookPluginAPI::firePrivBookTransByRawData() {
    std::string tmpFolder = tmpdir();
    std::string tmpFileName = tmpFolder + "/" + current_guid;
    std::ifstream file(tmpFileName.c_str(), std::ios_base::binary);
    if (file.is_open())  {
        int length;
        char * buffer;

        file.seekg (0, std::ios::end);
        length = file.tellg();
        file.seekg (0, std::ios::beg);
        buffer = new char [length];
        file.read (buffer,length);
        file.close();

        std::string data = base64_encode((const unsigned char*)buffer, length);
        FireEvent("onprivbooktransbyrawdata", FB::variant_list_of(data));
    }
}

void BambookPluginAPI::privBookTransCallback(uint32_t status, uint32_t progress, intptr_t userData)
{
    BambookPluginAPI::instance->FireEvent("onprivbooktrans", FB::variant_list_of(status)(progress)(userData));
}

void BambookPluginAPI::fetchPrivBookByRawDataCallback(uint32_t status, uint32_t progress, intptr_t userData)
{
    if(status == TRANS_STATUS_DONE) {              
        BambookPluginAPI::instance->firePrivBookTransByRawData();
    }
    BambookPluginAPI::instance->FireEvent("onprivbooktrans", FB::variant_list_of(status)(progress)(userData));
}
