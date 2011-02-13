/*! \file BambookCore.h
    \brief Bambook PC �����������ͷ�ļ�

    Copyright (C) 2009-2011 ʢ������ All right reserved\n

    ��Ŀ���ƣ�Bambook SDK\n
    ���ܼ�飺Bambook PC �����������ͷ�ļ�\n

    ԭʼ���ߣ����ǵ��� Bambook SDK ��Ŀ��\n
    ����ʱ�䣺2010-10-12\n
    �����£�2011-01-05\n

    ��Ԫ��ʶ��$Id $
*/

#ifndef __BAMBOOKCORE_H__
#define __BAMBOOKCORE_H__

//==============================================================================
// �������ͼ���������
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

//! \addtogroup ���Ͷ���
//! @{

//! \addtogroup �������Ͷ���
//! @{

//! \name �������Ͷ���
//! @{

//! API ����ֵ����
typedef int32_t             BB_RESULT;

//! ������
typedef intptr_t            BB_HANDLE;
//! @}
//! @}
//! @}

//! \addtogroup MacroDef �궨��
//! @{

//! \addtogroup CommonMacro ������������
//! @{

//! \name ������������
//! @{

//! SDK �汾�� 0.9.7.0
#define BAMBOOK_SDK_VERSION 0x00090700

//! ʹ�� USB ���� Bambook ���豸 IP
#define DEFAULT_BAMBOOK_IP  "192.168.250.2"

//! ������ AppID
#define PRIVBOOK_APPID      "999"

//! API ���÷�ʽ
#define BBAPI               __cdecl
//! @}
//! @}

//! \addtogroup BBResult ��������ֵ����
//! @{

//! \name ��������ֵ����
//! @{
#define BR_SUCC             0     //!< �����ɹ�
#define BR_FAIL             1001  //!< ����ʧ��
#define BR_NOT_IMPL         1002  //!< �ù��ܻ�δʵ��
#define BR_DISCONNECTED     1003  //!< ���豸�������ѶϿ�
#define BR_PARAM_ERROR      1004  //!< ���ú�������Ĳ�������
#define BR_TIMEOUT          1005  //!< ������ͨѶ��ʱ
#define BR_INVALID_HANDLE   1006  //!< ����ľ����Ч
#define BR_INVALID_FILE     1007  //!< �ļ������ڻ��ʽ��Ч
#define BR_INVALID_DIR      1008  //!< Ŀ¼������
#define BR_FIRM_NOT_SUPPORT 1009  //!< �豸�̼���֧�ָù��ܣ���Ҫ���������µĹ̼��汾
#define BR_BUSY             1010  //!< �豸æ����һ��������δ���
#define BR_EOF              1011  //!< �ļ�������ѽ���
#define BR_IO_ERROR         1012  //!< �ļ���дʧ��
#define BR_FILE_NOT_INSIDE  1013  //!< ָ�����ļ����ڰ���
#define BR_USER_REFUSED     1014  //!< �û����豸�Ͼܾ�������
#define BR_WAIT_FOR_AUTH    1015  //!< �豸�����ӣ�����û��ͨ�������֤���޷�ִ��ָ������
#define BR_OUT_OF_BOUNDS    1016  //!< ����������Χ
#define BR_FILE_EXISTS      1017  //!< \brief �ļ��Ѿ�����
//! @}
//! @}

//! \addtogroup BBConn ��ǰ����״̬
//! @{

//! \name ��ǰ����״̬
//! @{
#define CONN_CONNECTED      0     //!< ������
#define CONN_DISCONNECTED   1     //!< δ���ӡ������ѶϿ����û��ܾ�������
#define CONN_CONNECTING     2     //!< ��������
#define CONN_WAIT_FOR_AUTH  3     //!< \brief �����ӣ����ڵȴ������֤
//! @}
//! @}

//! \addtogroup BBTrans ����״̬
//! @{

//! \name ����״̬
//! @{
#define TRANS_STATUS_TRANS  0     //!< ���ڴ���
#define TRANS_STATUS_DONE   1     //!< �������
#define TRANS_STATUS_ERR    2     //!< \brief �������
//! @}
//! @}
//! @}

//! \addtogroup ���Ͷ���
//! @{

//! \addtogroup ö�ٶ���
//! @{

//! \name ö�ٶ���
//! @{

//! ��������
enum BambookKey
{
    BBKeyNum0 = 0, BBKeyNum1, BBKeyNum2, BBKeyNum3, BBKeyNum4,
    BBKeyNum5, BBKeyNum6, BBKeyNum7, BBKeyNum8, BBKeyNum9,
    BBKeyStar, BBKeyCross, BBKeyUp, BBKeyDown, BBKeyLeft, BBKeyRight, BBKeyPageUp, BBKeyPageDown,
    BBKeyOK, BBKeyESC, BBKeyBookshelf, BBKeyStore, BBKeyTTS, BBKeyMenu, BBKeyInteract
};

//! �豸�̼�֧�ֵĹ���
enum BambookDeviceCap
{
    BBCapCatalog = 0,               //!< ��д���๦��
    BBCapGetBookSize,               //!< ȡ�������ļ���С����
    BBCapBookmark,                  //!< ��д�鼮�Ķ�λ�ù���
    BBCapGetLastReadBook,           //!< ȡ����Ķ��鼮����
    BBCapGetCurrentReadBook,        //!< ȡ��ǰ�Ķ��鼮����
    BBCapKeyPress,                  //!< ģ�ⰴ������
    BBCapTTSPlay                    //!< TTS �������Ź���
};
//! @}
//! @}

//! \addtogroup �ṹ����
//! @{

//! �����ӵ���ǰ��������豸��Ϣ�ṹ
struct BambookDevInfo
{
    uint32_t cbSize;              //!< �ṹ��С
    char ip[32];                  //!< �豸IP��ַ
    uint32_t protocalVersion;     //!< �豸֧�ֵ� PC ͨѶЭ��汾��
};

