/*!
================================================================================
@Project    : ESP8266 Configuration  
@Module Func: esp8266 configuration
--------------------------------------------------------------------------------
@File Name	: sta_tcpclient_test.c                                                                                         
@Copyright by su.ch                                                    
--------------------------------------------------------------------------------
Change Records                                                              
--------------------------------------------------------------------------------
	[No]       [Name]       [Date]      [Description]                         
   1         su.ch        2021/12/29   first                                  
================================================================================
*/

#include "sta_tcpclent_test.h"
#include "SysTick.h"
#include "usart.h"
#include "esp8266_drive.h"

//!-----------------------------------------------------------------------------
//!---------------------------> Local Variables   <-----------------------------
//!-----------------------------------------------------------------------------
volatile u8 TcpClosedFlag = 0;


//!=============================================================================
//!            Function Define Section(as bellows)                            
//!=============================================================================

/*!
================================================================================
@Brief
	Set STA mode.                                       
@Param
	void                                                                     
@Return	
	None                                   
-------------------------------------------------------------------------------
*/
void ESP8266_STA_TCPClient_Test(void)
{
//	u8 uRes;
	
//	char cStr[100]={0};
	
	printf ( "\r\n��������ESP8266�����ĵȴ�...\r\n" );

	//ESP8266Ӳ��ʹ�ܣ�EN����
	ESP8266_CH_PD_Pin_SetH;

	//��������ִ��AT����ָ��
	ESP8266_AT_Test();
	
	//����STAģʽ
	ESP8266_Net_Mode_Choose(STA);
	
	//ESP8266�����ȵ�
	while(!ESP8266_JoinAP(User_ESP8266_SSID, User_ESP8266_PWD));
	
	//������-Disable��ֻ�е����Ӳ�֧��͸��ģʽ
	ESP8266_Enable_MultipleId( DISABLE );
	
	//TCP/UDP����
	while(!ESP8266_Link_Server(enumTCP, User_ESP8266_TCPServer_IP, User_ESP8266_TCPServer_PORT, Single_ID_0));
	
	//����͸��ģʽ
	while(!ESP8266_UnvarnishSend());
	
	printf ( "\r\n����ESP8266 OK��\r\n" );
	
//	while ( 1 )
//	{		
//		//tcp͸��ģʽ�����ַ���
//		sprintf (cStr,"www.prechin.cn\r\n" );
//		ESP8266_SendString ( ENABLE, cStr, 0, Single_ID_0 );
//		delay_ms(1000);
//		
//		//����Ƿ�ʧȥ����
//		if(TcpClosedFlag)
//		{
//			//�˳�͸��ģʽ
//			ESP8266_ExitUnvarnishSend();
//			
//			do
//			{
//				//��ȡ����״̬
//				uRes = ESP8266_Get_LinkStatus();
//			} 	
//			while(!uRes);
//			
//			//ȷ��ʧȥ���Ӻ�����
//			if(uRes == 4)
//			{
//				printf ( "\r\n���Եȣ����������ȵ�ͷ�����...\r\n" );
//				
//				while (!ESP8266_JoinAP(User_ESP8266_SSID, User_ESP8266_PWD ) );
//				
//				while (!ESP8266_Link_Server(enumTCP, User_ESP8266_TCPServer_IP, User_ESP8266_TCPServer_PORT, Single_ID_0 ) );
//				
//				printf ( "\r\n�����ȵ�ͷ������ɹ�\r\n" );
//			} 
//			while(!ESP8266_UnvarnishSend());					
//		}
//	}
		
}

// ESP8266һֱ��������
void ESP8266_OnLoop(char *cStr)
{
	u8 uRes;
//	char cStr[100]={0};
		
	//while ( 1 )
	{		
		//tcp͸��ģʽ�����ַ���
		//sprintf (cStr,"www.prechin.cn\r\n" );
		ESP8266_SendString ( ENABLE, cStr, 0, Single_ID_0 );
		//delay_ms(1000);
		
		//����Ƿ�ʧȥ����
		if(TcpClosedFlag)
		{
			//�˳�͸��ģʽ
			ESP8266_ExitUnvarnishSend();
			
			do
			{
				//��ȡ����״̬
				uRes = ESP8266_Get_LinkStatus();
			} 	
			while(!uRes);
			
			//ȷ��ʧȥ���Ӻ�����
			if(uRes == 4)
			{
				printf ( "\r\n���Եȣ����������ȵ�ͷ�����...\r\n" );
				
				while (!ESP8266_JoinAP(User_ESP8266_SSID, User_ESP8266_PWD ) );
				
				while (!ESP8266_Link_Server(enumTCP, User_ESP8266_TCPServer_IP, User_ESP8266_TCPServer_PORT, Single_ID_0 ) );
				
				printf ( "\r\n�����ȵ�ͷ������ɹ�\r\n" );
			} 
			while(!ESP8266_UnvarnishSend());					
		}
	}
}


