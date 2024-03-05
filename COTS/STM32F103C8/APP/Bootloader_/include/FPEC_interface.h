/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 10 Feb 2024                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : FPEC_interface.h           *****************/
/****************************************************************/
#ifndef FPEC_INTERFACE_
#define FPEC_INTERFACE_

/**
 * @brief Erase the application area in the Flash memory.
 *
 * This function erases the application area in the Flash memory.
 * It iterates over the pages from 4 to 63 and erases each page using FPEC_FlashPageErase().
 *
 * @note This function assumes that FPEC_FlashPageErase() is defined elsewhere.
 *
 * @return None.
 */
void MCAL_FPEC_EraseAppArea(void);

/**
 * @brief Erase a page in the Flash memory.
 *
 * This function erases a page in the Flash memory specified by the given page number.
 * It waits for the Flash controller to become ready, unlocks the Flash if it's locked,
 * initiates the page erase operation, waits for the operation to complete, and clears
 * the End of Operation (EOP) flag after the erase operation.
 *
 * @param PageNumber The page number to be erased.
 * @note This function assumes that the Flash controller (FPEC) peripheral is properly configured and initialized.
 * @return None.
 */	
void MCAL_FPEC_FlashPageErase(u8 PageNumber);

/**
 * @brief Write a half word of data to Flash memory.
 *
 * This function writes a half word of data to the specified address in Flash memory.
 * It waits for the Flash memory controller to become ready before performing the write operation.
 * If the Flash memory controller is locked, it unlocks it using the appropriate sequence.
 *
 * @param Address The address in Flash memory where the half word of data will be written.
 * @param Data The half word of data to be written to Flash memory.
 * @note This function assumes that the Flash controller (FPEC) peripheral is properly configured and initialized.
 *       It does not perform any bounds checking on the address range. Ensure that the provided address is valid.
 * @return None.
 */
void MCAL_FPEC_FlashWrite(uint32_t Address, uint16_t *Data, uint8_t Length);

#endif /**< FPEC_INTERFACE_ */