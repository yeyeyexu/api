/******************************************************************************/
/* @ All Rights Reserved Copyright (C) XX                                     */
/* 编码 = UTF-8                                                               */
/* 系统 = 运维管理软件                                                        */
/* 模块 = 存储模块状态获取二次开发库                                          */
/* 功能 =                                                                     */
/* 注意 =                                                                     */
/* 更新 = $Id：$                                                              */
/******************************************************************************/

#ifndef _EZSMS_H_
#define _EZSMS_H_

#include <stdint.h>
#include <vector>

#define EZSMS_SLOT_MAX_NAME_LEN  31
#define EZSMS_MAX_DISK_NUM       16
#define EZSMS_MAX_KEY_LEN        63
#define EZSMS_MAX_VALUE_LEN      63

#define EZSMS_VERSION            "ezsms:     V0.0.01 20230927 10:00"

/*盘的信息*/
typedef struct
{
    char a_slot_name[EZSMS_SLOT_MAX_NAME_LEN+1];     //槽位PCIe号
    bool b_alive;   	                       //盘是否在位
    uint64_t u64_disk_size;  		           //盘总空间，B
}ezsms_disk_t;

/*盘阵的信息*/
typedef struct
{
    uint8_t u8_disk_count;         //盘的总个数
    ezsms_disk_t st_disk[EZSMS_MAX_DISK_NUM];
}ezsms_disk_array_t;

/*工作参数*/
typedef struct
{
    double d_temp;        // 温度
    double d_voltage;     // XX电压
    double d_curr;        // XX电流
}ezsms_work_para_t;

/*key的类型，value对应的值为在位，不在位，或其它对应的描述信息
FC-1
FC-2
FC-3
FC-4
FC-5
FC-6
FC-7
FC-8
SRIO-1
SRIO-2
SRIO-3
SRIO-4
SRIO-5
SRIO-6
SRIO-7
SRIO-8
FPGA
RAID-1/2/3…
 */
typedef struct
{
    char a_key[EZSMS_MAX_KEY_LEN + 1];       // 类型名称
    char a_value[EZSMS_MAX_VALUE_LEN + 1];   // 类型对应的值
    bool b_warn;                               // 是否有告警
}ezsms_kv_t;

/******************************************************************************/
/* 名称  = ezsms_get_version                                                   */
/* 功能  = 获得二次开发库版本                                                  */
/* 参数  =                                                                     */
/* 返回  = 0        : OK                                                       */
/*         非0      ：ERR                                                      */
/* 注意  =                                                                     */
/* 日期  =                                                                     */
/******************************************************************************/
const char* ezsms_get_version();

/********************************************************************************/
/* 名称  = ezsms_get_module_alive											     */
/* 功能  = 获取模块是否在位                     								 */
/* 参数  = u32_module_id   : uint32_t   : I  :  模块ID                           */
/* 参数  = p_b_alive       : bool *     : O : 模块是否在位                       */
/* 返回  =  0        : OK												         */
/*          非0      ：ERR												         */
/* 注意  =                               										 */
/* 日期  = 2022/02/14 by zhoujiqiang-1993@ST.CETC52                              */
/********************************************************************************/
int ezsms_get_module_alive(uint32_t u32_module_id, bool *p_b_alive);

/******************************************************************************/
/* 名称     = ezcs_get_disk_status                                             */
/* 功能     = 获取盘组状态                                                     */
/* 参数     = p_st_info  : ezsms_disk_array_t* : 盘组状态                      */
/* 返回     = 0 : OK                                                           */
/*          < 0 : ERROR                                                        */
/* 注意     =                                                                 */
/* 日期 	   =                                                              */
/******************************************************************************/
int ezsms_get_disk_status(ezsms_disk_array_t *p_st_info);

/*****************************************************************************/
/* 名称  = ezcs_get_work_para                                                */
/* 功能  = 获取模块工作参数信息                                              */
/* 参数  = u32_module_id       I : 模块ID                                    */
/*         p_st_para           O : 模块工作参数信息                          */
/* 返回  = 0        : OK                                                     */
/*         非0      :ERR                                                     */
/* 注意     =                                                                 */
/* 日期 	   =                                                              */
/*****************************************************************************/
int ezsms_get_work_para(int u32_module_id, ezsms_work_para_t *p_st_para);

/*****************************************************************************/
/* 名称  = ezsms_get_other_info                                               */
/* 功能  = 获取其它运行信息,包括FC、SRIO、FPGA、RAID等                        */
/* 参数  = u32_module_id       I : 模块ID                                     */
/*         p_st_para           O : 模块工作参数信息                           */
/* 返回  = 0        : OK                                                      */
/*         非0      :ERR                                                      */
/* 注意     =                                                                 */
/* 日期 	   =                                                              */
/*****************************************************************************/
int ezsms_get_other_info(int u32_module_id, std::vector<ezsms_kv_t> &v_kv);
#endif //_EZSMS_H_
