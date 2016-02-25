#ifndef __TCP_SERVER_H__
#define __TCP_SERVER_H__

#include <arpa/inet.h>
#include <sys/epoll.h>
#include <list>
#include "Thread.h"
#include "InetAddr.h"

#define EPOLL_SIZE_MAX  32

class TCPTransfer;
class TCPLinkReceiver;

class TCPServer
{
public:
	TCPServer();
	virtual ~TCPServer();
private:
	TCPServer(const TCPServer& p_objOther);
	TCPServer& operator=(const TCPServer& p_objOther);
public:
	//���ü����˿�;
	void setBindAddr(const InetAddr& p_objInetAddr);
	const InetAddr& getBindAddr()const;
	//�������������
	void setMaxConnectionCount(const int p_nMaxConnectionCount);
	int getMaxConnectionCount()const;
	//����
	int start();
	//ֹͣ
	void stop();
#ifdef WIN32
	static THREAD_RESULT _stdcall TCPServerThread(void *pParam);
#else
	static THREAD_RESULT  TCPServerThread(void *pParam);
#endif

protected:
	virtual int handleEvent(TCPLinkReceiver* p_pobjTCPLinkReceiver, struct epoll_event *ev);
	virtual TCPLinkReceiver* creatTCPLinkReceiver() = 0;
	int addPassiveTCPTransfer(TCPTransfer* p_pobjTCPTransfer);
private:		
	int run();

	int clearTimeOutConnection();

	int epoll();

	int handleAccept();

	int closeConnection(TCPLinkReceiver* p_pobjTCPLinkReceiver);
private:
	InetAddr                    m_objInetAddr;              //����˿�
	int                         m_nMaxConnectionCount;      //���������
	TCPTransfer*                m_objListenTCPTransfer;     //����������
	thread_t                    m_nServerThreadId;          //�����߳�
	bool                        m_bThreadRunFlag;           //���������߳����б��
	int                         m_nEpollFd;                 //epoll�ļ������� 
	struct 	epoll_event         m_events[EPOLL_SIZE_MAX];   //����¼���;	
	int                         m_fdCount;                  //VAP������
	std::list<TCPLinkReceiver*> m_objTCPLinkReceiverList;   //�ͻ����б�
	lock_t                      m_objLock;                  //�Ự�б�����
};

#endif /*__TCP_SERVER_H__*/