//! �豸��Ϣ�ṹ
struct DeviceInfo
{
    uint32_t cbSize;              //!< �ṹ��С
    char sn[20];                  //!< �豸���к�
    char firmwareVersion[20];     //!< �豸�̼��汾
    uint32_t deviceVolume;        //!< �豸�ܴ洢�ռ䣬��λΪKB
    uint32_t spareVolume;         //!< ʣ��洢�ռ䣬��λΪKB
    uint32_t protocalVersion;     //!< �豸֧�ֵ� PC ͨѶЭ��汾��
};

//! Bambook �鼮��Ϣ�ṹ
struct BambookBookInfo
{
    uint32_t cbSize;              //!< �ṹ��С
    uint32_t bookType;            //!< �鼮���ͣ� 0 ��Ȩ�飻1 ������
    char bookAppId[20];           //!< �����ṩ����ʶ��"999" Ϊ������
    char bookGuid[20];            //!< �鼮id(���豸���snb�ļ���)
    char bookName[80];            //!< ����
    char bookAuthor[40];          //!< ����
    char bookAbstract[256];       //!< ժҪ
    char bookLatest[80];          //!< �����½ڱ���
    char lastUpdateTime[20];      //!< ������ʱ��
    char bookCover[100];          //!< ����ͼƬ URL
    uint32_t unread;              //!< δ���½���
    uint32_t autoPay;             //!< �Ƿ��Զ����ģ�0 δ�Զ����ģ�1 �Զ�����
    uint32_t bookSize;            //!< �������ļ���С����Ȩ��ʼ��Ϊ 0��Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��23
};

//! \name �������Ͷ���
//! @{

//! ���ڼ������ڰ汾�� API �����˽����ṹ����
typedef BambookBookInfo PrivBookInfo;
//! @}

//! Bambook �鼮�½���Ϣ�ṹ
struct BambookChapterInfo
{
    uint32_t cbSize;              //!< �ṹ��С
    char chapterId[20];           //!< �½�ID
    char chapterName[80];         //!< �½���
    uint32_t chapterBuyStatus;    //!< �½ڹ���״̬�� 0 ����½ڣ�1 �Ѹ���vip�½ڣ�2 δ����vip�½�
    uint32_t chapterDownloadStatus; //!< �½�����״̬�� 0 δ���أ�1 ������
};

//! Bambook �鼮��ǩ��Ϣ�ṹ
struct BambookBookmarkInfo 
{
    uint32_t cbSize;              //!< �ṹ��С
    char chapterId[20];           //!< �½�ID
    char bookmark[64];            //!< ��ǩ��Ϣ��֧�����ָ�ʽ���ڵ�ID|�Ӹýڵ��һ���ֽڿ�ʼ�� offset ���� ҳ��
                                  /*!< �ڵ�IDָ������ snbc �е� text/image �ڵ�ı�ţ���0��ʼ��\n
                                       ���磺"3|336" ��ʾ���½��е������ڵ�ƫ��336�ֽڣ�utf8���룩��\n
                                       �����Ķ�ʱ�ǰ���ҳ�Ű�ģ�ָ����ƫ��λ�ÿ�������ҳ���κ�λ�ö�������Ļ���Ͻ�\n
                                       ���⣬Ҳ����ֱ��ָ���½��ڵ�ҳ�룬�� "5" ��ʾ�� 5 ҳ */
    uint32_t lastReadTime;        //!< ����Ķ�ʱ�䣬��1970-1-1��ʼ��������������ǩʱ 0 ��ʾ���޸�
};

//! SNB �е��ļ���Ϣ�ṹ
struct SnbFileInfo
{
    uint32_t cbSize;              //!< �ṹ��С
    char filePathName[1024];      //!< �ļ��� SNB �е����·�����ļ���
    uint32_t fileSize;            //!< �ļ�ԭʼ��С
};
//! @}

//! \addtogroup �ص���������
//! @{

//! \name �ص���������
//! @{

/*! ����������ص�����

    �ڵ��������鴫��ʱʹ��

    \param status   ����״̬
    \param progress ������ȣ�0..100
    \param userData �û�����APIʱ���������
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
//! \addtogroup BaseAPI ���� API
//==============================================================================

//! @{
/*! ȡ��SDK DLL�汾��

    ���øú������Է���DLL֧��SDK�汾�ţ������ڼ����Դ���

    \param version ָ�룬���ذ汾��
    \return �ɹ����� BR_SUCC
*/
BB_RESULT
BBAPI
BambookGetSDKVersion (
    __out uint32_t * version
    );

/*! ���ش������Ӧ�����ĺ���

    �ú�������ȡ�ô����ַ������������δ����Ĵ�����룬������ "δ֪����"

    \param nCode �������
    \return ������Ϣ�ַ���ָ��
*/
const char *
BBAPI 
BambookGetErrorString (
    __in BB_RESULT nCode
    );

/*! �趨 BambookCore �� API ���պͷ��ص��ַ���ʹ�õ��ַ���

    ͨ���ú���Ӧ����Ӧ�ó����ʼ��ʱ���ã��ɿ������� API ���ַ������룬Ĭ��Ϊ "gbk"

    \param lpszEncoding �ַ������ƣ�ֻ֧�� "utf8" �� "gbk"
    \return             �ɹ����� BR_SUCC����������ȷ���� BR_PARAM_ERROR
*/
BB_RESULT
BBAPI 
BambookSetCharacterEncoding(
    __in const char * lpszEncoding
    );

/*! ȡ�� BambookCore �� API ���պͷ��ص��ַ���ʹ�õ��ַ���

    \param lpszEncoding �����ַ������ƣ�����ʱ���뱣֤����ĳ��� >= 20
    \return             �ɹ����� BR_SUCC����������ȷ���� BR_PARAM_ERROR
*/
BB_RESULT
BBAPI 
BambookGetCharacterEncoding(
    __out_ecount(20) char * lpszEncoding
    );
//! @}

//==============================================================================
//! \addtogroup ConnAPI �豸������� API
//==============================================================================

//! @{
/*! ȡ�õ�һ�����ӵ���ǰ������� Bambook �豸��Ϣ

    \param dwFlags  ���Ҳ�����Ŀǰδʹ�ã�����ʱӦ���� 0
    \param pInfo    �����豸��Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(BambookDevInfo)
    \return         �ɹ����� BR_SUCC������Ҳ����豸���� BR_EOF���������󷵻ش������
*/
BB_RESULT
BBAPI
BambookGetFirstDevice (
    __in uint32_t dwFlags,
    __out BambookDevInfo * pInfo
    );

