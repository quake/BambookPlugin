/**************************************************************
** Copyright (C) 2009-2010 盛大网络
** All right reserved
***************************************************************
**
** 项目名称：Bambook SDK
** 功能简介：Bambook PC 开发核心组件头文件
**
** 原始作者：果壳电子 Bambook SDK 项目组
** 备    注：
** 建立时间：2010-10-12
** 最后更新：2010-11-05
** 版    本：1.1
***************************************************************
** 单元标识：$Id: $
** 版本历史：
** 修 改 者：
** 最近修改：
**************************************************************/

#ifndef __BAMBOOKCORE_H__
#define __BAMBOOKCORE_H__
#include <stdint.h>
//==============================================================================
// 公共类型及常量定义
//==============================================================================

// API 返回值类型
typedef int32_t BB_RESULT;

// 连接句柄
typedef intptr_t BB_HANDLE;

// SDK 版本号
#define BAMBOOK_SDK_VERSION 0x00090000

// 使用 USB 连接 Bambook 的设备 IP
#define DEFAULT_BAMBOOK_IP  "192.168.250.2"

// 函数返回值定义
#define BR_SUCC             0     // 操作成功
#define BR_FAIL             1001  // 操作失败
#define BR_NOT_IMPL         1002  // 该功能还未实现
#define BR_DISCONNECTED     1003  // 与设备的连接已断开
#define BR_PARAM_ERROR      1004  // 调用函数传入的参数错误
#define BR_TIMEOUT          1005  // 操作或通讯超时
#define BR_INVALID_HANDLE   1006  // 传入的句柄无效
#define BR_INVALID_FILE     1007  // 传入的文件不存在或格式无效
#define BR_INVALID_DIR      1008  // 传入的目录不存在
#define BR_BUSY             1010  // 设备忙，另一个操作还未完成
#define BR_EOF              1011  // 文件或操作已结束
#define BR_IO_ERROR         1012  // 文件读写失败
#define BR_FILE_NOT_INSIDE  1013  // 指定的文件不在包里

// 当前连接状态
#define CONN_CONNECTED      0     // 已连接
#define CONN_DISCONNECTED   1     // 未连接或连接已断开
#define CONN_CONNECTING     2     // 正在连接
#define CONN_WAIT_FOR_AUTH  3     // 已连接，正在等待身份验证（暂未实现）

//传输状态
#define TRANS_STATUS_TRANS	0	//正在传输
#define TRANS_STATUS_DONE	1	//传输完成
#define TRANS_STATUS_ERR	2	//传输出错

//按键定义
enum BambookKey
{
        BBKeyNum0 = 0, BBKeyNum1, BBKeyNum2, BBKeyNum3, BBKeyNum4,
        BBKeyNum5, BBKeyNum6, BBKeyNum7, BBKeyNum8, BBKeyNum9,
        BBKeyStar, BBKeyCross, BBKeyUp, BBKeyDown, BBKeyLeft, BBKeyRight, BBKeyPageUp, BBKeyPageDown,
        BBKeyOK, BBKeyESC, BBKeyBookshelf, BBKeyStore, BBKeyTTS, BBKeyMenu, BBKeyInteract
};

// 设备信息结构
struct DeviceInfo
{
    uint32_t cbSize;              // 结构大小
    char sn[20];                  // 设备序列号
    char firmwareVersion[20];     // 设备固件版本
    uint32_t deviceVolume;        // 设备总存储空间，单位为KB
    uint32_t spareVolume;         // 剩余存储空间，单位为KB
};

// 自有书信息结构
struct PrivBookInfo
{
    uint32_t cbSize;              // 结构大小
    char bookGuid[20];            // 书籍id(在设备里的snb文件名)
    char bookName[80];            // 书名
    char bookAuthor[40];          // 作者
    char bookAbstract[256];       // 摘要
};

////////////////////////////////////////////////////////////////////////////////
// 功能：传输自有书回调函数
// 参数：status: 传输状态
//       progress: 传输进度，0..100
//       userData: 用户调用API时传入的数据
// 注释：在调用自有书传输时使用
////////////////////////////////////////////////////////////////////////////////
typedef void(* TransCallback)(uint32_t status, uint32_t progress, intptr_t userData);

