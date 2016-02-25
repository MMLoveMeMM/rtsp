#ifndef __TCP_LINK_RECEIVER_H__
#define __TCP_LINK_RECEIVER_H__

class TCPTransfer;
class TCPLinkReceiver
{
public:
	TCPLinkReceiver();
	virtual ~TCPLinkReceiver();
public:
	//���ô�����
	void setTCPTransfer(TCPTransfer* p_pobjTCPTransfer);
	TCPTransfer* getTCPTransfer();
	//����˽������
	void setPrivateData(void* p_pPrivateData);
	void* getPrivateData()const;

	//��������Ծʱ��
	void setLastActiveTime(const unsigned long p_dwLastActiveTime);
	unsigned long getLastActiveTime()const;
	
	//���������¼�
	virtual int handleEvent(const int p_nNetworkEventType);
protected:
	TCPTransfer*           m_pobjTCPTransfer;
	void*                  m_pPrivateData;
	unsigned long          m_dwLastActiveTime;
};

#endif /*__TCP_LINK_RECEIVER_H__*/