/*! ȡ����һ�����ӵ���ǰ������� Bambook �豸��Ϣ

    \param pInfo    �����豸��Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(BambookDevInfo)
    \return         �ɹ����� BR_SUCC������Ҳ����豸���� BR_EOF���������󷵻ش������
*/
BB_RESULT
BBAPI
BambookGetNextDevice (
    __out BambookDevInfo * pInfo
    );

/*! ���� Bambook �豸

    ���ú����������ִ�У����ӳɹ��� hConn Ϊ���Ӿ����\n
    ��� timeOut Ϊ 0�����豸֧���û���֤ʱ�����ú������ȴ��û����豸�˽�
    ��ȷ�ϣ�ͨ����ܾ������Ż᷵�ء�\n
    ��� timeOut Ϊ�� 0 ֵ��������� timeOut ʱ�����������豸���ͷ��ؾ����
    �ɹ�������ʱӦ�ó�����Ҫ����ͨ�� BambookGetConnectStatus ȥ����豸�Ƿ�
    �ڵȴ��û���֤ͨ��״̬��ֻ��״̬Ϊ CONN_CONNECTED ʱ�ſɲ����豸��\n
    ���ӱ��жϻ�ͨѶ������Ӧ���� BambookDisconnect �ͷ���Դ

    \param lpszIP   Bambook IP��ַ������ʱʹ��Ĭ��ֵ DEFAULT_BAMBOOK_IP
    \param timeOut  ��ʱֵ����λ���룬0ΪĬ�ϡ�
    \param hConn    ���ָ�룬ִ�гɹ��������Ӿ��
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL����ʱ���� BR_TIMEOUT���û��ܾ����ӷ��� BR_USER_REFUSED��
*/
BB_RESULT
BBAPI 
BambookConnect (
    __in const char * lpszIP,
    __in uint32_t timeOut,
    __out BB_HANDLE * hConn
    );

/*! �Ͽ� Bambook �豸������

    ���ú����������ִ�У�ֱ�����ӱ��Ͽ���ʧ�ܣ��ɹ��� hConn �����������

    \param hConn    ���Ӿ��
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI
BambookDisconnect (
    __in BB_HANDLE hConn
    );

/*! ��ѯ��ǰ Bambook �豸������״̬

    Ӧ���ڵ�������APIǰ�ɵ��øú����Բ�ѯ����״̬��\n
    ���ʹ�ý�������ʱ������ timeOut ֵ����Ҫ�ڵ������� API ֮ǰʹ�øú�
    ����ѯ����״̬��ֻ��״̬Ϊ CONN_CONNECTED ʱ�ſɽ�������������

    \param hConn    ���Ӿ��
    \param status   ָ�룬��������״̬
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookGetConnectStatus (
    __in BB_HANDLE hConn,
    __out uint32_t * status
    );
//! @}

//==============================================================================
//! \addtogroup InfoAPI �豸��Ϣ��� API
//==============================================================================

//! @{
/*! ��ȡ Bambook ������Ϣ

    ���ú����������ִ�У�ֱ�������ɹ���ʧ��

    \param hConn    ���Ӿ��
    \param pInfo    ��Ϣָ�룬���ڷ��ػ�����Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(DeviceInfo)
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ����롣
                    ��� pInfo->cbSize ����ȷ������ BR_PARAM_ERROR
*/
BB_RESULT
BBAPI 
BambookGetDeviceInfo (
    __in BB_HANDLE hConn,
    __out DeviceInfo * pInfo
    );

/*! ���� Bambook �鼮�б���������

    ���û�ͨ�����ݡ�����Ӧ�ó����ֱ�����豸���ֹ����顢ɾ�飬�Լ��豸�ӷ�
    ������ͬ��������ʱ��������������Զ��� 1��Ӧ�ÿ��Ը��ݼ�������ֵ������
    �Ƿ���Ҫ������ܡ�ʹ�� BambookReplacePrivBook API ���ܲ���Ӱ����������

    \param hConn        ���Ӿ��
    \param uChangCount  �����鼮�б���������ÿ�μ�⵽�豸��ܱ�����ü�������� 1
    \return             �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookGetBookShelfChangeCount (
    __in BB_HANDLE hConn,
    __out uint32_t * uChangCount
    );

/*! ��鵱ǰ���ӵ��豸�Ƿ�֧��ָ���Ĺ���

    \param hConn    ���Ӿ��
    \param devCap   Ҫ���Ĺ���
    \return         ����豸֧�ָù��ܷ��� BR_SUCC����֧��ʱ���� BR_FIRM_NOT_SUPPORT��
                    �������󷵻ش������
*/
BB_RESULT
BBAPI 
BambookDeviceSupports (
    __in BB_HANDLE hConn,
    __in BambookDeviceCap devCap
    );
//! @}

//==============================================================================
//! \addtogroup BookInfoAPI �鼮��Ϣ��� API
//==============================================================================

//! @{
/*! ��ȡ Bambook ��һ����������Ϣ

    ���øú����󽫴�ͷ��ʼ���豸������������Ϣ���ɹ�������ٴε��� BambookGetNextPrivBookInfo
    ����ʣ�µ���������Ϣ��\n
    �ú���������ִ�У�ֱ�������ɹ���ʧ��

    \param hConn    ���Ӿ��
    \param pInfo    ��Ϣָ�룬���ڷ�����������Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(BambookBookInfo)
    \return         �ɹ����� BR_SUCC������Ҳ��������鷵�� BR_EOF���������󷵻ش������
*/
BB_RESULT
BBAPI 
BambookGetFirstPrivBookInfo (
    __in BB_HANDLE hConn, 
    __out BambookBookInfo * pInfo
    );