//==============================================================================
// SDK API 函数声明
//==============================================================================

////////////////////////////////////////////////////////////////////////////////
// 功能：取得SDK DLL版本号
// 参数：version: 指针，返回版本号
// 返回：成功返回 BR_SUCC
// 注释：调用该函数可以返回DLL支持SDK版本号，可用于兼容性处理
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetSDKVersion(uint32_t * version);

////////////////////////////////////////////////////////////////////////////////
// 功能：连接Bambook设备
// 参数：lpszIP: Bambook IP地址，传空时使用默认值 DEFAULT_BAMBOOK_IP
//       timeOut: 超时值，单位毫秒，0为默认
//       hConn: 句柄指针，执行成功返回连接句柄
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL，超时返回 BR_TIMEOUT
// 注释：调用函数后会阻塞执行，连接成功后 hConn 为连接句柄。
//       连接被中断或通讯结束后应调用 BambookDisconnect 释放资源
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookConnect(const char * lpszIP, uint32_t timeOut, BB_HANDLE * hConn);

////////////////////////////////////////////////////////////////////////////////
// 功能：断开Bambook设备的连接
// 参数：hConn: 连接句柄
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL
// 注释：调用函数后会阻塞执行，直到连接被断开或失败，成功后 hConn 句柄将不可用
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookDisconnect(BB_HANDLE hConn);

////////////////////////////////////////////////////////////////////////////////
// 功能：查询当前Bambook设备的连接状态
// 参数：hConn: 连接句柄
//       status: 指针，返回连接状态
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL
// 注释：应用在调用其它API前可调用该函数以查询连接状态
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetConnectStatus(BB_HANDLE hConn, uint32_t * status);

////////////////////////////////////////////////////////////////////////////////
// 功能：获取Bambook基本信息
// 参数：hConn: 连接句柄
//       pInfo: 信息指针，用于返回基本信息。调用前应设置 pInfo->cbSize = SizeOf(DeviceInfo)
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
//       如果 pInfo->cbSize 不正确将返回 BR_PARAM_ERROR
// 注释：调用函数后会阻塞执行，直到操作成功或失败
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetDeviceInfo(BB_HANDLE hConn, DeviceInfo * pInfo);

////////////////////////////////////////////////////////////////////////////////
// 功能：获取Bambook第一本自有书信息
// 参数：hConn: 连接句柄
//       pInfo: 信息指针，用于返回自有书信息。调用前应设置 pInfo->cbSize = SizeOf(PrivBookInfo)
// 返回：成功返回 BR_SUCC，如果找不到自有书返回 BR_EOF，其它错误返回错误代码
// 注释：调用该函数后将从头开始从设备查找自有书信息，成功后可以再次调用 BambookGetNextPrivBookInfo
//       查找剩下的自有书信息。该函数会阻塞执行，直到操作成功或失败
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetFirstPrivBookInfo(BB_HANDLE hConn, PrivBookInfo * pInfo);

////////////////////////////////////////////////////////////////////////////////
// 功能：获取Bambook下一本自有书信息
// 参数：hConn: 连接句柄
//       pInfo: 信息指针，用于返回自有书信息。调用前应设置 pInfo->cbSize = SizeOf(PrivBookInfo)
// 返回：成功返回 BR_SUCC，如果找不到自有书返回 BR_EOF，其它错误返回错误代码
// 注释：在调用 BambookGetFirstPrivBookInfo 成功后再调用本函数，查找后继的自有书信息。
//       该函数会阻塞执行，直到操作成功或失败
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookGetNextPrivBookInfo(BB_HANDLE hConn, PrivBookInfo * pInfo);

////////////////////////////////////////////////////////////////////////////////
// 功能：向Bambook传输自有书，传到Bambook以后的书籍ID为随机生成的字串
// 参数：hConn: 连接句柄
//       pszSnbFile: 自有书全路径文件名
//       pCallbackFunc: 传输过程中回调函数，回调函数将在单独的线程中执行
//       userData: 在回调中传回
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
// 注释：调用该函数后立即返回。如果调用成功，传输过程会调用回调函数通知状态和进度
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookAddPrivBook(BB_HANDLE hConn, const char * pszSnbFile,
                                        TransCallback pCallbackFunc, intptr_t userData);

