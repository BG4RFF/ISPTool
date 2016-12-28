/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2013        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control module to the FatFs module with a defined API.        */
/*-----------------------------------------------------------------------*/
#include "NUC230_240.h"
//#include "SPI_FLASH.h"
#include "ISP_BSP.h"
#include "diskio.h"		/* FatFs lower layer API */



//��ʼ������
DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber (0..) */
)
{
		DSTATUS sta;

	
	if(DrvSDCARD_Open()==0)
	{	
	  sta = 	RES_OK;
		
	}
	else
	{
	sta = STA_NOINIT;
	}
	return sta;
}  

//��ô���״̬
DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber (0..) */
)
{ 
	DSTATUS sta1=STA_OK;
	if (pdrv) 
		sta1 =   STA_NOINIT;
	return sta1;
} 

//������
//drv:���̱��0~9
//*buff:���ݽ��ջ����׵�ַ
//sector:������ַ
//count:��Ҫ��ȡ��������
DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address (LBA) */
	UINT count		/* Number of sectors to read (1..128) */
)
{
	DRESULT res;
	uint32_t size;
	  	if (pdrv) {
			res = (DRESULT)STA_NOINIT;	
		return res;
		}


     if(count==0||count>=2)
	   	{	 
		res =   (DRESULT)STA_NOINIT;
		return res;
	}
	   	    size=count*512;
		SpiRead(sector, size, buff);			
		res =RES_OK;	/* Clear STA_NOINIT */;
	return res;
}

//д����
//drv:���̱��0~9
//*buff:���������׵�ַ
//sector:������ַ
//count:��Ҫд���������
#if _USE_WRITE
DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber (0..) */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address (LBA) */
	UINT count			/* Number of sectors to write (1..128) */
)
{
DRESULT  res;	
   uint32_t size;

 	if (pdrv) {
		res = (DRESULT)STA_NOINIT;	
		return res;
	}


	     
    if(count==0||count>=2)
	{	 
		res = (DRESULT)  STA_NOINIT;
		return res;
	}
	    size=count*512;
		SpiWrite(sector, size,(uint8_t *)buff);
	    res = RES_OK;
	return res;	
}
#endif


//����������Ļ��
 //drv:���̱��0~9
 //ctrl:���ƴ���
 //*buff:����/���ջ�����ָ��
#if _USE_IOCTL
DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	{
	DRESULT res;
if (pdrv) return RES_PARERR;

	switch (cmd) {
	case CTRL_SYNC :		/* Make sure that no pending write process */
		res = RES_OK;
		break;

	case GET_SECTOR_COUNT :	/* Get number of sectors on the disk (DWORD) */
DrvSDCARD_GetCardSize(buff);
		res = RES_OK;
		break;

	case GET_SECTOR_SIZE :	/* Get R/W sector size (WORD) */
		*(DWORD*)buff = 512;	//512;
		res = RES_OK;
		break;

	case GET_BLOCK_SIZE :	/* Get erase block size in unit of sector (DWORD) */
		*(DWORD*)buff = 1;
		res = RES_OK;
		break;


	default:
		res = RES_PARERR;
	}


	res = RES_OK;


	return res;
}
	}
#endif
DWORD get_fattime(void)
{				 
	return 0;
}			 

void *ff_memalloc (UINT size)			
{
	return 0;
	//return (void*)mymalloc(size);
}
//????
void ff_memfree (void* mf)		 
{
	//myfree(mf);
}