/*! ��ȡ Bambook ��һ����������Ϣ

    �ڵ��� BambookGetFirstPrivBookInfo �ɹ����ٵ��ñ����������Һ�̵���������Ϣ��\n
    �ú���������ִ�У�ֱ�������ɹ���ʧ��

    \param hConn    ���Ӿ��
    \param pInfo    ��Ϣָ�룬���ڷ�����������Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(BambookBookInfo)
    \return         �ɹ����� BR_SUCC������Ҳ��������鷵�� BR_EOF���������󷵻ش������
*/
BB_RESULT
BBAPI 
BambookGetNextPrivBookInfo (
    __in BB_HANDLE hConn, 
    __out BambookBookInfo * pInfo
    );

/*! ��ȡ Bambook ��һ���鼮��Ϣ

    ���øú����󽫴�ͷ��ʼ���豸�����鼮��Ϣ���ɹ�������ٴε��� BambookFindNextBook
    ����ʣ�µ��鼮��Ϣ�����ҽ�����Ӧ���� BambookFindBookClose �رվ����\n
    �ú���������ִ�У�ֱ�������ɹ���ʧ��

    \param hConn        ���Ӿ��
    \param pCondition   ��ѯ������Ŀǰ�ݲ�֧�֣����봫���ָ��
    \param pInfo        ��Ϣָ�룬���ڷ����鼮��Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(BambookBookInfo)
    \param hFind        ���ָ�룬������ҳɹ����ز��Ҿ��
    \return             �ɹ����� BR_SUCC������Ҳ����鼮���� BR_EOF���������󷵻ش������
*/
BB_RESULT
BBAPI 
BambookFindFirstBook (
    __in BB_HANDLE hConn, 
    __in_opt intptr_t pCondition,
    __out BambookBookInfo * pInfo,
    __out BB_HANDLE * hFind
    );

/*! ��ȡ Bambook ��һ���鼮��Ϣ

    �ڵ��� BambookFindFirstBook �ɹ����ٵ��ñ����������Һ�̵��鼮��Ϣ��\n
    �ú���������ִ�У�ֱ�������ɹ���ʧ��

    \param hFind    ���Ҿ��
    \param pInfo    ��Ϣָ�룬���ڷ����鼮��Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(BambookBookInfo)
    \return         �ɹ����� BR_SUCC������Ҳ����鼮���� BR_EOF���������󷵻ش������
*/
BB_RESULT
BBAPI 
BambookFindNextBook (
    __in BB_HANDLE hFind, 
    __out BambookBookInfo * pInfo
    );

/*! �ر� Bambook �鼮���Ҿ��

    �ڵ��� BambookFindFirstBook ��õ��ľ�����ڲ�����ɺ�Ӧ���øú����ͷš�\n
    �ú���������ִ�У�ֱ�������ɹ���ʧ��

    \param hFind    ���Ҿ��
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookFindBookClose (
    __in BB_HANDLE hFind
    );

/*! �����鼮 Id ���Ҷ�Ӧ���鼮��Ϣ

    �ú������Զ��ж��豸�̼��汾�����̼�֧�ֵ�ͨѶЭ�� protocalVersion < 20 
    ʱ����ʹ�ñ����ķ�ʽ�����ҡ�\n
    �ú���������ִ�У�ֱ�������ɹ���ʧ��

    \param hConn        ���Ӿ��
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid
    \param pInfo        ��Ϣָ�룬���ڷ����鼮��Ϣ���ò������Դ� NULL����ʱ���Ը��ݷ���
                        ֵ���ж��ļ��Ƿ���ڡ�\n���������Ϊ NULL�������ǰӦ���� 
                        pInfo->cbSize = SizeOf(BambookBookInfo)
    \return             �ɹ����� BR_SUCC���鼮�����ڷ��� BR_INVALID_FILE��ʧ�ܷ��� BR_FAIL ���
                        ��ԭ�����
*/
BB_RESULT
BBAPI 
BambookGetBookInfoById (
    __in BB_HANDLE hConn, 
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __out_opt BambookBookInfo * pInfo
    );

/*! ȡ��һ�� Bambook �鼮���½���

    �ú���������ִ�У�ֱ�������ɹ���ʧ��

    \param hConn        ���Ӿ��
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid
    \param uCount       �����½���
    \return             �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookGetBookChapterCount (
    __in BB_HANDLE hConn,
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __out uint32_t * uCount
    );

/*! ȡ��һ�� Bambook �鼮���½���Ϣ

    �ú���������ִ�У�ֱ�������ɹ���ʧ��

    \param hConn        ���Ӿ��
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid
    \param uIndex       Ҫȡ����Ϣ���½�������
    \param pInfo        ��Ϣָ�룬���ڷ����½���Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(BambookChapterInfo)
    \return             �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
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
//! \addtogroup BookmarkAPI �鼮�Ķ���ǩ��� API
//==============================================================================

//! @{
/*! ȡ��һ�� Bambook �鼮���Ķ���ǩ��Ϣ

    �ú���������ִ�У�ֱ�������ɹ���ʧ��\n
    �ú���Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��21

    \param hConn        ���Ӿ��
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid
    \param pInfo        ��Ϣָ�룬���ڷ����鼮�Ķ���ǩ��Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(BambookBookmarkInfo)
    \return             �ɹ����� BR_SUCC������豸�̼���֧�ָù��ܷ��� BR_FIRM_NOT_SUPPORT������
                        ���󷵻ش���ԭ�����
*/
BB_RESULT
BBAPI 
BambookGetBookmark (
    __in BB_HANDLE hConn,
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __out BambookBookmarkInfo * pInfo
    );

/*! ����һ�� Bambook �鼮���Ķ���ǩ��Ϣ

    pInfo ��������Ϊ����Ĳ�������������ǩ��Ϣ�������ڷ���������ɺ��µ���ǩ
    ��Ϣ�������������ý��������֤��\n
    �ú���������ִ�У�ֱ�������ɹ���ʧ�ܡ�\n
    �ú���Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��21

    \param hConn        ���Ӿ��
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid
    \param pInfo        ��Ϣָ�룬�������úͷ����鼮�Ķ���ǩ��Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(BambookBookmarkInfo)
    \return             �ɹ����� BR_SUCC������豸�̼���֧�ָù��ܷ��� BR_FIRM_NOT_SUPPORT������
                        ���󷵻ش���ԭ�����
*/
BB_RESULT
BBAPI 
BambookSetBookmark (
    __in BB_HANDLE hConn,
    __in const char * lpszAppId,
    __in const char * lpszBookId,
    __inout BambookBookmarkInfo * pInfo
    );

