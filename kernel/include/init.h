#ifndef __INIT_H__
#define __INIT_H__

#define ADR_BOOTINFO (0xff0)
#define ADR_DISKIMG 0x00100000

struct BOOTINFO {
  char cyls, leds, vmode, reserve;
  short scrnx, scrny;
  char *vram;
};

struct TASK *open_constask(struct SHEET *sht, unsigned int memtotal);
struct SHEET *open_console(struct SHTCTL *shtctl, unsigned int memtotal);

#endif
