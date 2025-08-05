#ifndef MEM_SECTIONS_H
#define MEM_SECTIONS_H

#if defined(__GNUC__)
  #define PSRAM_BSS __attribute__((section(".psram_bss"), aligned(32)))
#else
  #define PSRAM_BSS
#endif

#endif