/*! ȡ�����һ���Ķ����鼮��

    �ú���������ִ�У�ֱ�������ɹ���ʧ�ܡ�\n
    �ú���Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��21

    \param hConn        ���Ӿ��
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId������ʱ���뱣֤����ĳ��� >= 20
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid������ʱ���뱣֤����ĳ��� >= 20
    \return             �ɹ����� BR_SUCC������豸�̼���֧�ָù��ܷ��� BR_FIRM_NOT_SUPPORT�����
                        ��������Ķ��鼮�����ڷ��� BR_INVALID_FILE���������󷵻ش���ԭ�����
*/
BB_RESULT
BBAPI 
BambookGetLastReadBook (
    __in BB_HANDLE hConn,
    __out_ecount(20) char * lpszAppId,
    __out_ecount(20) char * lpszBookId
    );

/*! ȡ�õ�ǰ���򿪵��鼮��

    �ú���������ִ�У�ֱ�������ɹ���ʧ��\n
    �ú���Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��21

    \param hConn        ���Ӿ��
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId������ʱ���뱣֤����ĳ��� >= 20
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid������ʱ���뱣֤����ĳ��� >= 20
    \return             �ɹ����� BR_SUCC������豸�̼���֧�ָù��ܷ��� BR_FIRM_NOT_SUPPORT�����
                        �豸�տ�����û�д��鼮���� BR_INVALID_FILE���������󷵻ش���ԭ�����
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
//! \addtogroup BookTransAPI �豸���ݴ��� API
//==============================================================================

//! @{
/*! �� Bambook ���������飬����Bambook�Ժ���鼮IDΪ������ɵ��ִ�

    ���øú������������ء�\n
    ������óɹ���������̻���ûص�����֪ͨ״̬�ͽ��ȡ�\n
    �����ʹ�ûص������Դ��� NULL�����ַ�ʽ�¿�ʹ�� BambookGetSendPrivBookStatus
    ����ѯ��ǰ�Ľ��Ⱥ���������

    \param hConn            ���Ӿ��
    \param pszSnbFile       ������ȫ·���ļ���
    \param pCallbackFunc    ��������лص��������ص��������ڵ������߳���ִ�У���Ϊ�ա�
    \param userData         �ڻص��д���
    \return                 �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookAddPrivBook (
    __in BB_HANDLE hConn,
    __in const char * pszSnbFile,
    __callback TransCallback pCallbackFunc,
    __in_opt intptr_t userData
    );

/*! �� Bambook ���������飬�������Զ����ɵ� BookId ����

    ���øú������������ء�������óɹ���������̻���ûص�����֪ͨ״̬�ͽ��ȡ�
    �����ʹ�ûص������Դ��� NULL�����ַ�ʽ�¿�ʹ�� BambookGetSendPrivBookStatus
    ����ѯ��ǰ�Ľ��Ⱥ���������

    \param hConn            ���Ӿ��
    \param pszSnbFile       ������ȫ·���ļ���
    \param pCallbackFunc    ��������лص��������ص��������ڵ������߳���ִ�У���Ϊ�ա�
    \param userData         �ڻص��д���
    \param lpszBookId       �����Զ����ɵ� BookId�����ջ���������Ӧ >= 20����Ϊ NULL
    \return                 �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
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

/*! �� Bambook ���������飬��ָ���鼮ID���鼮ID���ȴ���0���ó���char[20]��
    IDΪӢ�ĺ���ĸ�������λΪ".snb"�����������������滻Bambook���ض��鼮��

    ���øú������������ء�������óɹ���������̻���ûص�����֪ͨ״̬�ͽ��ȡ�
    �����ʹ�ûص������Դ��� NULL�����ַ�ʽ�¿�ʹ�� BambookGetSendPrivBookStatus
    ����ѯ��ǰ�Ľ��Ⱥ���������
    ���̼�֧�ֵ�ͨѶЭ�� protocalVersion >= 20 ʱ���滻����鼮�Ķ�λ����ǩ��������

    \param hConn            ���Ӿ��
    \param pszSnbFile       ������ȫ·���ļ���
    \param lpszBookId       �鼮ID
    \param pCallbackFunc    ��������лص��������ص��������ڵ������߳���ִ�У���Ϊ�ա�
    \param userData         �ڻص��д���
    \return                 �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
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

/*! ��ѯ��ǰ�� Bambook ��������������Ľ��Ⱥ�״̬

    ��ʹ�÷ǻص���ʽ�� Bambook ����������ʱ����ͨ���ú�����ѯ����״̬��\n
    �����ǰû�д��ڴ���״̬���ߴ�������ɣ�status ������ TRANS_STATUS_DONE\n
    �������ʧ�ܣ�status ���� TRANS_STATUS_ERR����������з��� TRANS_STATUS_TRANS

    \param hConn    ���Ӿ��
    \param status   ָ�룬���ش���״̬
    \param progress ָ�룬���ش�����ȣ�0..100
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookGetSendPrivBookStatus (
    __in BB_HANDLE hConn,
    __out uint32_t * status,
    __out uint32_t * progress
    );

/*! ɾ�� Bambook ������

    �ú���������ִ�У�ֱ�������ɹ���ʧ��\n
    ���̼�֧�ֵ�ͨѶЭ�� protocalVersion  >= 20 ʱ��ɾ�������ڵ��ļ��᷵�� 
    BR_INVALID_FILE

    \param hConn        ���Ӿ��
    \param lpszBookId   ��Ӧ��������Ϣ�е� bookGuid
    \return             �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookDeletePrivBook (
    __in BB_HANDLE hConn, 
    __in const char * lpszBookId
    );

/*! �� Bambook �����������ļ�

    ���øú������������ء�������óɹ���������̻���ûص�����֪ͨ״̬�ͽ��ȡ�\n
    �����ʹ�ûص������Դ��� NULL�����ַ�ʽ�¿�ʹ�� BambookGetFetchPrivBookStatus
    ����ѯ��ǰ�Ľ��Ⱥ���������

    \param hConn            ���Ӿ��
    \param lpszBookId       ��Ӧ��������Ϣ�е� bookGuid
    \param lpszFilePath     �����������ļ����Ŀ¼
    \param pCallbackFunc    ��������лص��������ص��������ڵ������߳���ִ�У���Ϊ�ա�
    \param userData         �ڻص��д���
    \return                 �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
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

/*! ��ѯ��ǰ�� Bambook ��������������Ľ��Ⱥ�״̬

    ��ʹ�÷ǻص���ʽ���� BambookFetchPrivBook ʱ����ͨ���ú�����ѯ����״̬��\n
    �����ǰû�д��ڴ���״̬���ߴ�������ɣ�status ������ TRANS_STATUS_DONE\n
    �������ʧ�ܣ�status ���� TRANS_STATUS_ERR����������з��� TRANS_STATUS_TRANS

    \param hConn    ���Ӿ��
    \param status   ָ�룬���ش���״̬
    \param progress ָ�룬���ش�����ȣ�0..100
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookGetFetchPrivBookStatus (
    __in BB_HANDLE hConn,
    __out uint32_t * status,
    __out uint32_t * progress
    );

/*! �� Bambook �������������ͼƬ�ļ�

    �ú���������ִ�У�ֱ�������ɹ���ʧ��

    \param hConn            ���Ӿ��
    \param lpszBookId       ��Ӧ��������Ϣ�е� bookGuid
    \param lpszFilePath     �������������ͼƬ�ļ����Ŀ¼
    \param lpszCoverName    ���ط���ͼƬ�ļ���������ʱ���뱣֤����ĳ��� >= 100
    \return                 �ɹ����� BR_SUCC������鼮�����ڻ�û�з��淵�� BR_INVALID_FILE��������
                            �󷵻ش���ԭ�����
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
//! \addtogroup CLBookAPI ��Ȩ�鴦����� API
//==============================================================================

//! @{
/*! ���� Bambook ��ӻ����һ����Ȩ��

    �ú������Կ��� Bambook ����һ����Ȩ�顣����ð�Ȩ���Ѿ���������ˣ���ִ
    ���½ڸ��²���������ð�Ȩ�鲻���û�����ϣ����Զ���������ӵ��û������
    ���� Bambook ��ִ�����غ͸��²�����\n
    �ú���ֻ����֪ͨ Bambook �����鼮������ȴ�������ɣ�Ҳ���᷵�ظ��½����
    Bambook ����������еķ�ʽִ�и��²������ڶ����е����������豸�󽫶�ʧ��

    \param hConn        ���Ӿ��
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid
    \return             �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookUpdateBook (
    __in BB_HANDLE hConn, 
    __in const char * lpszAppId,
    __in const char * lpszBookId
    );

/*! ���� Bambook �������

    �ú������Կ��� Bambook �����û���ܡ��൱���û����豸��ִ�С�ȫ�����¡�
    ���ܡ�

    \param hConn    ���Ӿ��
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookUpdateBookShelf (
    __in BB_HANDLE hConn
    );

/*! ɾ�� Bambook �鼮

    �ú���������ִ�У�ֱ�������ɹ���ʧ��\n
    ���̼�֧�ֵ�ͨѶЭ�� protocalVersion >= 20 ʱ��ɾ�������ڵ��ļ��᷵��
    BR_INVALID_FILE

    \param hConn        ���Ӿ��
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid
    \return             �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
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
//! \addtogroup CataAPI ���ദ����� API
//==============================================================================

//! @{
/*! ������ܷ�����Ϣ���

    �����ɹ���ľ����ͨ�� BambookCatalogLoad ��ȡ���豸������Ϣ��
    ʹ����ɺ�Ӧͨ�� BambookCatalogFree �ر�

    \param hCatalog ������Ϣ���
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogCreate (
    __out BB_HANDLE * hCatalog
    );

/*! �ر���ܷ�����Ϣ���

    ͨ�� BambookCatalogCreate �����ľ����ʹ����ɺ�Ӧ���ñ������ͷ�

    \param hCatalog ������Ϣ���
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogFree (
    __in BB_HANDLE hCatalog
    );

/*! �� Bambook �ж�ȡ��ܷ�����Ϣ

    ִ�гɹ���ȡ�÷�����Ϣ��������ɺ��ʹ�� BambookCatalogSave ��������Ϣ
    ���浽 Bambook���ú���������ִ�У�ֱ�������ɹ���ʧ��\n
    �ú���Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��19

    \param hConn    ���Ӿ��
    \param hCatalog ������Ϣ���
    \return         �ɹ����� BR_SUCC������豸�̼���֧�ַ��෵�� BR_FIRM_NOT_SUPPORT������
                    ���󷵻ش���ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogLoad (
    __in BB_HANDLE hConn,
    __in BB_HANDLE hCatalog
    );

/*! ����ܷ�����Ϣ���浽 Bambook ��

    �ú���������ִ�У�ֱ�������ɹ���ʧ��\n
    �ú���Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��19

    \param hConn    ���Ӿ��
    \param hCatalog ������Ϣ���
    \return         �ɹ����� BR_SUCC������豸�̼���֧�ַ��෵�� BR_FIRM_NOT_SUPPORT������
                    ���󷵻ش���ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogSave (
    __in BB_HANDLE hConn,
    __in BB_HANDLE hCatalog
    );

/*! ȡ�÷�����Ϣ�а����ķ�������

    \param hCatalog ������Ϣ���
    \param uCount   ���ط�������
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogGetCount (
    __in BB_HANDLE hCatalog,
    __out uint32_t * uCount
    );

/*! ȡ�÷�����Ϣ�е�ָ����������

    \param hCatalog ������Ϣ���
    \param uIndex   Ҫȡ�õķ��������ţ��� 0 ��ʼ
    \param lpszName ���ط������ƣ�����ʱ���뱣֤����ĳ��� >= 100
    \return         �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                    ��ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogGetItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __out_ecount(100) char * lpszName
    );

/*! ɾ��������Ϣ�е�ָ������

    \param hCatalog ������Ϣ���
    \param uIndex   Ҫɾ���ķ��������ţ��� 0 ��ʼ
    \return         �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                    ��ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogDeleteItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex
    );

/*! �޸ķ�����Ϣ�е�ָ����������

    \param hCatalog ������Ϣ���
    \param uIndex   Ҫ�޸ĵķ��������ţ��� 0 ��ʼ
    \param lpszName �µķ�������
    \return         �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                    ��ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogRenameItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in const char * lpszName
    );

/*! �ڷ�����Ϣ��ָ��λ�ò����µķ���

    \param hCatalog ������Ϣ���
    \param uIndex   Ҫ����ķ�������λ�ã�0 ��ʾ��������ǰ�棬�������ֵʱ׷����β��
    \param lpszName �µķ�������
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogInsertItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in const char * lpszName
    );

/*! �ڷ�����Ϣβ�������µķ���

    \param hCatalog ������Ϣ���
    \param lpszName �µķ�������
    \return         �ɹ����� BR_SUCC���������󷵻ش���ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogAppendItem (
    __in BB_HANDLE hCatalog,
    __in const char * lpszName
    );

/*! �ƶ�������Ϣ��ָ�����ൽ�µ�λ��

    \param hCatalog     ������Ϣ���
    \param uIndex       Ҫ�ƶ��ķ��������ţ��� 0 ��ʼ
    \param uNewIndex    �µ�������λ�ã��� 0 ��ʼ
    \return             �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                        ��ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogMoveItem (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in uint32_t uNewIndex
    );

/*! ȡ�÷�����Ϣ��ָ������������鼮��

    \param hCatalog ������Ϣ���
    \param uIndex   Ҫȡ�õķ��������ţ��� 0 ��ʼ
    \param uCount   ���ظ÷����µ��鼮����
    \return         �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                    ��ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogGetBookCount (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __out uint32_t * uCount
    );

/*! ȡ�÷�����Ϣ�е�ָ��������ָ���鼮����Ϣ

    \param hCatalog     ������Ϣ���
    \param uIndex       Ҫȡ�õķ��������ţ��� 0 ��ʼ
    \param uBookIndex   Ҫȡ�õ��鼮�����ţ��� 0 ��ʼ
    \param lpszAppId    ��Ӧ�鼮��Ϣ�е� AppId������ʱ���뱣֤����ĳ��� >= 20
    \param lpszBookId   ��Ӧ�鼮��Ϣ�е� bookGuid������ʱ���뱣֤����ĳ��� >= 20
    \return             �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                        ��ԭ�����
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

/*! �ӷ�����Ϣ�е�ָ���������Ƴ�ָ�����鼮

    �ú���ֻ�ǽ��鼮��Ϣ�ӷ������Ƴ�������ɾ���豸�ϵ��鼮

    \param hCatalog     ������Ϣ���
    \param uIndex       Ҫ�����ķ��������ţ��� 0 ��ʼ
    \param uBookIndex   Ҫ�Ƴ����鼮�����ţ��� 0 ��ʼ
    \return             �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                        ��ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogRemoveBook (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in uint32_t uBookIndex
    );

/*! �ڷ�����Ϣ�е�ָ�������°�ָ����λ�ò����鼮

    \param hCatalog     ������Ϣ���
    \param uIndex       Ҫ�����ķ��������ţ��� 0 ��ʼ
    \param uBookIndex   Ҫ������鼮�����ţ�0 ��ʾ��������ǰ�棬�������ֵʱ׷����β��
    \param lpszAppId    Ҫ�����鼮�� AppId
    \param lpszBookId   Ҫ�����鼮�� BookID
    \return             �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                        ��ԭ�����
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

/*! �ڷ�����Ϣ�е�ָ��������׷���鼮

    \param hCatalog     ������Ϣ���
    \param uIndex       Ҫ�����ķ��������ţ��� 0 ��ʼ
    \param lpszAppId    Ҫ�����鼮�� AppId
    \param lpszBookId   Ҫ�����鼮�� BookID
    \return             �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                        ��ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogAppendBook (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in const char * lpszAppId,
    __in const char * lpszBookId
    );

/*! �ڷ�����Ϣ�е�ָ�������ƶ�ָ���鼮���µ�λ��

    \param hCatalog         ������Ϣ���
    \param uIndex           Ҫ�����ķ��������ţ��� 0 ��ʼ
    \param uBookIndex       Ҫ�ƶ����鼮�����ţ��� 0 ��ʼ
    \param uNewBookIndex    �µ�������λ��
    \return                 �ɹ����� BR_SUCC���������������Χ���� BR_OUT_OF_BOUNDS���������󷵻ش�
                            ��ԭ�����
*/
BB_RESULT
BBAPI 
BambookCatalogMoveBook (
    __in BB_HANDLE hCatalog,
    __in uint32_t uIndex,
    __in uint32_t uBookIndex,
    __in uint32_t uNewBookIndex
    );

