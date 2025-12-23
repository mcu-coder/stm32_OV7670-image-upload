/**
  ******************************************************************************
  * 文件: ltk_key.h
  * 作者: LeiTek (leitek.taobao.com)
  * 版本: V1.0.0
  * 描述: 按键外部中断中间件头文件
  ******************************************************************************
  *
  *                  版权所有 (C): LeiTek (leitek.taobao.com)
  *                                www.leitek.com
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
/* 防止递归包含该头文件 ------------------------------------------------------*/
#ifndef __KEY_H
#define __KEY_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/

	 
#define KEY1  GPIO_ReadInputDataBit(KEY1_PORT,KEY1_PIN)//读取按键1
#define KEY2  GPIO_ReadInputDataBit(KEY1_PORT,KEY2_PIN)//读取按键2 	 
#define KEY1_PRES	1	//KEY1按下
#define KEY2_PRES	2	//KEY2按下
	 
void Key_init(void);	//初始化 KEY
u8 KEY_Scan(u8);  	//按键扫描函数	
	 
#ifdef __cplusplus
}
#endif


#endif /* __LTK_KEY_H */

/****************************** leitek.taobao.com *****************************/
