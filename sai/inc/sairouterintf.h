/*
* Copyright (c) 2014 Microsoft Open Technologies, Inc. 
*   
*    Licensed under the Apache License, Version 2.0 (the "License"); you may 
*    not use this file except in compliance with the License. You may obtain 
*    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
*
*    THIS CODE IS PROVIDED ON AN  *AS IS* BASIS, WITHOUT WARRANTIES OR 
*    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
*    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
*
*    See the Apache Version 2.0 License for specific language governing 
*    permissions and limitations under the License. 
*
*    Microsoft would like to thank the following companies for their review and
*    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
*    Dell Products, L.P., Facebook, Inc
*   
* Module Name:
*
*    sairouterintf.h
*
* Abstract:
*
*    This module defines SAI Router Interface
*
*/

#if !defined (__SAIROUTERINTF_H_)
#define __SAIROUTERINTF_H_

#include <saitypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
*  Attribute data for SAI_ROUTER_INTERFACE_ATTR_TYPE
*/
typedef enum _sai_router_interface_type_t 
{
    /* Port Router Interface Type */
    SAI_ROUTER_INTERFACE_TYPE_PORT,

    /* VLAN Router Interface Type */
    SAI_ROUTER_INTERFACE_TYPE_VLAN

} sai_router_interface_type_t;


/*
*  Routing interface attribute IDs 
*/
typedef enum _sai_router_interface_attr_t
{
    /* READ-ONLY */

    /* Virtual router id [sai_virtual_router_id_t]
     *  (mandatory for create) */
    SAI_ROUTER_INTERFACE_ATTR_VIRTUAL_ROUTER_ID,

    /* Type [sai_router_interface_type_t]
     *  (mandatory for create) */
    SAI_ROUTER_INTERFACE_ATTR_TYPE,

    /* Assosiated Port [sai_port_id_t] 
    *   (mandatory for create when SAI_ROUTER_INTERFACE_ATTR_TYPE == SAI_ROUTER_INTERFACE_TYPE_PORT) 
    */
    SAI_ROUTER_INTERFACE_ATTR_PORT_ID,

    /* Assosiated Vlan [sai_vlan_id_t] 
    *   (mandatory for create when SAI_ROUTER_INTERFACE_ATTR_TYPE == SAI_ROUTER_INTERFACE_TYPE_VLAN) 
    */
    SAI_ROUTER_INTERFACE_ATTR_VLAN_ID,

    /* READ-WRITE */

    /* MAC Address [sai_mac_t] 
        (equal to the SAI_VIRTUAL_ROUTER_ATTR_SRC_MAC_ADDRESS by default) */
    SAI_ROUTER_INTERFACE_ATTR_SRC_MAC_ADDRESS,

    /* Admin V4 state [bool] (default to TRUE) */
    SAI_ROUTER_INTERFACE_ATTR_ADMIN_V4_STATE,

    /* Admin V6 state [bool] (default to TRUE) */
    SAI_ROUTER_INTERFACE_ATTR_ADMIN_V6_STATE,

    /* MTU [uint32_t], (default to  1514 bytes) */
    SAI_ROUTER_INTERFACE_ATTR_MTU,

    /* -- */

    /* Custom range base value */
    SAI_ROUTER_INTERFACE_ATTR_CUSTOM_RANGE_BASE  = 0x10000000

} sai_router_interface_attr_t;

/*
* Routine Description:
*    Create router interface. 
*
* Arguments:
*    [out] rif_id - router interface id
*    [in] attr_count - number of attributes
*    [in] attr_list - array of attributes
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/
typedef sai_status_t(*sai_create_router_interface_fn)(
    _Out_ sai_router_interface_id_t* rif_id,
    _In_ uint32_t attr_count,
    _In_ sai_attribute_t *attr_list
    );

/*
* Routine Description:
*    Remove router interface
*
* Arguments:
*    [in] rif_id - router interface id
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/
typedef sai_status_t(*sai_remove_router_interface_fn)(
    _In_ sai_router_interface_id_t rif_id
    );

/*
* Routine Description:
*    Set router interface attribute
*
* Arguments:
*    [in] sai_router_interface_id_t - router_interface_id
*    [in] attr - attribute
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/
typedef sai_status_t (*sai_set_router_interface_attribute_fn)(
    _In_ sai_router_interface_id_t rif_id,
    _In_ const sai_attribute_t *attr
    );


/*
* Routine Description:
*    Get router interface attribute
*
* Arguments:
*    [in] sai_router_interface_id_t - router_interface_id
*    [in] attr_count - number of attributes
*    [inout] attr_list - array of attributes
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/
typedef sai_status_t (*sai_get_router_interface_attribute_fn)(
    _In_ sai_router_interface_id_t rif_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
    );

/*
*  Routing interface methods table retrieved with sai_api_query()
*/
typedef struct _sai_router_interface_api_t
{
    sai_create_router_interface_fn          create_router_interface;
    sai_remove_router_interface_fn          remove_router_interface;
    sai_set_router_interface_attribute_fn   set_router_interface_attribute;
    sai_get_router_interface_attribute_fn   get_router_interface_attribute;

} sai_router_interface_api_t;

#ifdef __cplusplus
}
#endif

#endif // __SAIROUTERINTF_H_