/*! ��ָ���鼮��ӵ�ָ��������

    ������಻���ڣ����Զ�׷��һ���µķ��ࡣ
    ���ָ�������¸��鼮�Ѿ����ڣ���ֱ�ӷ��سɹ���

    \param hCatalog         ������Ϣ���
    \param lpszAppId        Ҫ����鼮�� AppId
    \param lpszBookId       Ҫ����鼮�� BookID
    \param lpszCataName     Ҫ��ӵ��ķ�����
    \return                 �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
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
//! \addtogroup MiscAPI �豸�������� API
//==============================================================================

//! @{
/*! �� Bambook ���Ͱ�������

    �ú���Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��12

    \param hConn    ���Ӿ��
    \param key      ����ֵ
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookKeyPress (
    __in BB_HANDLE hConn, 
    __in BambookKey key
    );

/*! ���� Bambook �� TTS �ʶ�ָ�����ı�

    �ú���Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��12

    \param hConn    ���Ӿ��
    \param lpszText Ҫ�ʶ����ı����ݣ����Ȳ��ܳ���40������
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookTTSPlay (
    __in BB_HANDLE hConn, 
    __in const char * lpszText
    );

/*! ���� Bambook ֹͣ�� BambookTTSPlay ������ TTS �ʶ�

    �ú���Ҫ��̼�֧�ֵ�ͨѶЭ�� protocalVersion ��Ͱ汾Ϊ��12

    \param hConn    ���Ӿ��
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookTTSStop (
    __in BB_HANDLE hConn
    );
//! @}

//==============================================================================
//! \addtogroup SNBWrapAPI SNB �ļ������װ API
//==============================================================================

//! @{
/*! ��һ������ SNB Ŀ¼�ṹ��Ŀ¼��� SNB ��

    \param snbName  ���ɵ� snb �ļ���
    \param rootDir  Ҫ����ĸ�Ŀ¼
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL��BR_IO_ERROR �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookPackSnbFromDir (
    __in const char * snbName, 
    __in const char * rootDir
    );

/*! �������·���ļ����� SNB ���н��һ���ļ�

    \param snbName      Ҫ������ snb �ļ���
    \param relativePath Ҫ��ѹ���ļ��ڰ��е����·�����ļ��������磺"snbf/book.snbf"
    \param outputName   ��ѹ�������ļ������ȫ·���ļ���
    \return             �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL��BR_IO_ERROR��BR_FILE_NOT_INSIDE ��
                        ����ԭ�����
*/
BB_RESULT
BBAPI 
BambookUnpackFileFromSnb (
    __in const char * snbName, 
    __in const char * relativePath, 
    __in const char * outputName
    );

