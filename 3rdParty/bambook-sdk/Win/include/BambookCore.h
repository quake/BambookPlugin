/*! \file BambookCore.h
    \brief Bambook PC 开发核心组件头文件

    Copyright (C) 2009-2011 盛大网络 All right reserved\n

    项目名称：Bambook SDK\n
    功能简介：Bambook PC 开发核心组件头文件\n

    原始作者：果壳电子 Bambook SDK 项目组\n
    建立时间：2010-10-12\n
    最后更新：2011-01-05\n

    单元标识：$Id $
*/

#ifndef __BAMBOOKCORE_H__
#define __BAMBOOKCORE_H__

//==============================================================================
// 公共类型及常量定义
//==============================================================================

#ifdef __cplusplus
extern "C" {
#endif

//! \cond
#ifndef __in
#define __in
#define __in_opt
#define __inout
#define __out
#define __out_opt
#define __out_ecount(n)
#define __out_ecount_opt(n)
#define __callback
#endif

typedef __int32             int32_t;
typedef unsigned __int32    uint32_t;

#ifdef _WIN64
typedef __int64             intptr_t;
#else
typedef __int32             intptr_t;
#endif
//! \endcond

//! \addtogroup 类型定义
//! @{

//! \addtogroup 基本类型定义
//! @{

//! \name 基本类型定义
//! @{

//! API 返回值类型
typedef int32_t             BB_RESULT;

//! 对象句柄
typedef intptr_t            BB_HANDLE;
//! @}
//! @}
//! @}

//! \addtogroup MacroDef 宏定义
//! @{

//! \addtogroup CommonMacro 公共常量定义
//! @{

//! \name 公共常量定义
//! @{

//! SDK 版本号 0.9.7.0
#define BAMBOOK_SDK_VERSION 0x00090700

//! 使用 USB 连接 Bambook 的设备 IP
#define DEFAULT_BAMBOOK_IP  "192.168.250.2"

//! 自有书 AppID
#define PRIVBOOK_APPID      "999"

//! API 调用方式
#define BBAPI               __cdecl
//! @}
//! @}

//! \addtogroup BBResult 函数返回值定义
//! @{

//! \name 函数返回值定义
//! @{
#define BR_SUCC             0     //!< 操作成功
#define BR_FAIL             1001  //!< 操作失败
#define BR_NOT_IMPL         1002  //!< 该功能还未实现
#define BR_DISCONNECTED     1003  //!< 与设备的连接已断开
#define BR_PARAM_ERROR      1004  //!< 调用函数传入的参数错误
#define BR_TIMEOUT          1005  //!< 操作或通讯超时
#define BR_INVALID_HANDLE   1006  //!< 传入的句柄无效
#define BR_INVALID_FILE     1007  //!< 文件不存在或格式无效
#define BR_INVALID_DIR      1008  //!< 目录不存在
#define BR_FIRM_NOT_SUPPORT 1009  //!< 设备固件不支持该功能，需要升级到最新的固件版本
#define BR_BUSY             1010  //!< 设备忙，另一个操作还未完成
#define BR_EOF              1011  //!< 文件或操作已结束
#define BR_IO_ERROR         1012  //!< 文件读写失败
#define BR_FILE_NOT_INSIDE  1013  //!< 指定的文件不在包里
#define BR_USER_REFUSED     1014  //!< 用户在设备上拒绝了连接
#define BR_WAIT_FOR_AUTH    1015  //!< 设备已连接，但还没有通过身份验证，无法执行指定操作
#define BR_OUT_OF_BOUNDS    1016  //!< 索引超出范围
#define BR_FILE_EXISTS      1017  //!< \brief 文件已经存在
//! @}
//! @}

//! \addtogroup BBConn 当前连接状态
//! @{

//! \name 当前连接状态
//! @{
#define CONN_CONNECTED      0     //!< 已连接
#define CONN_DISCONNECTED   1     //!< 未连接、连接已断开或用户拒绝了连接
#define CONN_CONNECTING     2     //!< 正在连接
#define CONN_WAIT_FOR_AUTH  3     //!< \brief 已连接，正在等待身份验证
//! @}
//! @}

//! \addtogroup BBTrans 传输状态
//! @{

//! \name 传输状态
//! @{
#define TRANS_STATUS_TRANS  0     //!< 正在传输
#define TRANS_STATUS_DONE   1     //!< 传输完成
#define TRANS_STATUS_ERR    2     //!< \brief 传输出错
//! @}
//! @}
//! @}

//! \addtogroup 类型定义
//! @{

//! \addtogroup 枚举定义
//! @{

//! \name 枚举定义
//! @{

//! 按键定义
enum BambookKey
{
    BBKeyNum0 = 0, BBKeyNum1, BBKeyNum2, BBKeyNum3, BBKeyNum4,
    BBKeyNum5, BBKeyNum6, BBKeyNum7, BBKeyNum8, BBKeyNum9,
    BBKeyStar, BBKeyCross, BBKeyUp, BBKeyDown, BBKeyLeft, BBKeyRight, BBKeyPageUp, BBKeyPageDown,
    BBKeyOK, BBKeyESC, BBKeyBookshelf, BBKeyStore, BBKeyTTS, BBKeyMenu, BBKeyInteract
};

//! 设备固件支持的功能
enum BambookDeviceCap
{
    BBCapCatalog = 0,               //!< 读写分类功能
    BBCapGetBookSize,               //!< 取自有书文件大小功能
    BBCapBookmark,                  //!< 读写书籍阅读位置功能
    BBCapGetLastReadBook,           //!< 取最后阅读书籍功能
    BBCapGetCurrentReadBook,        //!< 取当前阅读书籍功能
    BBCapKeyPress,                  //!< 模拟按键功能
    BBCapTTSPlay                    //!< TTS 语音播放功能
};
//! @}
//! @}

//! \addtogroup 结构定义
//! @{

//! 已连接到当前计算机的设备信息结构
struct BambookDevInfo
{
    uint32_t cbSize;              //!< 结构大小
    char ip[32];                  //!< 设备IP地址
    uint32_t protocalVersion;     //!< 设备支持的 PC 通讯协议版本号
};

//! 设备信息结构
struct DeviceInfo
{
    uint32_t cbSize;              //!< 结构大小
    char sn[20];                  //!< 设备序列号
    char firmwareVersion[20];     //!< 设备固件版本
    uint32_t deviceVolume;        //!< 设备总存储空间，单位为KB
    uint32_t spareVolume;         //!< 剩余存储空间，单位为KB
    uint32_t protocalVersion;     //!< 设备支持的 PC 通讯协议版本号
};

//! Bambook 书籍信息结构
struct BambookBookInfo
{
    uint32_t cbSize;              //!< 结构大小
    uint32_t bookType;            //!< 书籍类型： 0 版权书；1 自有书
    char bookAppId[20];           //!< 内容提供方标识："999" 为自有书
    char bookGuid[20];            //!< 书籍id(在设备里的snb文件名)
    char bookName[80];            //!< 书名
    char bookAuthor[40];          //!< 作者
    char bookAbstract[256];       //!< 摘要
    char bookLatest[80];          //!< 最新章节标题
    char lastUpdateTime[20];      //!< 最后更新时间
    char bookCover[100];          //!< 封面图片 URL
    uint32_t unread;              //!< 未读章节数
    uint32_t autoPay;             //!< 是否自动订阅：0 未自动订阅；1 自动订阅
    uint32_t bookSize;            //!< 自有书文件大小，版权书始终为 0。要求固件支持的通讯协议 protocalVersion 最低版本为：23
};

//! \name 兼容类型定义
//! @{

//! 用于兼容早期版本的 API 定义的私有书结构别名
typedef BambookBookInfo PrivBookInfo;
//! @}

//! Bambook 书籍章节信息结构
struct BambookChapterInfo
{
    uint32_t cbSize;              //!< 结构大小
    char chapterId[20];           //!< 章节ID
    char chapterName[80];         //!< 章节名
    uint32_t chapterBuyStatus;    //!< 章节购买状态： 0 免费章节；1 已付费vip章节；2 未付费vip章节
    uint32_t chapterDownloadStatus; //!< 章节下载状态： 0 未下载；1 已下载
};

//! Bambook 书籍书签信息结构
struct BambookBookmarkInfo 
{
    uint32_t cbSize;              //!< 结构大小
    char chapterId[20];           //!< 章节ID
    char bookmark[64];            //!< 书签信息，支持两种格式：节点ID|从该节点第一个字节开始的 offset 或者 页码
                                  /*!< 节点ID指的是在 snbc 中的 text/image 节点的编号（从0开始）\n
                                       比如："3|336" 表示在章节中第三个节点偏移336字节（utf8编码）处\n
                                       由于阅读时是按整页排版的，指定的偏移位置可能在整页的任何位置而不是屏幕左上角\n
                                       另外，也可以直接指定章节内的页码，如 "5" 表示第 5 页 */
    uint32_t lastReadTime;        //!< 最后阅读时间，从1970-1-1开始的秒数，设置书签时 0 表示不修改
};

//! SNB 中的文件信息结构
struct SnbFileInfo
{
    uint32_t cbSize;              //!< 结构大小
    char filePathName[1024];      //!< 文件在 SNB 中的相对路径及文件名
    uint32_t fileSize;            //!< 文件原始大小
};
//! @}

//! \addtogroup 回调函数定义
//! @{

//! \name 回调函数定义
//! @{

/*! 传输自有书回调函数

    在调用自有书传输时使用

    \param status   传输状态
    \param progress 传输进度，0..100
    \param userData 用户调用API时传入的数据
*/
typedef void ( BBAPI * TransCallback )(
    __in uint32_t status,
    __in uint32_t progress,
    __in_opt intptr_t userData
    );
//! @}
//! @}
//! @}

//! \weakgroup SDKAPI BambookCore API
//! @{

//==============================================================================
//! \addtogroup BaseAPI 基础 API
//==============================================================================

//! @{
/*! 取得SDK DLL版本号

    调用该函数可以返回DLL支持SDK版本号，可用于兼容性处理

    \param version 指针，返回版本号
    \return 成功返回 BR_SUCC
*/
BB_RESULT
BBAPI
BambookGetSDKVersion (
    __out uint32_t * version
    );

/*! 返回错误码对应的中文含义

    该函数用来取得错误字符串，如果传入未定义的错误代码，将返回 "未知错误"

    \param nCode 错误代码
    \return 错误信息字符串指针
*/
const char *
BBAPI 
BambookGetErrorString (
    __in BB_RESULT nCode
    );

/*! 设定 BambookCore 的 API 接收和返回的字符串使用的字符集

    通常该函数应该在应用程序初始化时调用，可控制所有 API 的字符串编码，默认为 "gbk"

    \param lpszEncoding 字符集名称，只支持 "utf8" 和 "gbk"
    \return             成功返回 BR_SUCC，参数不正确返回 BR_PARAM_ERROR
*/
BB_RESULT
BBAPI 
BambookSetCharacterEncoding(
    __in const char * lpszEncoding
    );

/*! 取得 BambookCore 的 API 接收和返回的字符串使用的字符集

    \param lpszEncoding 返回字符集名称，调用时必须保证分配的长度 >= 20
    \return             成功返回 BR_SUCC，参数不正确返回 BR_PARAM_ERROR
*/
BB_RESULT
BBAPI 
BambookGetCharacterEncoding(
    __out_ecount(20) char * lpszEncoding
    );
//! @}

//==============================================================================
//! \addtogroup ConnAPI 设备连接相关 API
//==============================================================================

//! @{
/*! 取得第一个连接到当前计算机的 Bambook 设备信息

    \param dwFlags  查找参数，目前未使用，调用时应传入 0
    \param pInfo    返回设备信息。调用前应设置 pInfo->cbSize = SizeOf(BambookDevInfo)
    \return         成功返回 BR_SUCC，如果找不到设备返回 BR_EOF，其它错误返回错误代码
*/
BB_RESULT
BBAPI
BambookGetFirstDevice (
    __in uint32_t dwFlags,
    __out BambookDevInfo * pInfo
    );

/*! 取得下一个连接到当前计算机的 Bambook 设备信息

    \param pInfo    返回设备信息。调用前应设置 pInfo->cbSize = SizeOf(BambookDevInfo)
    \return         成功返回 BR_SUCC，如果找不到设备返回 BR_EOF，其它错误返回错误代码
*/
BB_RESULT
BBAPI
BambookGetNextDevice (
    __out BambookDevInfo * pInfo
    );

/*! 连接 Bambook 设备

    调用函数后会阻塞执行，连接成功后 hConn 为连接句柄。\n
    如果 timeOut 为 0，当设备支持用户验证时，调用函数后会等待用户在设备端进
    行确认，通过或拒绝后函数才会返回。\n
    如果 timeOut 为非 0 值，则如果在 timeOut 时间内连接上设备，就返回句柄和
    成功，但此时应用程序需要自行通过 BambookGetConnectStatus 去检查设备是否
    在等待用户验证通过状态，只有状态为 CONN_CONNECTED 时才可操作设备。\n
    连接被中断或通讯结束后应调用 BambookDisconnect 释放资源

    \param lpszIP   Bambook IP地址，传空时使用默认值 DEFAULT_BAMBOOK_IP
    \param timeOut  超时值，单位毫秒，0为默认。
    \param hConn    句柄指针，执行成功返回连接句柄
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL，超时返回 BR_TIMEOUT，用户拒绝连接返回 BR_USER_REFUSED。
*/
BB_RESULT
BBAPI 
BambookConnect (
    __in const char * lpszIP,
    __in uint32_t timeOut,
    __out BB_HANDLE * hConn
    );

/*! 断开 Bambook 设备的连接

    调用函数后会阻塞执行，直到连接被断开或失败，成功后 hConn 句柄将不可用

    \param hConn    连接句柄
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI
BambookDisconnect (
    __in BB_HANDLE hConn
    );

/*! 查询当前 Bambook 设备的连接状态

    应用在调用其它API前可调用该函数以查询连接状态。\n
    如果使用建立连接时传入了 timeOut 值，需要在调用其它 API 之前使用该函
    数查询连接状态，只有状态为 CONN_CONNECTED 时才可进行其它操作。

    \param hConn    连接句柄
    \param status   指针，返回连接状态
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookGetConnectStatus (
    __in BB_HANDLE hConn,
    __out uint32_t * status
    );
//! @}

//==============================================================================
//! \addtogroup InfoAPI 设备信息相关 API
//==============================================================================

//! @{
/*! 获取 Bambook 基本信息

    调用函数后会阻塞执行，直到操作成功或失败

    \param hConn    连接句柄
    \param pInfo    信息指针，用于返回基本信息。调用前应设置 pInfo->cbSize = SizeOf(DeviceInfo)
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码。
                    如果 pInfo->cbSize 不正确将返回 BR_PARAM_ERROR
*/
BB_RESULT
BBAPI 
BambookGetDeviceInfo (
    __in BB_HANDLE hConn,
    __out DeviceInfo * pInfo
    );

/*! 返回 Bambook 书籍列表变更计数器

    当用户通过云梯、其它应用程序或直接在设备上手工加书、删书，以及设备从服
    务器上同步下新书时，变更计数器会自动加 1，应用可以根据计数器的值来决定
    是否需要更新书架。使用 BambookReplacePrivBook API 可能不会影响变更计数。

    \param hConn        连接句柄
    \param uChangCount  返回书籍列表变更计数，每次检测到设备书架变更，该计数器会加 1
    \return             成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookGetBookShelfChangeCount (
    __in BB_HANDLE hConn,
    __out uint32_t * uChangCount
    );

/*! 检查当前连接的设备是否支持指定的功能

    \param hConn    连接句柄
    \param devCap   要检查的功能
    \return         如果设备支持该功能返回 BR_SUCC，不支持时返回 BR_FIRM_NOT_SUPPORT，
                    其它错误返回错误代码
*/
BB_RESULT
BBAPI 
BambookDeviceSupports (
    __in BB_HANDLE hConn,
    __in BambookDeviceCap devCap
    );
//! @}

//==============================================================================
//! \addtogroup BookInfoAPI 书籍信息相关 API
//==============================================================================

//! @{
/*! 获取 Bambook 第一本自有书信息

    调用该函数后将从头开始从设备查找自有书信息，成功后可以再次调用 BambookGetNextPrivBookInfo
    查找剩下的自有书信息。\n
    该函数会阻塞执行，直到操作成功或失败

    \param hConn    连接句柄
    \param pInfo    信息指针，用于返回自有书信息。调用前应设置 pInfo->cbSize = SizeOf(BambookBookInfo)
    \return         成功返回 BR_SUCC，如果找不到自有书返回 BR_EOF，其它错误返回错误代码
*/
BB_RESULT
BBAPI 
BambookGetFirstPrivBookInfo (
    __in BB_HANDLE hConn, 
    __out BambookBookInfo * pInfo
    );

/*! 获取 Bambook 下一本自有书信息

    在调用 BambookGetFirstPrivBookInfo 成功后再调用本函数，查找后继的自有书信息。\n
    该函数会阻塞执行，直到操作成功或失败

    \param hConn    连接句柄
    \param pInfo    信息指针，用于返回自有书信息。调用前应设置 pInfo->cbSize = SizeOf(BambookBookInfo)
    \return         成功返回 BR_SUCC，如果找不到自有书返回 BR_EOF，其它错误返回错误代码
*/
BB_RESULT
BBAPI 
BambookGetNextPrivBookInfo (
    __in BB_HANDLE hConn, 
    __out BambookBookInfo * pInfo
    );

/*! 获取 Bambook 第一本书籍信息

    调用该函数后将从头开始从设备查找书籍信息，成功后可以再次调用 BambookFindNextBook
    查找剩下的书籍信息，查找结束后应调用 BambookFindBookClose 关闭句柄。\n
    该函数会阻塞执行，直到操作成功或失败

    \param hConn        连接句柄
    \param pCondition   查询条件，目前暂不支持，必须传入空指针
    \param pInfo        信息指针，用于返回书籍信息。调用前应设置 pInfo->cbSize = SizeOf(BambookBookInfo)
    \param hFind        句柄指针，如果查找成功返回查找句柄
    \return             成功返回 BR_SUCC，如果找不到书籍返回 BR_EOF，其它错误返回错误代码
*/
BB_RESULT
BBAPI 
BambookFindFirstBook (
    __in BB_HANDLE hConn, 
    __in_opt intptr_t pCondition,
    __out BambookBookInfo * pInfo,
    __out BB_HANDLE * hFind
    );

/*! 获取 Bambook 下一本书籍信息

    在调用 BambookFindFirstBook 成功后再调用本函数，查找后继的书籍信息。\n
    该函数会阻塞执行，直到操作成功或失败

    \param hFind    查找句柄
    \param pInfo    信息指针，用于返回书籍信息。调用前应设置 pInfo->cbSize = SizeOf(BambookBookInfo)
    \return         成功返回 BR_SUCC，如果找不到书籍返回 BR_EOF，其它错误返回错误代码
*/
BB_RESULT
BBAPI 
BambookFindNextBook (
    __in BB_HANDLE hFind, 
    __out BambookBookInfo * pInfo
    );

/*! 关闭 Bambook 书籍查找句柄

    在调用 BambookFindFirstBook 后得到的句柄，在查找完成后应调用该函数释放。\n
    该函数会阻塞执行，直到操作成功或失败

    \param hFind    查找句柄
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookFindBookClose (
    __in BB_HANDLE hFind
    );

/*! 根据书籍 Id 查找对应的书籍信息

    该函数会自动判断设备固件版本，当固件支持的通讯协议 protocalVersion < 20 
    时，会使用遍历的方式来查找。\n
    该函数会阻塞执行，直到操作成功或失败

    \param hConn        连接句柄
    \param lpszAppId    对应书籍信息中的 AppId
    \param lpszBookId   对应书籍信息中的 bookGuid
    \param pInfo        信息指针，用于返回书籍信息。该参数可以传 NULL，此时可以根据返回
                        值来判断文件是否存在。\n如果参数不为 NULL，则调用前应设置 
                        pInfo->cbSize = SizeOf(BambookBookInfo)
    \return             成功返回 BR_SUCC，书籍不存在返回 BR_INVALID_FILE，失败返回 BR_FAIL 或错
                        误原因代码
*/
BB_RESULT
BBAPI 
BambookGetBookInfoById (
    __in BB_HANDLE hConn, 
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __out_opt BambookBookInfo * pInfo
    );

/*! 取得一本 Bambook 书籍的章节数

    该函数会阻塞执行，直到操作成功或失败

    \param hConn        连接句柄
    \param lpszAppId    对应书籍信息中的 AppId
    \param lpszBookId   对应书籍信息中的 bookGuid
    \param uCount       返回章节数
    \return             成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookGetBookChapterCount (
    __in BB_HANDLE hConn,
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __out uint32_t * uCount
    );

/*! 取得一本 Bambook 书籍的章节信息

    该函数会阻塞执行，直到操作成功或失败

    \param hConn        连接句柄
    \param lpszAppId    对应书籍信息中的 AppId
    \param lpszBookId   对应书籍信息中的 bookGuid
    \param uIndex       要取得信息的章节索引号
    \param pInfo        信息指针，用于返回章节信息。调用前应设置 pInfo->cbSize = SizeOf(BambookChapterInfo)
    \return             成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookGetBookChapterInfo (
    __in BB_HANDLE hConn,
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __in uint32_t uIndex,
    __out BambookChapterInfo * pInfo
    );
//! @}

//==============================================================================
//! \addtogroup BookmarkAPI 书籍阅读书签相关 API
//==============================================================================

//! @{
/*! 取得一本 Bambook 书籍的阅读书签信息

    该函数会阻塞执行，直到操作成功或失败\n
    该函数要求固件支持的通讯协议 protocalVersion 最低版本为：21

    \param hConn        连接句柄
    \param lpszAppId    对应书籍信息中的 AppId
    \param lpszBookId   对应书籍信息中的 bookGuid
    \param pInfo        信息指针，用于返回书籍阅读书签信息。调用前应设置 pInfo->cbSize = SizeOf(BambookBookmarkInfo)
    \return             成功返回 BR_SUCC，如果设备固件不支持该功能返回 BR_FIRM_NOT_SUPPORT，其它
                        错误返回错误原因代码
*/
BB_RESULT
BBAPI 
BambookGetBookmark (
    __in BB_HANDLE hConn,
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __out BambookBookmarkInfo * pInfo
    );

/*! 设置一本 Bambook 书籍的阅读书签信息

    pInfo 参数既作为传入的参数用来设置书签信息，又用于返回设置完成后新的书签
    信息，可用来对设置结果进行验证。\n
    该函数会阻塞执行，直到操作成功或失败。\n
    该函数要求固件支持的通讯协议 protocalVersion 最低版本为：21

    \param hConn        连接句柄
    \param lpszAppId    对应书籍信息中的 AppId
    \param lpszBookId   对应书籍信息中的 bookGuid
    \param pInfo        信息指针，用于设置和返回书籍阅读书签信息。调用前应设置 pInfo->cbSize = SizeOf(BambookBookmarkInfo)
    \return             成功返回 BR_SUCC，如果设备固件不支持该功能返回 BR_FIRM_NOT_SUPPORT，其它
                        错误返回错误原因代码
*/
BB_RESULT
BBAPI 
BambookSetBookmark (
    __in BB_HANDLE hConn,
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __inout BambookBookmarkInfo * pInfo
    );

/*! 取得最后一次阅读的书籍名

    该函数会阻塞执行，直到操作成功或失败。\n
    该函数要求固件支持的通讯协议 protocalVersion 最低版本为：21

    \param hConn        连接句柄
    \param lpszAppId    对应书籍信息中的 AppId，调用时必须保证分配的长度 >= 20
    \param lpszBookId   对应书籍信息中的 bookGuid，调用时必须保证分配的长度 >= 20
    \return             成功返回 BR_SUCC，如果设备固件不支持该功能返回 BR_FIRM_NOT_SUPPORT，如果
                        最后其它阅读书籍不存在返回 BR_INVALID_FILE，其它错误返回错误原因代码
*/
BB_RESULT
BBAPI 
BambookGetLastReadBook (
    __in BB_HANDLE hConn,
    __out_ecount(20) char * lpszAppId,
    __out_ecount(20) char * lpszBookId
    );

/*! 取得当前被打开的书籍名

    该函数会阻塞执行，直到操作成功或失败\n
    该函数要求固件支持的通讯协议 protocalVersion 最低版本为：21

    \param hConn        连接句柄
    \param lpszAppId    对应书籍信息中的 AppId，调用时必须保证分配的长度 >= 20
    \param lpszBookId   对应书籍信息中的 bookGuid，调用时必须保证分配的长度 >= 20
    \return             成功返回 BR_SUCC，如果设备固件不支持该功能返回 BR_FIRM_NOT_SUPPORT，如果
                        设备刚开机还没有打开书籍返回 BR_INVALID_FILE，其它错误返回错误原因代码
*/
BB_RESULT
BBAPI 
BambookGetCurrentReadBook (
    __in BB_HANDLE hConn,
    __out_ecount(20) char * lpszAppId,
    __out_ecount(20) char * lpszBookId
    );
//! @}

//==============================================================================
//! \addtogroup BookTransAPI 设备数据传输 API
//==============================================================================

//! @{
/*! 向 Bambook 传输自有书，传到Bambook以后的书籍ID为随机生成的字串

    调用该函数后立即返回。\n
    如果调用成功，传输过程会调用回调函数通知状态和进度。\n
    如果不使用回调，可以传入 NULL，这种方式下可使用 BambookGetSendPrivBookStatus
    来查询当前的进度和完成情况。

    \param hConn            连接句柄
    \param pszSnbFile       自有书全路径文件名
    \param pCallbackFunc    传输过程中回调函数，回调函数将在单独的线程中执行，可为空。
    \param userData         在回调中传回
    \return                 成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookAddPrivBook (
    __in BB_HANDLE hConn,
    __in const char * pszSnbFile,
    __callback TransCallback pCallbackFunc,
    __in_opt intptr_t userData
    );

/*! 向 Bambook 传输自有书，并返回自动生成的 BookId 名称

    调用该函数后立即返回。如果调用成功，传输过程会调用回调函数通知状态和进度。
    如果不使用回调，可以传入 NULL，这种方式下可使用 BambookGetSendPrivBookStatus
    来查询当前的进度和完成情况。

    \param hConn            连接句柄
    \param pszSnbFile       自有书全路径文件名
    \param pCallbackFunc    传输过程中回调函数，回调函数将在单独的线程中执行，可为空。
    \param userData         在回调中传回
    \param lpszBookId       返回自动生成的 BookId，接收缓冲区长度应 >= 20，可为 NULL
    \return                 成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookAddPrivBookEx (
    __in BB_HANDLE hConn,
    __in const char * pszSnbFile,
    __callback TransCallback pCallbackFunc,
    __in_opt intptr_t userData,
    __out_ecount_opt(20) char * lpszBookId
    );

/*! 向 Bambook 传输自有书，并指定书籍ID，书籍ID长度大于0不得超过char[20]，
    ID为英文和字母，最后四位为".snb"。本函数可以用于替换Bambook内特定书籍。

    调用该函数后立即返回。如果调用成功，传输过程会调用回调函数通知状态和进度。
    如果不使用回调，可以传入 NULL，这种方式下可使用 BambookGetSendPrivBookStatus
    来查询当前的进度和完成情况。
    当固件支持的通讯协议 protocalVersion >= 20 时，替换后的书籍阅读位置书签将保留。

    \param hConn            连接句柄
    \param pszSnbFile       自有书全路径文件名
    \param lpszBookId       书籍ID
    \param pCallbackFunc    传输过程中回调函数，回调函数将在单独的线程中执行，可为空。
    \param userData         在回调中传回
    \return                 成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookReplacePrivBook (
    __in BB_HANDLE hConn,
    __in const char * pszSnbFile, 
    __in const char * lpszBookId,
    __callback TransCallback pCallbackFunc, 
    __in_opt intptr_t userData
    );

/*! 查询当前向 Bambook 传输自有书操作的进度和状态

    当使用非回调方式向 Bambook 传输自有书时，可通过该函数查询传输状态。\n
    如果当前没有处于传输状态或者传输已完成，status 将返回 TRANS_STATUS_DONE\n
    如果传输失败，status 返回 TRANS_STATUS_ERR，传输过程中返回 TRANS_STATUS_TRANS

    \param hConn    连接句柄
    \param status   指针，返回传输状态
    \param progress 指针，返回传输进度，0..100
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookGetSendPrivBookStatus (
    __in BB_HANDLE hConn,
    __out uint32_t * status,
    __out uint32_t * progress
    );

/*! 删除 Bambook 自有书

    该函数会阻塞执行，直到操作成功或失败\n
    当固件支持的通讯协议 protocalVersion  >= 20 时，删除不存在的文件会返回 
    BR_INVALID_FILE

    \param hConn        连接句柄
    \param lpszBookId   对应自有书信息中的 bookGuid
    \return             成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookDeletePrivBook (
    __in BB_HANDLE hConn, 
    __in const char * lpszBookId
    );

/*! 向 Bambook 请求自有书文件

    调用该函数后立即返回。如果调用成功，传输过程会调用回调函数通知状态和进度。\n
    如果不使用回调，可以传入 NULL，这种方式下可使用 BambookGetFetchPrivBookStatus
    来查询当前的进度和完成情况。

    \param hConn            连接句柄
    \param lpszBookId       对应自有书信息中的 bookGuid
    \param lpszFilePath     接收自有书文件存放目录
    \param pCallbackFunc    传输过程中回调函数，回调函数将在单独的线程中执行，可为空。
    \param userData         在回调中传回
    \return                 成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookFetchPrivBook (
    __in BB_HANDLE hConn, 
    __in const char * lpszBookId, 
    __in const char * lpszFilePath,
    __callback TransCallback pCallbackFunc, 
    __in_opt intptr_t userData
    );

/*! 查询当前向 Bambook 请求自有书操作的进度和状态

    当使用非回调方式调用 BambookFetchPrivBook 时，可通过该函数查询传输状态。\n
    如果当前没有处于传输状态或者传输已完成，status 将返回 TRANS_STATUS_DONE\n
    如果传输失败，status 返回 TRANS_STATUS_ERR，传输过程中返回 TRANS_STATUS_TRANS

    \param hConn    连接句柄
    \param status   指针，返回传输状态
    \param progress 指针，返回传输进度，0..100
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookGetFetchPrivBookStatus (
    __in BB_HANDLE hConn,
    __out uint32_t * status,
    __out uint32_t * progress
    );

/*! 向 Bambook 请求自有书封面图片文件

    该函数会阻塞执行，直到操作成功或失败

    \param hConn            连接句柄
    \param lpszBookId       对应自有书信息中的 bookGuid
    \param lpszFilePath     接收自有书封面图片文件存放目录
    \param lpszCoverName    返回封面图片文件名，调用时必须保证分配的长度 >= 100
    \return                 成功返回 BR_SUCC，如果书籍不存在或没有封面返回 BR_INVALID_FILE，其它错
                            误返回错误原因代码
*/
BB_RESULT
BBAPI 
BambookFetchPrivBookCover (
    __in BB_HANDLE hConn, 
    __in const char * lpszBookId, 
    __in const char * lpszFilePath,
    __out_ecount(100) char * lpszCoverName
    );
//! @}

//==============================================================================
//! \addtogroup CLBookAPI 版权书处理相关 API
//==============================================================================

//! @{
/*! 控制 Bambook 添加或更新一本版权书

    该函数可以控制 Bambook 更新一本版权书。如果该版权书已经在书架上了，则执
    行章节更新操作。如果该版权书不在用户书架上，则自动将该书添加到用户书架上
    并在 Bambook 上执行下载和更新操作。\n
    该函数只负责通知 Bambook 更新书籍，不会等待更新完成，也不会返回更新结果。
    Bambook 会以任务队列的方式执行更新操作，在队列中的任务重启设备后将丢失。

    \param hConn        连接句柄
    \param lpszAppId    对应书籍信息中的 AppId
    \param lpszBookId   对应书籍信息中的 bookGuid
    \return             成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookUpdateBook (
    __in BB_HANDLE hConn, 
    __in const char * lpszAppId,
    __in const char * lpszBookId
    );

/*! 控制 Bambook 更新书架

    该函数可以控制 Bambook 更新用户书架。相当于用户在设备上执行“全部更新”
    功能。

    \param hConn    连接句柄
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookUpdateBookShelf (
    __in BB_HANDLE hConn
    );

/*! 删除 Bambook 书籍

    该函数会阻塞执行，直到操作成功或失败\n
    当固件支持的通讯协议 protocalVersion >= 20 时，删除不存在的文件会返回
    BR_INVALID_FILE

    \param hConn        连接句柄
    \param lpszAppId    对应书籍信息中的 AppId
    \param lpszBookId   对应书籍信息中的 bookGuid
    \return             成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookDeleteBook (
    __in BB_HANDLE hConn, 
    __in const char * lpszAppId,
    __in const char * lpszBookId
    );
//! @}

//==============================================================================
//! \addtogroup CataAPI 分类处理相关 API
//==============================================================================

//! @{
/*! 创建书架分类信息句柄

    创建成功后的句柄可通过 BambookCatalogLoad 来取得设备分类信息，
    使用完成后应通过 BambookCatalogFree 关闭

    \param hCatalog 分类信息句柄
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogCreate (
    __out BB_HANDLE * hCatalog
    );

/*! 关闭书架分类信息句柄

    通过 BambookCatalogCreate 创建的句柄在使用完成后应调用本函数释放

    \param hCatalog 分类信息句柄
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogFree (
    __in BB_HANDLE hCatalog
    );

/*! 从 Bambook 中读取书架分类信息

    执行成功后取得分类信息，操作完成后可使用 BambookCatalogSave 将分类信息
    保存到 Bambook。该函数会阻塞执行，直到操作成功或失败\n
    该函数要求固件支持的通讯协议 protocalVersion 最低版本为：19

    \param hConn    连接句柄
    \param hCatalog 分类信息句柄
    \return         成功返回 BR_SUCC，如果设备固件不支持分类返回 BR_FIRM_NOT_SUPPORT，其它
                    错误返回错误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogLoad (
    __in BB_HANDLE hConn,
    __in BB_HANDLE hCatalog
    );

/*! 将书架分类信息保存到 Bambook 中

    该函数会阻塞执行，直到操作成功或失败\n
    该函数要求固件支持的通讯协议 protocalVersion 最低版本为：19

    \param hConn    连接句柄
    \param hCatalog 分类信息句柄
    \return         成功返回 BR_SUCC，如果设备固件不支持分类返回 BR_FIRM_NOT_SUPPORT，其它
                    错误返回错误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogSave (
    __in BB_HANDLE hConn,
    __in BB_HANDLE hCatalog
    );

/*! 取得分类信息中包含的分类总数

    \param hCatalog 分类信息句柄
    \param uCount   返回分类总数
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogGetCount (
    __in BB_HANDLE hCatalog,
    __out uint32_t * uCount
    );

/*! 取得分类信息中的指定分类名称

    \param hCatalog 分类信息句柄
    \param uIndex   要取得的分类索引号，从 0 开始
    \param lpszName 返回分类名称，调用时必须保证分配的长度 >= 100
    \return         成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                    误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogGetItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __out_ecount(100) char * lpszName
    );

/*! 删除分类信息中的指定分类

    \param hCatalog 分类信息句柄
    \param uIndex   要删除的分类索引号，从 0 开始
    \return         成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                    误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogDeleteItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex
    );

/*! 修改分类信息中的指定分类名称

    \param hCatalog 分类信息句柄
    \param uIndex   要修改的分类索引号，从 0 开始
    \param lpszName 新的分类名称
    \return         成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                    误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogRenameItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in const char * lpszName
    );

/*! 在分类信息中指定位置插入新的分类

    \param hCatalog 分类信息句柄
    \param uIndex   要插入的分类索引位置，0 表示插入在最前面，超过最大值时追加在尾部
    \param lpszName 新的分类名称
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogInsertItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in const char * lpszName
    );

/*! 在分类信息尾部增加新的分类

    \param hCatalog 分类信息句柄
    \param lpszName 新的分类名称
    \return         成功返回 BR_SUCC，其它错误返回错误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogAppendItem (
    __in BB_HANDLE hCatalog,
    __in const char * lpszName
    );

/*! 移动分类信息中指定分类到新的位置

    \param hCatalog     分类信息句柄
    \param uIndex       要移动的分类索引号，从 0 开始
    \param uNewIndex    新的索引号位置，从 0 开始
    \return             成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                        误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogMoveItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in uint32_t uNewIndex
    );

/*! 取得分类信息中指定分类包含的书籍数

    \param hCatalog 分类信息句柄
    \param uIndex   要取得的分类索引号，从 0 开始
    \param uCount   返回该分类下的书籍总数
    \return         成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                    误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogGetBookCount (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __out uint32_t * uCount
    );

/*! 取得分类信息中的指定分类下指定书籍的信息

    \param hCatalog     分类信息句柄
    \param uIndex       要取得的分类索引号，从 0 开始
    \param uBookIndex   要取得的书籍索引号，从 0 开始
    \param lpszAppId    对应书籍信息中的 AppId，调用时必须保证分配的长度 >= 20
    \param lpszBookId   对应书籍信息中的 bookGuid，调用时必须保证分配的长度 >= 20
    \return             成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                        误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogGetBook (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in uint32_t uBookIndex,
    __out_ecount(20) char * lpszAppId,
    __out_ecount(20) char * lpszBookId
    );

/*! 从分类信息中的指定分类下移除指定的书籍

    该函数只是将书籍信息从分类中移除，不会删除设备上的书籍

    \param hCatalog     分类信息句柄
    \param uIndex       要操作的分类索引号，从 0 开始
    \param uBookIndex   要移除的书籍索引号，从 0 开始
    \return             成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                        误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogRemoveBook (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in uint32_t uBookIndex
    );

/*! 在分类信息中的指定分类下按指定的位置插入书籍

    \param hCatalog     分类信息句柄
    \param uIndex       要操作的分类索引号，从 0 开始
    \param uBookIndex   要插入的书籍索引号，0 表示插入在最前面，超过最大值时追加在尾部
    \param lpszAppId    要插入书籍的 AppId
    \param lpszBookId   要插入书籍的 BookID
    \return             成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                        误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogInsertBook (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in uint32_t uBookIndex,
    __in const char * lpszAppId,
    __in const char * lpszBookId
    );

/*! 在分类信息中的指定分类下追加书籍

    \param hCatalog     分类信息句柄
    \param uIndex       要操作的分类索引号，从 0 开始
    \param lpszAppId    要插入书籍的 AppId
    \param lpszBookId   要插入书籍的 BookID
    \return             成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                        误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogAppendBook (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in const char * lpszAppId,
    __in const char * lpszBookId
    );

/*! 在分类信息中的指定分类移动指定书籍到新的位置

    \param hCatalog         分类信息句柄
    \param uIndex           要操作的分类索引号，从 0 开始
    \param uBookIndex       要移动的书籍索引号，从 0 开始
    \param uNewBookIndex    新的索引号位置
    \return                 成功返回 BR_SUCC，如果索引超出范围返回 BR_OUT_OF_BOUNDS，其它错误返回错
                            误原因代码
*/
BB_RESULT
BBAPI 
BambookCatalogMoveBook (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in uint32_t uBookIndex,
    __in uint32_t uNewBookIndex
    );

/*! 将指定书籍添加到指定分类中

    如果分类不存在，则自动追加一个新的分类。
    如果指定分类下该书籍已经存在，则直接返回成功。

    \param hCatalog         分类信息句柄
    \param lpszAppId        要添加书籍的 AppId
    \param lpszBookId       要添加书籍的 BookID
    \param lpszCataName     要添加到的分类名
    \return                 成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI
BambookCatalogAddBookByName (
    __in BB_HANDLE hCatalog,
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __in const char * lpszCataName
    );
//! @}

//==============================================================================
//! \addtogroup MiscAPI 设备其它功能 API
//==============================================================================

//! @{
/*! 向 Bambook 发送按键命令

    该函数要求固件支持的通讯协议 protocalVersion 最低版本为：12

    \param hConn    连接句柄
    \param key      按键值
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookKeyPress (
    __in BB_HANDLE hConn, 
    __in BambookKey key
    );

/*! 控制 Bambook 的 TTS 朗读指定的文本

    该函数要求固件支持的通讯协议 protocalVersion 最低版本为：12

    \param hConn    连接句柄
    \param lpszText 要朗读的文本内容，长度不能超过40个中文
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookTTSPlay (
    __in BB_HANDLE hConn, 
    __in const char * lpszText
    );

/*! 控制 Bambook 停止由 BambookTTSPlay 启动的 TTS 朗读

    该函数要求固件支持的通讯协议 protocalVersion 最低版本为：12

    \param hConn    连接句柄
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookTTSStop (
    __in BB_HANDLE hConn
    );
//! @}

//==============================================================================
//! \addtogroup SNBWrapAPI SNB 文件处理封装 API
//==============================================================================

//! @{
/*! 把一个符合 SNB 目录结构的目录打成 SNB 包

    \param snbName  生成的 snb 文件名
    \param rootDir  要打包的根目录
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL、BR_IO_ERROR 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookPackSnbFromDir (
    __in const char * snbName, 
    __in const char * rootDir
    );

/*! 根据相对路径文件名从 SNB 包中解出一个文件

    \param snbName      要操作的 snb 文件名
    \param relativePath 要解压的文件在包中的相对路径和文件名，比如："snbf/book.snbf"
    \param outputName   解压出来的文件保存的全路径文件名
    \return             成功返回 BR_SUCC，失败返回 BR_FAIL、BR_IO_ERROR、BR_FILE_NOT_INSIDE 或
                        错误原因代码
*/
BB_RESULT
BBAPI 
BambookUnpackFileFromSnb (
    __in const char * snbName, 
    __in const char * relativePath, 
    __in const char * outputName
    );

/*! 检查一个文件是否合法的 SNB 文件

    \param snbName  要操作的 snb 文件名
    \return         如果文件合法 BR_SUCC，否则返回 BR_INVALID_FILE 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookVerifySnbFile (
    __in const char * snbName
    );
//! @}

//==============================================================================
//! \addtogroup SNBAPI SNB 文件操作 API
//==============================================================================

//! @{
/*! 打开一个 SNB 文件，返回 SNB 对象句柄

    操作完成后应调用 BambookSnbClose 关闭对象，释放资源。
    同一个文件 SNB 文件，不支持同时被多次打开，多线程下操作同一个 SNB 句柄
    可能会有未知错误。

    \param snbName  要打开的 snb 文件名
    \param hSnb     句柄指针，执行成功返回 SNB 对象句柄
    \return         如果打开文件成功返回 BR_SUCC，否则返回 BR_INVALID_FILE 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookSnbOpen (
    __in const char * snbName,
    __out BB_HANDLE * hSnb
    );

/*! 关闭一个 SNB 对象句柄

    \param hSnb     要关闭的对象句柄
    \return         成功返回 BR_SUCC，失败返回 BR_FAIL
*/
BB_RESULT
BBAPI 
BambookSnbClose (
    __in BB_HANDLE hSnb
    );

/*! 获取 SNB 文件中指定文件的信息

    \param hSnb         要操作的对象句柄
    \param relativePath 要获取的文件在包中的相对路径和文件名，比如："snbf/book.snbf"
    \param pInfo        信息指针，用于返回文件信息。调用前应设置 pInfo->cbSize = SizeOf(SnbFileInfo)
    \return             成功返回 BR_SUCC，如果找不到文件返回 BR_FILE_NOT_INSIDE，其它错误返回错误代码
*/
BB_RESULT
BBAPI 
BambookSnbGetFileInfo (
    __in BB_HANDLE hSnb,
    __in const char * relativePath,
    __out SnbFileInfo * pInfo
    );

/*! 获取 SNB 文件中第一个文件信息

    \param hSnb     要操作的对象句柄
    \param pInfo    信息指针，用于返回文件信息。调用前应设置 pInfo->cbSize = SizeOf(SnbFileInfo)
    \return         成功返回 BR_SUCC，如果找不到文件返回 BR_EOF，其它错误返回错误代码
*/
BB_RESULT
BBAPI 
BambookSnbGetFirstFileInfo (
    __in BB_HANDLE hSnb,
    __out SnbFileInfo * pInfo
    );

/*! 获取 SNB 文件中下一个文件信息

    \param hSnb     要操作的对象句柄
    \param pInfo    信息指针，用于返回文件信息。调用前应设置 pInfo->cbSize = SizeOf(SnbFileInfo)
    \return         成功返回 BR_SUCC，如果找不到文件返回 BR_EOF，其它错误返回错误代码
*/
BB_RESULT
BBAPI 
BambookSnbGetNextFileInfo (
    __in BB_HANDLE hSnb,
    __out SnbFileInfo * pInfo
    );

/*! 从 SNB 中读取一个文件内容到指定内存缓冲区

    \param hSnb         要操作的对象句柄
    \param relativePath 要解压的文件在包中的相对路径和文件名，比如："snbf/book.snbf"
    \param uOffset      要读取的起始偏移量
    \param pBuffer      用于存放解压内容的缓冲区指针
    \param uBufferSize  缓冲区大小
    \param uReadBytes   返回实际读取的字节数，该字节数为缓冲区大小与可读取字节数的小值
    \return             成功返回 BR_SUCC，如果找不到文件返回 BR_FILE_NOT_INSIDE，uOffset 超出文件
                        范围返回 BR_EOF，其它错误返回错误代码
*/
BB_RESULT
BBAPI 
BambookSnbUnpackToMemory (
    __in BB_HANDLE hSnb,
    __in const char * relativePath,
    __in uint32_t uOffset,
    __out void * pBuffer,
    __in uint32_t uBufferSize,
    __out uint32_t * uReadBytes
    );

/*! 从 SNB 中读取一个文件内容并保存为文件

    \param hSnb         要操作的对象句柄
    \param relativePath 要解压的文件在包中的相对路径和文件名，比如："snbf/book.snbf"
    \param outputName   解压出来的文件保存的全路径文件名
    \return             成功返回 BR_SUCC，失败返回 BR_FAIL、BR_FILE_NOT_INSIDE 或错误原因代码
*/
BB_RESULT
BBAPI 
BambookSnbUnpackToFile (
    __in BB_HANDLE hSnb,
    __in const char * relativePath,
    __in const char * outputName
    );
//! @}
//! @}

#ifdef __cplusplus
}
#endif

#endif /* __BAMBOOKCORE_H__ */
