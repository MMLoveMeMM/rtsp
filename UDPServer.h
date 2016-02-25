#ifndef __UDP_SERVER_H__
#define __UDP_SERVER_H__

#include "OS_Define.h"
#include "InetAddr.h"
#include "Thread.h"

class UDPTransfer;
class UDPServer
{
public:
	UDPServer();
	virtual ~UDPServer();
public:
	//���ü����˿�;
	void setBindAddr(const InetAddr& p_objInetAddr);
	const InetAddr& getBindAddr()const;

	int start();
	void stop();
	
#ifdef WIN32
	static PUB_THREAD_RESULT _stdcall UDPServerThread(void *pParam);
#else
	static PUB_THREAD_RESULT  UDPServerThread(void *pParam);
#endif

protected:
	virtual int handleEvent(const char* p_pData, const int p_nDataLen, const InetAddr& p_objInetAddr);

private:
	int run();
protected:
	InetAddr                    m_objInetAddr;         //������ַ
	UDPTransfer*                m_pobjListenTransfer;  //����������
	thread_t                    m_nServerThreadId;     //�����߳�
	bool                        m_bThreadRunFlag;      //���������߳����б��
};

#endif /*__UDP_SERVER_H__*/

