#ifndef __THREAD_H__
#define __THREAD_H__


#ifdef   WIN32
typedef  HANDLE						thread_t;			//�߳�ID
typedef  LPTHREAD_START_ROUTINE		_start_routine;		//�̺߳���
typedef  CRITICAL_SECTION			lock_t;				//��
typedef	 HANDLE						sem_t;				//�ź���
typedef	 DWORD						PUB_THREAD_RESULT;		//�̺߳������ؽ��
#define	 THREAD_CALL			    WINAPI					//�������÷�ʽ
#define  CREATE_THREAD_FAIL		    NULL					//�����߳�ʧ��
#define  snprintf                   _snprintf
#else			
typedef  pthread_t					thread_t;			//�߳�ID
typedef  void *(*start_routine)(void*);
typedef  start_routine				_start_routine;		//�̺߳���
typedef  pthread_mutex_t			lock_t;				//��
typedef	 sem_t						sem_t;						//�ź���
typedef	 void*						THREAD_RESULT;		//�̺߳������ؽ��
#define	 THREAD_CALL									//�������÷�ʽ
#define  CREATE_THREAD_FAIL		0						//�����߳�ʧ��
#endif

thread_t createThread(_start_routine start_routine, void* pParam, bool *pRun);

void exitThread(thread_t *pThreadID, bool *pRun, bool bCance);

#endif /*__THREAD_H__*/

