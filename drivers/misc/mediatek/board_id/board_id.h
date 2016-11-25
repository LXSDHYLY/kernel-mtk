// liupeng@wind-mobi.com 20161121 begin

#ifndef BOARD_ID_H
#define BOARD_ID_H

#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/semaphore.h>


 enum BOARD_ID{
	AP_DS_NA_EVT=0x00, //00
    EMEA_DS_NA_EVT,		//01
	EMEA_SS_NA_EVT,		//02
	EMEA_SS_NFC_EVT,	//03
	LATAM_DS_NA_EVT,	//04
	ROLA_SS_NA_EVT,		//05
	AP_DS_NA_DVT,		//06
	EMEA_DS_NA_DVT,		//07
	EMEA_SS_NA_DVT,		//08
	EMEA_SS_NFC_DVT,	//09
	LATAM_DS_NA_DVT,	//0a
	ROLA_SS_NA_DVT		//0B
 };
 
 enum{
	BOARD_TYPE_EVT=0x00, //EVT
	BOARD_TYPE_DVT
 };
 
 struct board_id_dev{
	int val;
	int board_gpio;
	//struct kobject kobj;
	struct semaphore sem;
	struct cdev dev;
	struct mutex board_mutex;
 };
 
 #define BOARD_ID_DRVNAME		"board_id_z168"
 #define BOARD_ID_MAGIC        86
 #define BOARD_ID_SET_PWR		_IOW(BOARD_ID_MAGIC, 0x01, unsigned int)
 #define BID_MAX_SIZE 				256
 
#define GPIO_TYPE_ID5         (GPIO59 | 0x80000000)
#define GPIO_TYPE_ID4         (GPIO60 | 0x80000000)
#define GPIO_TYPE_ID3         (GPIO71 | 0x80000000)
#define GPIO_TYPE_ID2         (GPIO70 | 0x80000000)
#define GPIO_TYPE_ID1         (GPIO99 | 0x80000000)
 /*
 static ssize_t  bid_dev_read(struct file *filp, char __user *buf, size_t count, loff_t *offset);
 static ssize_t bid_dev_write(struct file *filp, const char __user *buf, size_t count, loff_t *offset);
 static loff_t bid_dev_llseek(struct file *filp ,loff_t *offset,int orig);
 static int bid_dev_open(struct inode *inode,struct file *filp);
 int bid_dev_unlocked_ioctl(struct file *filp ,unsigned int cmd ,unsigned long args);
 static ssize_t bid_num_show(struct device *dev,struct device_attribute *attr,  char *buf);
 static ssize_t bid_num_store(struct device *dev,struct device_attribute *attr, const char *buf,size_t count);
 */
#endif
// liupeng@wind-mobi.com 20161121 end