/*! ���һ���ļ��Ƿ�Ϸ��� SNB �ļ�

    \param snbName  Ҫ������ snb �ļ���
    \return         ����ļ��Ϸ� BR_SUCC�����򷵻� BR_INVALID_FILE �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookVerifySnbFile (
    __in const char * snbName
    );
//! @}

//==============================================================================
//! \addtogroup SNBAPI SNB �ļ����� API
//==============================================================================

//! @{
/*! ��һ�� SNB �ļ������� SNB ������

    ������ɺ�Ӧ���� BambookSnbClose �رն����ͷ���Դ��
    ͬһ���ļ� SNB �ļ�����֧��ͬʱ����δ򿪣����߳��²���ͬһ�� SNB ���
    ���ܻ���δ֪����

    \param snbName  Ҫ�򿪵� snb �ļ���
    \param hSnb     ���ָ�룬ִ�гɹ����� SNB ������
    \return         ������ļ��ɹ����� BR_SUCC�����򷵻� BR_INVALID_FILE �����ԭ�����
*/
BB_RESULT
BBAPI 
BambookSnbOpen (
    __in const char * snbName,
    __out BB_HANDLE * hSnb
    );

/*! �ر�һ�� SNB ������

    \param hSnb     Ҫ�رյĶ�����
    \return         �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL
*/
BB_RESULT
BBAPI 
BambookSnbClose (
    __in BB_HANDLE hSnb
    );

