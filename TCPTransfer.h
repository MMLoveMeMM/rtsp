#ifndef __TCP_TRANSFER_H__
#define __TCP_TRANSFER_H__

#include "ITransfer.h"

class TCPTransfer;

class TCPTransfer : public ITransfer
{
public:
	TCPTransfer();
	~TCPTransfer();
public:
	//����SOCKET
	int open();
	//�󶨵�ָ����ַ
	int bind(const InetAddr& p_objInetAddr);
	//����
	int listen(const int p_nBakLog);
	//����
	int accept(ITransfer*& p_pobjTransfer);
	//����
	int connect(const InetAddr& p_objInetAddr, const int p_nTimeOut);
	//�ر�
	void close();
	//��ʱʱ�䷢��,��ʱʱ���Ϊ�ȴ���дʱ��
	int send(const char* p_pData, const int p_nDataLen, const int p_nTimeOut, const InetAddr& p_objToAddr);
	//����������
	int send(const char* p_pData, const int p_nDataLen, const InetAddr& p_objToAddr);
	//����������
	int nonBlockSend(const char* p_pData, const int p_nDataLen);
	//��ʱʱ�����
	int recv(char* p_pBuffer, const int p_nBuffSize, const int p_nTimeOut);
	//����ʽ���գ�ֱ���յ�����
	int recv(char* p_pBuffer, const int p_nBuffSize);
	//��ʵ��
	int sendTo(const char* p_pData, const int p_nDataLen, const InetAddr& p_objToInetAddr, const int p_nTimeOut = 0);
	//��ʵ��
	int recvFrom(char* p_pBuffer, const int p_nBuffSize, InetAddr& p_objIFromnetAddr, const int p_nTimeOut = 0);	
};

#endif /*__TCP_TRANSFER_H__*/

