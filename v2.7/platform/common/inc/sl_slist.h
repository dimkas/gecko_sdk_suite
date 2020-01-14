/***************************************************************************//**
 * @file
 * @brief Single Link List
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef SL_SLIST_H
#define SL_SLIST_H

#include "em_assert.h"
#include "em_core.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup platform_common
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @addtogroup SLIST
 * @{
 ******************************************************************************/

typedef struct sl_slist_node sl_slist_node_t;

struct sl_slist_node {
  sl_slist_node_t *node;
};

#define  container_of(ptr, type, member)  (type *)((uintptr_t)(ptr) - ((uintptr_t)(&((type *)0)->member)))

#define  SL_SLIST_ENTRY                               container_of

#define  SL_SLIST_FOR_EACH(list_head, iterator)       for ((iterator) = (list_head); (iterator) != NULL; (iterator) = (iterator)->node)

#define  SL_SLIST_FOR_EACH_ENTRY(list_head, entry, type, member) for (  (entry) = SL_SLIST_ENTRY(list_head, type, member); \
                                                                        &((entry)->member) != NULL;                        \
                                                                        (entry) = SL_SLIST_ENTRY((entry)->member.node, type, member))

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

/***************************************************************************//**
 * Initializes a singly-linked list.
 *
 * @param    head  Pointer to pointer of head element of list.
 ******************************************************************************/
void sl_slist_init(sl_slist_node_t **head);

/***************************************************************************//**
 * Add given item at beginning of list.
 *
 * @param    head  Pointer to pointer of head element of list.
 *
 * @param    item  Pointer to item to add.
 ******************************************************************************/
void sl_slist_push(sl_slist_node_t **head,
                   sl_slist_node_t *item);

/***************************************************************************//**
 * Add item at end of list.
 *
 * @param    head  Pointer to pointer of head element of list.
 *
 * @param    item  Pointer to item to add.
 ******************************************************************************/
void sl_slist_push_back(sl_slist_node_t **head,
                        sl_slist_node_t *item);

/***************************************************************************//**
 * Removes and returns first element of list.
 *
 * @param    head  Pointer to pointer of head element of list.
 *
 * @return   Pointer to item that was at top of the list.
 ******************************************************************************/
sl_slist_node_t *sl_slist_pop(sl_slist_node_t **head);

/***************************************************************************//**
 * Insert item after given item.
 *
 * @param    item  Pointer to item to add.
 *
 * @param    pos   Pointer to item after which the item to add will be inserted.
 ******************************************************************************/
void sl_slist_insert(sl_slist_node_t *item,
                     sl_slist_node_t *pos);

/***************************************************************************//**
 * Remove item from list.
 *
 * @param    head  Pointer to pointer of head element of list.
 *
 * @param    item  Pointer to item to remove.
 *
 * @note     (1) An EFM_ASSERT is thrown if the item is not found within the list.
 ******************************************************************************/
void sl_slist_remove(sl_slist_node_t **head,
                     sl_slist_node_t *item);

/***************************************************************************//**
 * Sorts list items.
 *
 * @param    head      Pointer to pointer of head element of list.
 *
 * @param    cmp_fnct  Pointer to function to use for sorting the list.
 *                     item_l    Pointer to left  item.
 *                     item_r    Pointer to right item.
 *                     Returns whether the two items are ordered (true) or not (false).
 ******************************************************************************/
void sl_slist_sort(sl_slist_node_t **head,
                   bool (*cmp_fnct)(sl_slist_node_t *item_l,
                                    sl_slist_node_t *item_r));

/** @} (end addtogroup SLIST) */
/** @} (end addtogroup platform_common) */

#ifdef __cplusplus
}
#endif

#endif /* SL_SLIST_H */