/*! ��ȡ SNB �ļ���ָ���ļ�����Ϣ

    \param hSnb         Ҫ�����Ķ�����
    \param relativePath Ҫ��ȡ���ļ��ڰ��е����·�����ļ��������磺"snbf/book.snbf"
    \param pInfo        ��Ϣָ�룬���ڷ����ļ���Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(SnbFileInfo)
    \return             �ɹ����� BR_SUCC������Ҳ����ļ����� BR_FILE_NOT_INSIDE���������󷵻ش������
*/
BB_RESULT
BBAPI 
BambookSnbGetFileInfo (
    __in BB_HANDLE hSnb,
    __in const char * relativePath,
    __out SnbFileInfo * pInfo
    );

/*! ��ȡ SNB �ļ��е�һ���ļ���Ϣ

    \param hSnb     Ҫ�����Ķ�����
    \param pInfo    ��Ϣָ�룬���ڷ����ļ���Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(SnbFileInfo)
    \return         �ɹ����� BR_SUCC������Ҳ����ļ����� BR_EOF���������󷵻ش������
*/
BB_RESULT
BBAPI 
BambookSnbGetFirstFileInfo (
    __in BB_HANDLE hSnb,
    __out SnbFileInfo * pInfo
    );

/*! ��ȡ SNB �ļ�����һ���ļ���Ϣ

    \param hSnb     Ҫ�����Ķ�����
    \param pInfo    ��Ϣָ�룬���ڷ����ļ���Ϣ������ǰӦ���� pInfo->cbSize = SizeOf(SnbFileInfo)
    \return         �ɹ����� BR_SUCC������Ҳ����ļ����� BR_EOF���������󷵻ش������
*/
BB_RESULT
BBAPI 
BambookSnbGetNextFileInfo (
    __in BB_HANDLE hSnb,
    __out SnbFileInfo * pInfo
    );

/*! �� SNB �ж�ȡһ���ļ����ݵ�ָ���ڴ滺����

    \param hSnb         Ҫ�����Ķ�����
    \param relativePath Ҫ��ѹ���ļ��ڰ��е����·�����ļ��������磺"snbf/book.snbf"
    \param uOffset      Ҫ��ȡ����ʼƫ����
    \param pBuffer      ���ڴ�Ž�ѹ���ݵĻ�����ָ��
    \param uBufferSize  ��������С
    \param uReadBytes   ����ʵ�ʶ�ȡ���ֽ��������ֽ���Ϊ��������С��ɶ�ȡ�ֽ�����Сֵ
    \return             �ɹ����� BR_SUCC������Ҳ����ļ����� BR_FILE_NOT_INSIDE��uOffset �����ļ�
                        ��Χ���� BR_EOF���������󷵻ش������
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

/*! �� SNB �ж�ȡһ���ļ����ݲ�����Ϊ�ļ�

    \param hSnb         Ҫ�����Ķ�����
    \param relativePath Ҫ��ѹ���ļ��ڰ��е����·�����ļ��������磺"snbf/book.snbf"
    \param outputName   ��ѹ�������ļ������ȫ·���ļ���
    \return             �ɹ����� BR_SUCC��ʧ�ܷ��� BR_FAIL��BR_FILE_NOT_INSIDE �����ԭ�����
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