////////////////////////////////////////////////////////////////////////////////
// 功能：向Bambook传输自有书，并指定书籍ID，书籍ID长度大于0不得超过char[20]
//       ID为英文和字母，最后四位为".snb"。
//       本函数可以用于替换Bambook内特定书籍。
// 参数：hConn: 连接句柄
//       pszSnbFile: 自有书全路径文件名
//       lpszBookID: 书籍ID
//       pCallbackFunc: 传输过程中回调函数，回调函数将在单独的线程中执行
//       userData: 在回调中传回
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
// 注释：调用该函数后立即返回。如果调用成功，传输过程会调用回调函数通知状态和进度
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookReplacePrivBook(BB_HANDLE hConn, const char * pszSnbFile, const char * lpszBookID,
                                            TransCallback pCallbackFunc, intptr_t userData);

////////////////////////////////////////////////////////////////////////////////
// 功能：删除Bambook自有书
// 参数：hConn: 连接句柄
//       lpszBookID: 对应自有书信息中的 bookGuid
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
// 注释：该函数会阻塞执行，直到操作成功或失败
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookDeletePrivBook(BB_HANDLE hConn, const char * lpszBookID);

////////////////////////////////////////////////////////////////////////////////
// 功能：向Bambook请求自有书文件
// 参数：hConn: 连接句柄
//       lpszBookID: 对应自有书信息中的 bookGuid
//       lpszFilePath: 接收自有书文件存放目录
//       pCallbackFunc: 传输过程中回调函数，回调函数将在单独的线程中执行
//       userData: 在回调中传回
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
// 注释：调用该函数后立即返回。如果调用成功，传输过程会调用回调函数通知状态和进度
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookFetchPrivBook(BB_HANDLE hConn, const char * lpszBookID, const char * lpszFilePath,
                                          TransCallback pCallbackFunc, intptr_t userData);

////////////////////////////////////////////////////////////////////////////////
// 功能：向Bambook发送按键命令
// 参数：hConn: 连接句柄
//       key: 按键值
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL 或错误原因代码
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookKeyPress(BB_HANDLE hConn, BambookKey key);

////////////////////////////////////////////////////////////////////////////////
// 功能：把一个符合 SNB 目录结构的目录打成 SNB 包
// 参数：snbName: 生成的 snb 文件名
//       rootDir: 要打包的根目录
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL、BR_IO_ERROR 或错误原因代码
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookPackSnbFromDir(const char * snbName, const char * rootDir);

////////////////////////////////////////////////////////////////////////////////
// 功能：根据相对路径文件名从 SNB 包中解出一个文件
// 参数：snbName: 要操作的 snb 文件名
//       relativePath: 要解压的文件在包中的相对路径和文件名，比如："snbf/book.snbf"
//       outputName: 解压出来的文件保存的全路径文件名
// 返回：成功返回 BR_SUCC，失败返回 BR_FAIL、BR_IO_ERROR、BR_FILE_NOT_INSIDE 或错误原因代码
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookUnpackFileFromSnb(const char * snbName, const char * relativePath, const char * outputName);

////////////////////////////////////////////////////////////////////////////////
// 功能：检查一个文件是否合法的 SNB 文件
// 参数：snbName: 要操作的 snb 文件名
// 返回：如果文件合法 BR_SUCC，否则返回 BR_INVALID_FILE 或错误原因代码
////////////////////////////////////////////////////////////////////////////////
extern "C" BB_RESULT BambookVerifySnbFile(const char * snbName);

////////////////////////////////////////////////////////////////////////////////
// 功能：返回错误码对应的中文含义
// 参数：nCode: 错误代码
// 返回：错误信息字符串指针
// 注释：该函数用来取得错误字符串，如果传入未定义的错误代码，将返回 "未知错误"
////////////////////////////////////////////////////////////////////////////////
extern "C" const char * BambookGetErrorString(BB_RESULT nCode);

#endif /* __BAMBOOKCORE_H__ */
