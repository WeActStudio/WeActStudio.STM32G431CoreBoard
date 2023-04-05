#include "flash_access.h"
/*!
    \brief      initialize the nand flash
    \param[in]  none
    \param[out] none
    \retval     status
  */
uint32_t  flash_init ()
{
		
	  HAL_FLASH_Unlock();
    
    return 0;
}

/*!
    \brief      read data from multiple blocks of nand flash
    \param[in]  pBuf: pointer to user buffer
    \param[in]  read_addr: address to be read
    \param[in]  block_size: size of block
    \param[in]  block_num: number of block
    \param[out] none
    \retval     status
*/
uint32_t  flash_read_multi_blocks (uint8_t *pBuf, uint32_t read_addr, uint16_t block_size, uint32_t block_num)
{
    uint32_t i;
    uint8_t *pSource = (uint8_t *)(read_addr + NAND_FLASH_BASE_ADDRESS);

    /* Data transfer */
    while (block_num--) {
        for (i = 0; i < block_size; i++) {
            *pBuf++ = *pSource++;
        }
    }

    return 0;
}

/*!
    \brief      write data to multiple blocks of flash
    \param[in]  pBuf: pointer to user buffer
    \param[in]  write_addr: address to be write
    \param[in]  block_size: block size
    \param[in]  block_num: number of block
    \param[out] none
    \retval     status
*/
uint32_t flash_write_multi_blocks (uint8_t *pBuf,
                           uint32_t write_addr,
                           uint16_t block_size,
                           uint32_t block_num)
{
	  FLASH_EraseInitTypeDef pEraseInit;
	  uint32_t PAGEError;
    uint32_t i, page;
    uint32_t start_addr = (write_addr / block_size) * block_size + NAND_FLASH_BASE_ADDRESS;
    uint64_t *ptrs = (uint64_t *)pBuf;
    uint32_t start_page = (write_addr + NAND_FLASH_BASE_ADDRESS)/block_size;
  
    page = block_num;
		
	  pEraseInit.NbPages = page;
	  pEraseInit.Page = start_page;
    pEraseInit.Banks = FLASH_BANK_1;
	  pEraseInit.TypeErase = FLASH_TYPEERASE_PAGES;
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);
	  HAL_FLASHEx_Erase(&pEraseInit,&PAGEError);
    for(; page > 0; page--){

        i = 0;

        do{
					  HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD,start_addr,*ptrs++);
            start_addr += 8;
        }while(++i < (block_size/8));
    }

    return 0;
}
