#include "ll_aton_NN_interface.h"
#include "ll_aton.h"
#include "ll_aton_ec_trace.h"

#if 0
// Workaround: the tracer does not know the target at this moment
// and cannot call the functions since are used in static code
#define ATON_LIB_PHYSICAL_TO_VIRTUAL_ADDR(address) LL_Address_Physical2Virtual(address)
#define ATON_LIB_VIRTUAL_TO_PHYSICAL_ADDR(address) LL_Address_Virtual2Physical(address)
#else
#define ATON_LIB_PHYSICAL_TO_VIRTUAL_ADDR(address) (address)
#define ATON_LIB_VIRTUAL_TO_PHYSICAL_ADDR(address) (address)
#endif


mpool_reloc_info_t mpool_reloc_info[] = {
  {"AXISRAM6", "_mem_pool_AXISRAM6_weed_detection", 0x34350000, 1, 0},
  {"AXISRAM5", "_mem_pool_AXISRAM5_weed_detection", 0x342e0000, 1, 0},
  {"AXISRAM4", "_mem_pool_AXISRAM4_weed_detection", 0x34270000, 1, 0},
  {"AXISRAM3", "_mem_pool_AXISRAM3_weed_detection", 0x34200000, 1, 0},
  {"AXISRAM2", "_mem_pool_AXISRAM2_weed_detection", 0x34100000, 1, 0},
  {"AXISRAM1", "_mem_pool_AXISRAM1_weed_detection", 0x34080000, 1, 0},
  {"AXIFLEXMEM", "_mem_pool_AXIFLEXMEM_weed_detection", 0x34000000, 1, 0},
  {"xSPI1", "_mem_pool_xSPI1_weed_detection", 0x90000000, 1, 0},
  {"AXISRAM2_AXISRAM3_AXISRAM4_AXISRAM5_AXISRAM6", "_mem_pool_AXISRAM2_AXISRAM3_AXISRAM4_AXISRAM5_AXISRAM6_weed_detection", 0x34100000, 1, 0},
  {NULL, NULL, 0, 0, 0}
};


void trace_ec__ec_blob_weed_detection_1(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_1");
  ec_trace_start_epoch(1);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Identity node=Identity_inserted_id399 */
    /* node=Identity_inserted_id399 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 6 [STREAM_ENG_V2 6] */
    /* Emit conf for STREAM_ENG_V2 node=Identity_inserted_id399 input ports=0 range=7[7499824,12415024] */

    static const LL_Streng_TensorInitTypeDef Identity_inserted_id399_dma_init_in_0_1 = {
      /* from memory with batch=1 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Input_12_out_0_inserted_in399 */
      .offset_start = 7499824,
      .offset_end = 9138224,
      .offset_limit = 12415088,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 1638400,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 3,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(6, &Identity_inserted_id399_dma_init_in_0_1, 1);


    /* Dma input bandwidth from memory pools: */
    /* hyperRAM -> 4915200 */

    /* Dma output units from cycle: */
    /* Unit= 4 [STREAM_ENG_V2 4] */
    /* Emit conf for STREAM_ENG_V2 node=Identity_inserted_id399 output ports=0 range=7[14053424,18968624] */

    static const LL_Streng_TensorInitTypeDef Identity_inserted_id399_dma_init_out_0_1 = {
      /* to memory canonical from batch=1 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Input_12_out_0_inserted_out399 */
      .offset_start = 14053424,
      .offset_limit = 18968688,
      .frame_count = 0,
      .fwidth = 640,
      .fheight = 640,
      .batch_depth = 2,
      .batch_offset = 12,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 4915200,
      .frame_loop_cnt = 3,
      .frame_tot_cnt = 3,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(4, &Identity_inserted_id399_dma_init_out_0_1, 1);


    /* Dma output bandwidth to memory pools: */
    /* hyperRAM <- 4915200 */

    static const LL_Switch_InitTypeDef switch_init_in_1[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 4, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 6, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Identity_inserted_id399 OUT: in unit=STREAM_ENG_V2 4 in port=0 out unit=STREAM_ENG_V2 6 out port=0 */
    };


    /* epoch=1 */
    LL_Switch_Init(switch_init_in_1, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_1_all_units[] = {
      { {STRENG, 4} }, /* STREAM_ENG_V2 */
      { {STRENG, 6} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_1_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x10);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_1[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 4, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 6, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Identity_inserted_id399 OUT: in unit=STREAM_ENG_V2 4 in port=0 out unit=STREAM_ENG_V2 6 out port=0 */
    };


    /* epoch=1 */
    LL_Switch_Deinit(switch_deinit_in_1, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_1_all_units[] = {
      { {STRENG, 4} }, /* STREAM_ENG_V2 */
      { {STRENG, 6} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_1_all_units, 2);

  }
  ec_trace_end_epoch(1);
  ec_trace_end_blob("_ec_blob_weed_detection_1");
}

void trace_ec__ec_blob_weed_detection_21(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_21");
  ec_trace_start_epoch(21);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_32 */
    /* node=Concat_32 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 5 [STREAM_ENG_V2 5] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_32 input ports=0 range=7[7499824,10776624] */

    static const LL_Streng_TensorInitTypeDef Concat_32_dma_init_in_0_21 = {
      /* from memory with batch=16 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Add_31_out_0 */
      .offset_start = 7499824,
      .offset_end = 9138224,
      .offset_limit = 10776688,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 1638400,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(5, &Concat_32_dma_init_in_0_21, 1);


    /* Dma input bandwidth from memory pools: */
    /* hyperRAM -> 3276800 */

    /* Dma output units from cycle: */
    /* Unit= 0 [STREAM_ENG_V2 0] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_32 output ports=0 range=7[10776624,14053424] */

    static const LL_Streng_TensorInitTypeDef Concat_32_dma_init_out_0_21 = {
      /* to memory canonical from batch=16 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Concat_32_out_0 */
      .offset_start = 10776624,
      .offset_limit = 14053488,
      .frame_count = 0,
      .fwidth = 160,
      .fheight = 160,
      .batch_depth = 32,
      .batch_offset = 128,
      .frame_offset = 64,
      .line_offset = 0,
      .loop_offset = 3276800,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(0, &Concat_32_dma_init_out_0_21, 1);


    /* Dma output bandwidth to memory pools: */
    /* hyperRAM <- 3276800 */

    static const LL_Switch_InitTypeDef switch_init_in_21[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 5, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_32 OUT: in unit=STREAM_ENG_V2 0 in port=0 out unit=STREAM_ENG_V2 5 out port=0 */
    };


    /* epoch=21 */
    LL_Switch_Init(switch_init_in_21, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_21_all_units[] = {
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 5} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_21_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x1);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_21[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 5, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_32 OUT: in unit=STREAM_ENG_V2 0 in port=0 out unit=STREAM_ENG_V2 5 out port=0 */
    };


    /* epoch=21 */
    LL_Switch_Deinit(switch_deinit_in_21, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_21_all_units[] = {
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 5} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_21_all_units, 2);

  }
  ec_trace_end_epoch(21);
  ec_trace_end_blob("_ec_blob_weed_detection_21");
}

void trace_ec__ec_blob_weed_detection_48(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_48");
  ec_trace_start_epoch(48);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_59 */
    /* node=Concat_59 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 9 [STREAM_ENG_V2 9] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_59 input ports=0 range=10[0,1638400] */

    static const LL_Streng_TensorInitTypeDef Concat_59_dma_init_in_0_48 = {
      /* from memory with batch=32 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Add_58_out_0 */
      .offset_start = 0,
      .offset_end = 819200,
      .offset_limit = 1638464,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 819200,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(9, &Concat_59_dma_init_in_0_48, 1);


    /* Dma input bandwidth from memory pools: */
    /* npuRAM4 -> 131072 */
    /* npuRAM3 -> 458752 */
    /* cpuRAM2 -> 1048576 */

    /* Dma output units from cycle: */
    /* Unit= 3 [STREAM_ENG_V2 3] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_59 output ports=0 range=7[7499824,9138224] */

    static const LL_Streng_TensorInitTypeDef Concat_59_dma_init_out_0_48 = {
      /* to memory canonical from batch=32 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Concat_59_out_0 */
      .offset_start = 7499824,
      .offset_limit = 9138288,
      .frame_count = 0,
      .fwidth = 80,
      .fheight = 80,
      .batch_depth = 64,
      .batch_offset = 256,
      .frame_offset = 128,
      .line_offset = 0,
      .loop_offset = 1638400,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(3, &Concat_59_dma_init_out_0_48, 1);


    /* Dma output bandwidth to memory pools: */
    /* hyperRAM <- 1638400 */

    static const LL_Switch_InitTypeDef switch_init_in_48[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_59 OUT: in unit=STREAM_ENG_V2 3 in port=0 out unit=STREAM_ENG_V2 9 out port=0 */
    };


    /* epoch=48 */
    LL_Switch_Init(switch_init_in_48, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_48_all_units[] = {
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_48_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x8);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_48[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_59 OUT: in unit=STREAM_ENG_V2 3 in port=0 out unit=STREAM_ENG_V2 9 out port=0 */
    };


    /* epoch=48 */
    LL_Switch_Deinit(switch_deinit_in_48, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_48_all_units[] = {
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_48_all_units, 2);

  }
  ec_trace_end_epoch(48);
  ec_trace_end_blob("_ec_blob_weed_detection_48");
}

void trace_ec__ec_blob_weed_detection_82(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_82");
  ec_trace_start_epoch(82);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_93 */
    /* node=Concat_93 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 7 [STREAM_ENG_V2 7] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_93 input ports=0 range=10[0,819200] */

    static const LL_Streng_TensorInitTypeDef Concat_93_dma_init_in_0_82 = {
      /* from memory with batch=64 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Add_92_out_0 */
      .offset_start = 0,
      .offset_end = 409600,
      .offset_limit = 819264,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 409600,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(7, &Concat_93_dma_init_in_0_82, 1);


    /* Dma input bandwidth from memory pools: */
    /* cpuRAM2 -> 819200 */

    /* Dma output units from cycle: */
    /* Unit= 1 [STREAM_ENG_V2 1] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_93 output ports=0 range=10[819200,1638400] */

    static const LL_Streng_TensorInitTypeDef Concat_93_dma_init_out_0_82 = {
      /* to memory canonical from batch=64 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Concat_93_out_0 */
      .offset_start = 819200,
      .offset_limit = 1638464,
      .frame_count = 0,
      .fwidth = 40,
      .fheight = 40,
      .batch_depth = 128,
      .batch_offset = 512,
      .frame_offset = 256,
      .line_offset = 0,
      .loop_offset = 819200,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(1, &Concat_93_dma_init_out_0_82, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM4 <- 131072 */
    /* npuRAM3 <- 458752 */
    /* cpuRAM2 <- 229376 */

    static const LL_Switch_InitTypeDef switch_init_in_82[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 1, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_93 OUT: in unit=STREAM_ENG_V2 1 in port=0 out unit=STREAM_ENG_V2 7 out port=0 */
    };


    /* epoch=82 */
    LL_Switch_Init(switch_init_in_82, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_82_all_units[] = {
      { {STRENG, 1} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_82_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x2);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_82[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 1, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_93 OUT: in unit=STREAM_ENG_V2 1 in port=0 out unit=STREAM_ENG_V2 7 out port=0 */
    };


    /* epoch=82 */
    LL_Switch_Deinit(switch_deinit_in_82, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_82_all_units[] = {
      { {STRENG, 1} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_82_all_units, 2);

  }
  ec_trace_end_epoch(82);
  ec_trace_end_blob("_ec_blob_weed_detection_82");
}

void trace_ec__ec_blob_weed_detection_102(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_102");
  ec_trace_start_epoch(102);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_113 */
    /* node=Concat_113 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 6 [STREAM_ENG_V2 6] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_113 input ports=0 range=1[0,409600] */

    static const LL_Streng_TensorInitTypeDef Concat_113_dma_init_in_0_102 = {
      /* from memory with batch=128 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Add_112_out_0 */
      .offset_start = 0,
      .offset_end = 204800,
      .offset_limit = 409664,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 204800,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(6, &Concat_113_dma_init_in_0_102, 1);


    /* Dma input bandwidth from memory pools: */
    /* npuRAM5 -> 409600 */

    /* Dma output units from cycle: */
    /* Unit= 2 [STREAM_ENG_V2 2] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_113 output ports=0 range=2[0,409600] */

    static const LL_Streng_TensorInitTypeDef Concat_113_dma_init_out_0_102 = {
      /* to memory canonical from batch=128 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34270000UL) /* Equivalent hex address = 0x34270000UL */}, /* Concat_113_out_0 */
      .offset_start = 0,
      .offset_limit = 409664,
      .frame_count = 0,
      .fwidth = 20,
      .fheight = 20,
      .batch_depth = 256,
      .batch_offset = 1024,
      .frame_offset = 512,
      .line_offset = 0,
      .loop_offset = 409600,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(2, &Concat_113_dma_init_out_0_102, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM4 <- 409600 */

    static const LL_Switch_InitTypeDef switch_init_in_102[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 6, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_113 OUT: in unit=STREAM_ENG_V2 2 in port=0 out unit=STREAM_ENG_V2 6 out port=0 */
    };


    /* epoch=102 */
    LL_Switch_Init(switch_init_in_102, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_102_all_units[] = {
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
      { {STRENG, 6} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_102_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x4);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_102[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 6, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_113 OUT: in unit=STREAM_ENG_V2 2 in port=0 out unit=STREAM_ENG_V2 6 out port=0 */
    };


    /* epoch=102 */
    LL_Switch_Deinit(switch_deinit_in_102, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_102_all_units[] = {
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
      { {STRENG, 6} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_102_all_units, 2);

  }
  ec_trace_end_epoch(102);
  ec_trace_end_blob("_ec_blob_weed_detection_102");
}

void trace_ec__ec_blob_weed_detection_118(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_118");
  ec_trace_start_epoch(118);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_123 */
    /* node=Concat_123 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 4 [STREAM_ENG_V2 4] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_123 input ports=0 range=10[0,819200] */

    static const LL_Streng_TensorInitTypeDef Concat_123_dma_init_in_0_118 = {
      /* from memory with batch=128 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Mul_119_out_0 */
      .offset_start = 0,
      .offset_end = 204800,
      .offset_limit = 819264,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 204800,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 4,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(4, &Concat_123_dma_init_in_0_118, 1);


    /* Dma input bandwidth from memory pools: */
    /* cpuRAM2 -> 819200 */

    /* Dma output units from cycle: */
    /* Unit= 8 [STREAM_ENG_V2 8] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_123 output ports=0 range=10[819200,1638400] */

    static const LL_Streng_TensorInitTypeDef Concat_123_dma_init_out_0_118 = {
      /* to memory canonical from batch=128 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Concat_123_out_0 */
      .offset_start = 819200,
      .offset_limit = 1638464,
      .frame_count = 0,
      .fwidth = 20,
      .fheight = 20,
      .batch_depth = 256,
      .batch_offset = 2048,
      .frame_offset = 512,
      .line_offset = 0,
      .loop_offset = 819200,
      .frame_loop_cnt = 4,
      .frame_tot_cnt = 4,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(8, &Concat_123_dma_init_out_0_118, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM4 <- 131072 */
    /* npuRAM3 <- 458752 */
    /* cpuRAM2 <- 229376 */

    static const LL_Switch_InitTypeDef switch_init_in_118[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 4, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_123 OUT: in unit=STREAM_ENG_V2 8 in port=0 out unit=STREAM_ENG_V2 4 out port=0 */
    };


    /* epoch=118 */
    LL_Switch_Init(switch_init_in_118, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_118_all_units[] = {
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
      { {STRENG, 4} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_118_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x100);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_118[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 4, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_123 OUT: in unit=STREAM_ENG_V2 8 in port=0 out unit=STREAM_ENG_V2 4 out port=0 */
    };


    /* epoch=118 */
    LL_Switch_Deinit(switch_deinit_in_118, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_118_all_units[] = {
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
      { {STRENG, 4} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_118_all_units, 2);

  }
  ec_trace_end_epoch(118);
  ec_trace_end_blob("_ec_blob_weed_detection_118");
}

void trace_ec__ec_blob_weed_detection_125(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_125");
  ec_trace_start_epoch(125);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Resize_130_resize_NN_expansion_concat_9 */
    /* node=Resize_130_resize_NN_expansion_concat_9 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 7 [STREAM_ENG_V2 7] */
    /* Emit conf for STREAM_ENG_V2 node=Resize_130_resize_NN_expansion_concat_9 input ports=0 range=1[204800,409600] */

    static const LL_Streng_TensorInitTypeDef Resize_130_resize_NN_expansion_concat_9_dma_init_in_0_125 = {
      /* from memory with batch=128
iterating outer iter=0 num_higher_elem=4
spanning across 819200 bytes */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Mul_129_out_0 */
      .offset_start = 204800,
      .offset_end = 409600,
      .offset_limit = 409664,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 204800,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 1,
      .frame_tot_cnt = 4,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(7, &Resize_130_resize_NN_expansion_concat_9_dma_init_in_0_125, 1);


    /* Dma input bandwidth from memory pools: */
    /* npuRAM5 -> 819200 */

    /* Dma output units from cycle: */
    /* Unit= 4 [STREAM_ENG_V2 4] */
    /* Emit conf for STREAM_ENG_V2 node=Resize_130_resize_NN_expansion_concat_9 output ports=0 range=10[0,819200] */

    static const LL_Streng_TensorInitTypeDef Resize_130_resize_NN_expansion_concat_9_dma_init_out_0_125 = {
      /* to memory canonical from batch=128 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Resize_130_resize_NN_expansion_concat_9_out_10 */
      .offset_start = 0,
      .offset_limit = 819264,
      .frame_count = 0,
      .fwidth = 20,
      .fheight = 20,
      .batch_depth = 256,
      .batch_offset = 2048,
      .frame_offset = 512,
      .line_offset = 0,
      .loop_offset = 819200,
      .frame_loop_cnt = 4,
      .frame_tot_cnt = 4,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(4, &Resize_130_resize_NN_expansion_concat_9_dma_init_out_0_125, 1);


    /* Dma output bandwidth to memory pools: */
    /* cpuRAM2 <- 819200 */

    static const LL_Switch_InitTypeDef switch_init_in_125[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 4, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Resize_130_resize_NN_expansion_concat_9 OUT: in unit=STREAM_ENG_V2 4 in port=0 out unit=STREAM_ENG_V2 7 out port=0 */
    };


    /* epoch=125 */
    LL_Switch_Init(switch_init_in_125, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_125_all_units[] = {
      { {STRENG, 4} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_125_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x10);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_125[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 4, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Resize_130_resize_NN_expansion_concat_9 OUT: in unit=STREAM_ENG_V2 4 in port=0 out unit=STREAM_ENG_V2 7 out port=0 */
    };


    /* epoch=125 */
    LL_Switch_Deinit(switch_deinit_in_125, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_125_all_units[] = {
      { {STRENG, 4} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_125_all_units, 2);

  }
  ec_trace_end_epoch(125);
  ec_trace_end_blob("_ec_blob_weed_detection_125");
}

void trace_ec__ec_blob_weed_detection_127(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_127");
  ec_trace_start_epoch(127);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_131 */
    /* node=Concat_131 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 0 [STREAM_ENG_V2 0] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_131 input ports=0 range=7[10776624,12415024] */

    static const LL_Streng_TensorInitTypeDef Concat_131_dma_init_in_0_127 = {
      /* from memory with batch=128 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Resize_130_resize_NN_expansion_concat_9_out_12 */
      .offset_start = 10776624,
      .offset_end = 11595824,
      .offset_limit = 12415088,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 819200,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(0, &Concat_131_dma_init_in_0_127, 1);


    /* Dma input bandwidth from memory pools: */
    /* hyperRAM -> 1638400 */

    /* Dma output units from cycle: */
    /* Unit= 9 [STREAM_ENG_V2 9] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_131 output ports=0 range=7[12415024,14053424] */

    static const LL_Streng_TensorInitTypeDef Concat_131_dma_init_out_0_127 = {
      /* to memory canonical from batch=128 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Concat_131_out_0 */
      .offset_start = 12415024,
      .offset_limit = 14053488,
      .frame_count = 0,
      .fwidth = 40,
      .fheight = 40,
      .batch_depth = 256,
      .batch_offset = 1024,
      .frame_offset = 512,
      .line_offset = 0,
      .loop_offset = 1638400,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(9, &Concat_131_dma_init_out_0_127, 1);


    /* Dma output bandwidth to memory pools: */
    /* hyperRAM <- 1638400 */

    static const LL_Switch_InitTypeDef switch_init_in_127[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_131 OUT: in unit=STREAM_ENG_V2 9 in port=0 out unit=STREAM_ENG_V2 0 out port=0 */
    };


    /* epoch=127 */
    LL_Switch_Init(switch_init_in_127, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_127_all_units[] = {
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_127_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x200);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_127[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_131 OUT: in unit=STREAM_ENG_V2 9 in port=0 out unit=STREAM_ENG_V2 0 out port=0 */
    };


    /* epoch=127 */
    LL_Switch_Deinit(switch_deinit_in_127, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_127_all_units[] = {
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_127_all_units, 2);

  }
  ec_trace_end_epoch(127);
  ec_trace_end_blob("_ec_blob_weed_detection_127");
}

void trace_ec__ec_blob_weed_detection_140(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_140");
  ec_trace_start_epoch(140);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_144 */
    /* node=Concat_144 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 2 [STREAM_ENG_V2 2] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_144 input ports=0 range=10[0,819200] */

    static const LL_Streng_TensorInitTypeDef Concat_144_dma_init_in_0_140 = {
      /* from memory with batch=64 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Mul_143_out_0 */
      .offset_start = 0,
      .offset_end = 409600,
      .offset_limit = 819264,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 409600,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(2, &Concat_144_dma_init_in_0_140, 1);


    /* Dma input bandwidth from memory pools: */
    /* cpuRAM2 -> 819200 */

    /* Dma output units from cycle: */
    /* Unit= 5 [STREAM_ENG_V2 5] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_144 output ports=0 range=10[819200,1638400] */

    static const LL_Streng_TensorInitTypeDef Concat_144_dma_init_out_0_140 = {
      /* to memory canonical from batch=64 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Concat_144_out_0 */
      .offset_start = 819200,
      .offset_limit = 1638464,
      .frame_count = 0,
      .fwidth = 40,
      .fheight = 40,
      .batch_depth = 128,
      .batch_offset = 512,
      .frame_offset = 256,
      .line_offset = 0,
      .loop_offset = 819200,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(5, &Concat_144_dma_init_out_0_140, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM4 <- 131072 */
    /* npuRAM3 <- 458752 */
    /* cpuRAM2 <- 229376 */

    static const LL_Switch_InitTypeDef switch_init_in_140[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 5, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_144 OUT: in unit=STREAM_ENG_V2 5 in port=0 out unit=STREAM_ENG_V2 2 out port=0 */
    };


    /* epoch=140 */
    LL_Switch_Init(switch_init_in_140, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_140_all_units[] = {
      { {STRENG, 5} }, /* STREAM_ENG_V2 */
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_140_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x20);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_140[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 5, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_144 OUT: in unit=STREAM_ENG_V2 5 in port=0 out unit=STREAM_ENG_V2 2 out port=0 */
    };


    /* epoch=140 */
    LL_Switch_Deinit(switch_deinit_in_140, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_140_all_units[] = {
      { {STRENG, 5} }, /* STREAM_ENG_V2 */
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_140_all_units, 2);

  }
  ec_trace_end_epoch(140);
  ec_trace_end_blob("_ec_blob_weed_detection_140");
}

void trace_ec__ec_blob_weed_detection_147(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_147");
  ec_trace_start_epoch(147);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Resize_151_resize_NN_expansion_concat_13 */
    /* node=Resize_151_resize_NN_expansion_concat_13 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 9 [STREAM_ENG_V2 9] */
    /* Emit conf for STREAM_ENG_V2 node=Resize_151_resize_NN_expansion_concat_13 input ports=0 range=7[14463024,14872624] */

    static const LL_Streng_TensorInitTypeDef Resize_151_resize_NN_expansion_concat_13_dma_init_in_0_147 = {
      /* from memory with batch=64
iterating outer iter=0 num_higher_elem=4
spanning across 1638400 bytes */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Mul_150_out_0 */
      .offset_start = 14463024,
      .offset_end = 14872624,
      .offset_limit = 14872688,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 409600,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 1,
      .frame_tot_cnt = 4,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(9, &Resize_151_resize_NN_expansion_concat_13_dma_init_in_0_147, 1);


    /* Dma input bandwidth from memory pools: */
    /* hyperRAM -> 1638400 */

    /* Dma output units from cycle: */
    /* Unit= 3 [STREAM_ENG_V2 3] */
    /* Emit conf for STREAM_ENG_V2 node=Resize_151_resize_NN_expansion_concat_13 output ports=0 range=10[0,1638400] */

    static const LL_Streng_TensorInitTypeDef Resize_151_resize_NN_expansion_concat_13_dma_init_out_0_147 = {
      /* to memory canonical from batch=64 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Resize_151_resize_NN_expansion_concat_13_out_14 */
      .offset_start = 0,
      .offset_limit = 1638464,
      .frame_count = 0,
      .fwidth = 40,
      .fheight = 40,
      .batch_depth = 128,
      .batch_offset = 1024,
      .frame_offset = 256,
      .line_offset = 0,
      .loop_offset = 1638400,
      .frame_loop_cnt = 4,
      .frame_tot_cnt = 4,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(3, &Resize_151_resize_NN_expansion_concat_13_dma_init_out_0_147, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM4 <- 131072 */
    /* npuRAM3 <- 458752 */
    /* cpuRAM2 <- 1048576 */

    static const LL_Switch_InitTypeDef switch_init_in_147[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Resize_151_resize_NN_expansion_concat_13 OUT: in unit=STREAM_ENG_V2 3 in port=0 out unit=STREAM_ENG_V2 9 out port=0 */
    };


    /* epoch=147 */
    LL_Switch_Init(switch_init_in_147, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_147_all_units[] = {
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_147_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x8);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_147[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Resize_151_resize_NN_expansion_concat_13 OUT: in unit=STREAM_ENG_V2 3 in port=0 out unit=STREAM_ENG_V2 9 out port=0 */
    };


    /* epoch=147 */
    LL_Switch_Deinit(switch_deinit_in_147, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_147_all_units[] = {
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_147_all_units, 2);

  }
  ec_trace_end_epoch(147);
  ec_trace_end_blob("_ec_blob_weed_detection_147");
}

void trace_ec__ec_blob_weed_detection_149(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_149");
  ec_trace_start_epoch(149);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_152 */
    /* node=Concat_152 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 2 [STREAM_ENG_V2 2] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_152 input ports=0 range=7[7499824,10776624] */

    static const LL_Streng_TensorInitTypeDef Concat_152_dma_init_in_0_149 = {
      /* from memory with batch=64 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Resize_151_resize_NN_expansion_concat_13_out_16 */
      .offset_start = 7499824,
      .offset_end = 9138224,
      .offset_limit = 10776688,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 1638400,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(2, &Concat_152_dma_init_in_0_149, 1);


    /* Dma input bandwidth from memory pools: */
    /* hyperRAM -> 3276800 */

    /* Dma output units from cycle: */
    /* Unit= 6 [STREAM_ENG_V2 6] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_152 output ports=0 range=7[10776624,14053424] */

    static const LL_Streng_TensorInitTypeDef Concat_152_dma_init_out_0_149 = {
      /* to memory canonical from batch=64 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Concat_152_out_0 */
      .offset_start = 10776624,
      .offset_limit = 14053488,
      .frame_count = 0,
      .fwidth = 80,
      .fheight = 80,
      .batch_depth = 128,
      .batch_offset = 512,
      .frame_offset = 256,
      .line_offset = 0,
      .loop_offset = 3276800,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(6, &Concat_152_dma_init_out_0_149, 1);


    /* Dma output bandwidth to memory pools: */
    /* hyperRAM <- 3276800 */

    static const LL_Switch_InitTypeDef switch_init_in_149[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 6, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_152 OUT: in unit=STREAM_ENG_V2 6 in port=0 out unit=STREAM_ENG_V2 2 out port=0 */
    };


    /* epoch=149 */
    LL_Switch_Init(switch_init_in_149, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_149_all_units[] = {
      { {STRENG, 6} }, /* STREAM_ENG_V2 */
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_149_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x40);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_149[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 6, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_152 OUT: in unit=STREAM_ENG_V2 6 in port=0 out unit=STREAM_ENG_V2 2 out port=0 */
    };


    /* epoch=149 */
    LL_Switch_Deinit(switch_deinit_in_149, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_149_all_units[] = {
      { {STRENG, 6} }, /* STREAM_ENG_V2 */
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_149_all_units, 2);

  }
  ec_trace_end_epoch(149);
  ec_trace_end_blob("_ec_blob_weed_detection_149");
}

void trace_ec__ec_blob_weed_detection_162(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_162");
  ec_trace_start_epoch(162);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_165 */
    /* node=Concat_165 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 8 [STREAM_ENG_V2 8] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_165 input ports=0 range=10[0,1638400] */

    static const LL_Streng_TensorInitTypeDef Concat_165_dma_init_in_0_162 = {
      /* from memory with batch=32 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Mul_164_out_0 */
      .offset_start = 0,
      .offset_end = 819200,
      .offset_limit = 1638464,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 819200,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(8, &Concat_165_dma_init_in_0_162, 1);


    /* Dma input bandwidth from memory pools: */
    /* npuRAM4 -> 131072 */
    /* npuRAM3 -> 458752 */
    /* cpuRAM2 -> 1048576 */

    /* Dma output units from cycle: */
    /* Unit= 3 [STREAM_ENG_V2 3] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_165 output ports=0 range=7[7499824,9138224] */

    static const LL_Streng_TensorInitTypeDef Concat_165_dma_init_out_0_162 = {
      /* to memory canonical from batch=32 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Concat_165_out_0 */
      .offset_start = 7499824,
      .offset_limit = 9138288,
      .frame_count = 0,
      .fwidth = 80,
      .fheight = 80,
      .batch_depth = 64,
      .batch_offset = 256,
      .frame_offset = 128,
      .line_offset = 0,
      .loop_offset = 1638400,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(3, &Concat_165_dma_init_out_0_162, 1);


    /* Dma output bandwidth to memory pools: */
    /* hyperRAM <- 1638400 */

    static const LL_Switch_InitTypeDef switch_init_in_162[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_165 OUT: in unit=STREAM_ENG_V2 3 in port=0 out unit=STREAM_ENG_V2 8 out port=0 */
    };


    /* epoch=162 */
    LL_Switch_Init(switch_init_in_162, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_162_all_units[] = {
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_162_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x8);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_162[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_165 OUT: in unit=STREAM_ENG_V2 3 in port=0 out unit=STREAM_ENG_V2 8 out port=0 */
    };


    /* epoch=162 */
    LL_Switch_Deinit(switch_deinit_in_162, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_162_all_units[] = {
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_162_all_units, 2);

  }
  ec_trace_end_epoch(162);
  ec_trace_end_blob("_ec_blob_weed_detection_162");
}

void trace_ec__ec_blob_weed_detection_170(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_170");
  ec_trace_start_epoch(170);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_180 */
    /* node=Concat_180 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Reshape node=Reshape_170 */
    /* node=Reshape_170 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 2 [STREAM_ENG_V2 2] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_180 input ports=0 range=7[14053424,14872624] */

    static const LL_Streng_TensorInitTypeDef Concat_180_dma_init_in_0_170 = {
      /* from memory with batch=64 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Mul_179_out_0 */
      .offset_start = 14053424,
      .offset_end = 14463024,
      .offset_limit = 14872688,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 409600,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(2, &Concat_180_dma_init_in_0_170, 1);

    /* Unit= 3 [STREAM_ENG_V2 3] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_170 input ports=0 range=7[10776624,12005424] */

    static const LL_Streng_TensorInitTypeDef Reshape_170_dma_init_in_0_170 = {
      /* memory canonical to batch=1 */
      .dir = 0,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Conv2D_169_out_0 */
      .offset_start = 10776624,
      .offset_limit = 12005488,
      .frame_count = 0,
      .fwidth = 80,
      .fheight = 80,
      .batch_depth = 2,
      .batch_offset = 192,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 1228800,
      .frame_loop_cnt = 48,
      .frame_tot_cnt = 48,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(3, &Reshape_170_dma_init_in_0_170, 1);


    /* Dma input bandwidth from memory pools: */
    /* hyperRAM -> 2048000 */

    /* Dma output units from cycle: */
    /* Unit= 8 [STREAM_ENG_V2 8] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_180 output ports=0 range=10[0,819200] */

    static const LL_Streng_TensorInitTypeDef Concat_180_dma_init_out_0_170 = {
      /* to memory canonical from batch=64 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Concat_180_out_0 */
      .offset_start = 0,
      .offset_limit = 819264,
      .frame_count = 0,
      .fwidth = 40,
      .fheight = 40,
      .batch_depth = 128,
      .batch_offset = 512,
      .frame_offset = 256,
      .line_offset = 0,
      .loop_offset = 819200,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(8, &Concat_180_dma_init_out_0_170, 1);

    /* Unit= 5 [STREAM_ENG_V2 5] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_170 output ports=0 range=7[7499824,8728624] */

    static const LL_Streng_TensorInitTypeDef Reshape_170_dma_init_out_0_170 = {
      /* to memory canonical from batch=1 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Reshape_170_out_0 */
      .offset_start = 7499824,
      .offset_limit = 8728688,
      .frame_count = 0,
      .fwidth = 80,
      .fheight = 80,
      .batch_depth = 2,
      .batch_offset = 64,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 409600,
      .frame_loop_cnt = 16,
      .frame_tot_cnt = 48,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(5, &Reshape_170_dma_init_out_0_170, 1);


    /* Dma output bandwidth to memory pools: */
    /* cpuRAM2 <- 819200 */
    /* hyperRAM <- 1228800 */

    static const LL_Switch_InitTypeDef switch_init_in_170[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_180 OUT: in unit=STREAM_ENG_V2 8 in port=0 out unit=STREAM_ENG_V2 2 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 5, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_170 OUT: in unit=STREAM_ENG_V2 5 in port=0 out unit=STREAM_ENG_V2 3 out port=0 */
    };


    /* epoch=170 */
    LL_Switch_Init(switch_init_in_170, 2);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_170_all_units[] = {
      { {STRENG, 5} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_170_all_units, 4);

  }

  ec_trace_wait_epoch_end(0x120);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_170[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_180 OUT: in unit=STREAM_ENG_V2 8 in port=0 out unit=STREAM_ENG_V2 2 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 5, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_170 OUT: in unit=STREAM_ENG_V2 5 in port=0 out unit=STREAM_ENG_V2 3 out port=0 */
    };


    /* epoch=170 */
    LL_Switch_Deinit(switch_deinit_in_170, 2);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_170_all_units[] = {
      { {STRENG, 5} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_170_all_units, 4);

  }
  ec_trace_end_epoch(170);
  ec_trace_end_blob("_ec_blob_weed_detection_170");
}

void trace_ec__ec_blob_weed_detection_183(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_183");
  ec_trace_start_epoch(183);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_193 */
    /* node=Concat_193 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Identity node=Identity_inserted_id400 */
    /* node=Identity_inserted_id400 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 9 [STREAM_ENG_V2 9] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_193 input ports=0 range=7[8728624,9547824] */

    static const LL_Streng_TensorInitTypeDef Concat_193_dma_init_in_0_183 = {
      /* from memory with batch=64 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Mul_192_out_0 */
      .offset_start = 8728624,
      .offset_end = 9138224,
      .offset_limit = 9547888,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 409600,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(9, &Concat_193_dma_init_in_0_183, 1);

    /* Unit= 1 [STREAM_ENG_V2 1] */
    /* Emit conf for STREAM_ENG_V2 node=Identity_inserted_id400 input ports=0 range=7[7499824,8728624] */

    static const LL_Streng_TensorInitTypeDef Identity_inserted_id400_dma_init_in_0_183 = {
      /* from memory with batch=1 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Transpose_171_out_0_inserted_in400 */
      .offset_start = 7499824,
      .offset_end = 7504944,
      .offset_limit = 8728688,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 5120,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 240,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(1, &Identity_inserted_id400_dma_init_in_0_183, 1);


    /* Dma input bandwidth from memory pools: */
    /* hyperRAM -> 2048000 */

    /* Dma output units from cycle: */
    /* Unit= 0 [STREAM_ENG_V2 0] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_193 output ports=0 range=10[1228800,2048000] */

    static const LL_Streng_TensorInitTypeDef Concat_193_dma_init_out_0_183 = {
      /* to memory canonical from batch=64 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Concat_193_out_0 */
      .offset_start = 1228800,
      .offset_limit = 2048064,
      .frame_count = 0,
      .fwidth = 40,
      .fheight = 40,
      .batch_depth = 128,
      .batch_offset = 512,
      .frame_offset = 256,
      .line_offset = 0,
      .loop_offset = 819200,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(0, &Concat_193_dma_init_out_0_183, 1);

    /* Unit= 7 [STREAM_ENG_V2 7] */
    /* Emit conf for STREAM_ENG_V2 node=Identity_inserted_id400 output ports=0 range=10[0,1228800] */

    static const LL_Streng_TensorInitTypeDef Identity_inserted_id400_dma_init_out_0_183 = {
      /* to memory canonical from batch=1 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34100000UL) /* Equivalent hex address = 0x34100000UL */}, /* Transpose_171_out_0_inserted_out400 */
      .offset_start = 0,
      .offset_limit = 1228864,
      .frame_count = 0,
      .fwidth = 16,
      .fheight = 80,
      .batch_depth = 2,
      .batch_offset = 320,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 409600,
      .frame_loop_cnt = 80,
      .frame_tot_cnt = 240,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(7, &Identity_inserted_id400_dma_init_out_0_183, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM5 <- 81920 */
    /* npuRAM4 <- 458752 */
    /* npuRAM3 <- 458752 */
    /* cpuRAM2 <- 1048576 */

    static const LL_Switch_InitTypeDef switch_init_in_183[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_193 OUT: in unit=STREAM_ENG_V2 0 in port=0 out unit=STREAM_ENG_V2 9 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 1, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Identity_inserted_id400 OUT: in unit=STREAM_ENG_V2 7 in port=0 out unit=STREAM_ENG_V2 1 out port=0 */
    };


    /* epoch=183 */
    LL_Switch_Init(switch_init_in_183, 2);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_183_all_units[] = {
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
      { {STRENG, 1} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_183_all_units, 4);

  }

  ec_trace_wait_epoch_end(0x81);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_183[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_193 OUT: in unit=STREAM_ENG_V2 0 in port=0 out unit=STREAM_ENG_V2 9 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 1, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Identity_inserted_id400 OUT: in unit=STREAM_ENG_V2 7 in port=0 out unit=STREAM_ENG_V2 1 out port=0 */
    };


    /* epoch=183 */
    LL_Switch_Deinit(switch_deinit_in_183, 2);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_183_all_units[] = {
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
      { {STRENG, 1} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_183_all_units, 4);

  }
  ec_trace_end_epoch(183);
  ec_trace_end_blob("_ec_blob_weed_detection_183");
}

void trace_ec__ec_blob_weed_detection_200(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_200");
  ec_trace_start_epoch(200);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_208 */
    /* node=Concat_208 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Reshape node=Reshape_198 */
    /* node=Reshape_198 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Reshape node=Reshape_253 */
    /* node=Reshape_253 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 0 [STREAM_ENG_V2 0] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_208 input ports=0 range=1[0,409600] */

    static const LL_Streng_TensorInitTypeDef Concat_208_dma_init_in_0_200 = {
      /* from memory with batch=128 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Mul_207_out_0 */
      .offset_start = 0,
      .offset_end = 204800,
      .offset_limit = 409664,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 204800,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(0, &Concat_208_dma_init_in_0_200, 1);

    /* Unit= 8 [STREAM_ENG_V2 8] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_198 input ports=0 range=0[0,307200] */

    static const LL_Streng_TensorInitTypeDef Reshape_198_dma_init_in_0_200 = {
      /* memory canonical to batch=1 */
      .dir = 0,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34350000UL) /* Equivalent hex address = 0x34350000UL */}, /* Conv2D_197_out_0 */
      .offset_start = 0,
      .offset_limit = 307264,
      .frame_count = 0,
      .fwidth = 40,
      .fheight = 40,
      .batch_depth = 2,
      .batch_offset = 192,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 307200,
      .frame_loop_cnt = 48,
      .frame_tot_cnt = 48,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(8, &Reshape_198_dma_init_in_0_200, 1);

    /* Unit= 3 [STREAM_ENG_V2 3] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_253 input ports=0 range=7[7499824,8728624] */

    static const LL_Streng_TensorInitTypeDef Reshape_253_dma_init_in_0_200 = {
      /* memory canonical to batch=1 */
      .dir = 0,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Concat_252_out_0 */
      .offset_start = 7499824,
      .offset_limit = 8728688,
      .frame_count = 0,
      .fwidth = 16,
      .fheight = 80,
      .batch_depth = 2,
      .batch_offset = 320,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 409600,
      .frame_loop_cnt = 80,
      .frame_tot_cnt = 240,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(3, &Reshape_253_dma_init_in_0_200, 1);


    /* Dma input bandwidth from memory pools: */
    /* npuRAM6 -> 307200 */
    /* npuRAM5 -> 409600 */
    /* hyperRAM -> 1228800 */

    /* Dma output units from cycle: */
    /* Unit= 2 [STREAM_ENG_V2 2] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_208 output ports=0 range=2[0,409600] */

    static const LL_Streng_TensorInitTypeDef Concat_208_dma_init_out_0_200 = {
      /* to memory canonical from batch=128 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34270000UL) /* Equivalent hex address = 0x34270000UL */}, /* Concat_208_out_0 */
      .offset_start = 0,
      .offset_limit = 409664,
      .frame_count = 0,
      .fwidth = 20,
      .fheight = 20,
      .batch_depth = 256,
      .batch_offset = 1024,
      .frame_offset = 512,
      .line_offset = 0,
      .loop_offset = 409600,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(2, &Concat_208_dma_init_out_0_200, 1);

    /* Unit= 9 [STREAM_ENG_V2 9] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_198 output ports=0 range=3[0,307200] */

    static const LL_Streng_TensorInitTypeDef Reshape_198_dma_init_out_0_200 = {
      /* to memory canonical from batch=1 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34200000UL) /* Equivalent hex address = 0x34200000UL */}, /* Reshape_198_out_0 */
      .offset_start = 0,
      .offset_limit = 307264,
      .frame_count = 0,
      .fwidth = 40,
      .fheight = 40,
      .batch_depth = 2,
      .batch_offset = 64,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 102400,
      .frame_loop_cnt = 16,
      .frame_tot_cnt = 48,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(9, &Reshape_198_dma_init_out_0_200, 1);

    /* Unit= 7 [STREAM_ENG_V2 7] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_253 output ports=0 range=7[9112624,10341424] */

    static const LL_Streng_TensorInitTypeDef Reshape_253_dma_init_out_0_200 = {
      /* to memory with batch=1 */
      .dir = 1,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .cacheable = 1,
      .cache_allocate = 0,
      .addr_base = {(unsigned char *)(0x90000000UL) /* Equivalent hex address = 0x90000000UL */}, /* Reshape_253_out_0 */
      .offset_start = 9112624,
      .offset_end = 10341424,
      .offset_limit = 10341488,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 1228800,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 1,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(7, &Reshape_253_dma_init_out_0_200, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM4 <- 409600 */
    /* npuRAM3 <- 307200 */
    /* hyperRAM <- 1228800 */

    static const LL_Switch_InitTypeDef switch_init_in_200[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_208 OUT: in unit=STREAM_ENG_V2 2 in port=0 out unit=STREAM_ENG_V2 0 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_198 OUT: in unit=STREAM_ENG_V2 9 in port=0 out unit=STREAM_ENG_V2 8 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_253 OUT: in unit=STREAM_ENG_V2 7 in port=0 out unit=STREAM_ENG_V2 3 out port=0 */
    };


    /* epoch=200 */
    LL_Switch_Init(switch_init_in_200, 3);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_200_all_units[] = {
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_200_all_units, 6);

  }

  ec_trace_wait_epoch_end(0x284);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_200[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_208 OUT: in unit=STREAM_ENG_V2 2 in port=0 out unit=STREAM_ENG_V2 0 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_198 OUT: in unit=STREAM_ENG_V2 9 in port=0 out unit=STREAM_ENG_V2 8 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_253 OUT: in unit=STREAM_ENG_V2 7 in port=0 out unit=STREAM_ENG_V2 3 out port=0 */
    };


    /* epoch=200 */
    LL_Switch_Deinit(switch_deinit_in_200, 3);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_200_all_units[] = {
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_200_all_units, 6);

  }
  ec_trace_end_epoch(200);
  ec_trace_end_blob("_ec_blob_weed_detection_200");
}

void trace_ec__ec_blob_weed_detection_213(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_213");
  ec_trace_start_epoch(213);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Concat node=Concat_221 */
    /* node=Concat_221 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Identity node=Identity_inserted_id401 */
    /* node=Identity_inserted_id401 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 4 [STREAM_ENG_V2 4] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_221 input ports=0 range=1[0,409600] */

    static const LL_Streng_TensorInitTypeDef Concat_221_dma_init_in_0_213 = {
      /* from memory with batch=128 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Mul_220_out_0 */
      .offset_start = 0,
      .offset_end = 204800,
      .offset_limit = 409664,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 204800,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(4, &Concat_221_dma_init_in_0_213, 1);

    /* Unit= 9 [STREAM_ENG_V2 9] */
    /* Emit conf for STREAM_ENG_V2 node=Identity_inserted_id401 input ports=0 range=3[0,307200] */

    static const LL_Streng_TensorInitTypeDef Identity_inserted_id401_dma_init_in_0_213 = {
      /* from memory with batch=1 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34200000UL) /* Equivalent hex address = 0x34200000UL */}, /* Transpose_199_out_0_inserted_in401 */
      .offset_start = 0,
      .offset_end = 2560,
      .offset_limit = 307264,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 2560,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 120,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(9, &Identity_inserted_id401_dma_init_in_0_213, 1);


    /* Dma input bandwidth from memory pools: */
    /* npuRAM5 -> 409600 */
    /* npuRAM3 -> 307200 */

    /* Dma output units from cycle: */
    /* Unit= 2 [STREAM_ENG_V2 2] */
    /* Emit conf for STREAM_ENG_V2 node=Concat_221 output ports=0 range=2[0,409600] */

    static const LL_Streng_TensorInitTypeDef Concat_221_dma_init_out_0_213 = {
      /* to memory canonical from batch=128 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34270000UL) /* Equivalent hex address = 0x34270000UL */}, /* Concat_221_out_0 */
      .offset_start = 0,
      .offset_limit = 409664,
      .frame_count = 0,
      .fwidth = 20,
      .fheight = 20,
      .batch_depth = 256,
      .batch_offset = 1024,
      .frame_offset = 512,
      .line_offset = 0,
      .loop_offset = 409600,
      .frame_loop_cnt = 2,
      .frame_tot_cnt = 2,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(2, &Concat_221_dma_init_out_0_213, 1);

    /* Unit= 8 [STREAM_ENG_V2 8] */
    /* Emit conf for STREAM_ENG_V2 node=Identity_inserted_id401 output ports=0 range=0[0,307200] */

    static const LL_Streng_TensorInitTypeDef Identity_inserted_id401_dma_init_out_0_213 = {
      /* to memory canonical from batch=1 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34350000UL) /* Equivalent hex address = 0x34350000UL */}, /* Transpose_199_out_0_inserted_out401 */
      .offset_start = 0,
      .offset_limit = 307264,
      .frame_count = 0,
      .fwidth = 16,
      .fheight = 40,
      .batch_depth = 2,
      .batch_offset = 160,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 102400,
      .frame_loop_cnt = 40,
      .frame_tot_cnt = 120,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(8, &Identity_inserted_id401_dma_init_out_0_213, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM6 <- 307200 */
    /* npuRAM4 <- 409600 */

    static const LL_Switch_InitTypeDef switch_init_in_213[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 4, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_221 OUT: in unit=STREAM_ENG_V2 2 in port=0 out unit=STREAM_ENG_V2 4 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Identity_inserted_id401 OUT: in unit=STREAM_ENG_V2 8 in port=0 out unit=STREAM_ENG_V2 9 out port=0 */
    };


    /* epoch=213 */
    LL_Switch_Init(switch_init_in_213, 2);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_213_all_units[] = {
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
      { {STRENG, 4} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_213_all_units, 4);

  }

  ec_trace_wait_epoch_end(0x104);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_213[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 2, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 4, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Concat_221 OUT: in unit=STREAM_ENG_V2 2 in port=0 out unit=STREAM_ENG_V2 4 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 9, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Identity_inserted_id401 OUT: in unit=STREAM_ENG_V2 8 in port=0 out unit=STREAM_ENG_V2 9 out port=0 */
    };


    /* epoch=213 */
    LL_Switch_Deinit(switch_deinit_in_213, 2);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_213_all_units[] = {
      { {STRENG, 2} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
      { {STRENG, 4} }, /* STREAM_ENG_V2 */
      { {STRENG, 9} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_213_all_units, 4);

  }
  ec_trace_end_epoch(213);
  ec_trace_end_blob("_ec_blob_weed_detection_213");
}

void trace_ec__ec_blob_weed_detection_227(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_227");
  ec_trace_start_epoch(227);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Reshape node=Reshape_226 */
    /* node=Reshape_226 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Reshape node=Reshape_246 */
    /* node=Reshape_246 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 7 [STREAM_ENG_V2 7] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_226 input ports=0 range=2[307200,384000] */

    static const LL_Streng_TensorInitTypeDef Reshape_226_dma_init_in_0_227 = {
      /* memory canonical to batch=1 */
      .dir = 0,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34270000UL) /* Equivalent hex address = 0x34270000UL */}, /* Conv2D_225_out_0 */
      .offset_start = 307200,
      .offset_limit = 384064,
      .frame_count = 0,
      .fwidth = 20,
      .fheight = 20,
      .batch_depth = 2,
      .batch_offset = 192,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 76800,
      .frame_loop_cnt = 48,
      .frame_tot_cnt = 48,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(7, &Reshape_226_dma_init_in_0_227, 1);

    /* Unit= 8 [STREAM_ENG_V2 8] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_246 input ports=0 range=1[0,307200] */

    static const LL_Streng_TensorInitTypeDef Reshape_246_dma_init_in_0_227 = {
      /* memory canonical to batch=1 */
      .dir = 0,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Concat_245_out_0 */
      .offset_start = 0,
      .offset_limit = 307264,
      .frame_count = 0,
      .fwidth = 16,
      .fheight = 40,
      .batch_depth = 2,
      .batch_offset = 160,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 102400,
      .frame_loop_cnt = 40,
      .frame_tot_cnt = 120,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(8, &Reshape_246_dma_init_in_0_227, 1);


    /* Dma input bandwidth from memory pools: */
    /* npuRAM5 -> 307200 */
    /* npuRAM4 -> 76800 */

    /* Dma output units from cycle: */
    /* Unit= 0 [STREAM_ENG_V2 0] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_226 output ports=0 range=1[307200,384000] */

    static const LL_Streng_TensorInitTypeDef Reshape_226_dma_init_out_0_227 = {
      /* to memory canonical from batch=1 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Reshape_226_out_0 */
      .offset_start = 307200,
      .offset_limit = 384064,
      .frame_count = 0,
      .fwidth = 20,
      .fheight = 20,
      .batch_depth = 2,
      .batch_offset = 64,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 25600,
      .frame_loop_cnt = 16,
      .frame_tot_cnt = 48,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(0, &Reshape_226_dma_init_out_0_227, 1);

    /* Unit= 3 [STREAM_ENG_V2 3] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_246 output ports=0 range=2[0,307200] */

    static const LL_Streng_TensorInitTypeDef Reshape_246_dma_init_out_0_227 = {
      /* to memory with batch=1 */
      .dir = 1,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x34270000UL) /* Equivalent hex address = 0x34270000UL */}, /* Reshape_246_out_0 */
      .offset_start = 0,
      .offset_end = 307200,
      .offset_limit = 307264,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 307200,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 1,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(3, &Reshape_246_dma_init_out_0_227, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM5 <- 76800 */
    /* npuRAM4 <- 307200 */

    static const LL_Switch_InitTypeDef switch_init_in_227[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_226 OUT: in unit=STREAM_ENG_V2 0 in port=0 out unit=STREAM_ENG_V2 7 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_246 OUT: in unit=STREAM_ENG_V2 3 in port=0 out unit=STREAM_ENG_V2 8 out port=0 */
    };


    /* epoch=227 */
    LL_Switch_Init(switch_init_in_227, 2);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_227_all_units[] = {
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_227_all_units, 4);

  }

  ec_trace_wait_epoch_end(0x9);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_227[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 7, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_226 OUT: in unit=STREAM_ENG_V2 0 in port=0 out unit=STREAM_ENG_V2 7 out port=0 */
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_246 OUT: in unit=STREAM_ENG_V2 3 in port=0 out unit=STREAM_ENG_V2 8 out port=0 */
    };


    /* epoch=227 */
    LL_Switch_Deinit(switch_deinit_in_227, 2);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_227_all_units[] = {
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
      { {STRENG, 7} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_227_all_units, 4);

  }
  ec_trace_end_epoch(227);
  ec_trace_start_epoch(228);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Identity node=Identity_inserted_id402 */
    /* node=Identity_inserted_id402 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 3 [STREAM_ENG_V2 3] */
    /* Emit conf for STREAM_ENG_V2 node=Identity_inserted_id402 input ports=0 range=1[307200,384000] */

    static const LL_Streng_TensorInitTypeDef Identity_inserted_id402_dma_init_in_0_228 = {
      /* from memory with batch=1 */
      .dir = 0,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Transpose_227_out_0_inserted_in402 */
      .offset_start = 307200,
      .offset_end = 308480,
      .offset_limit = 384064,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 1280,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 60,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(3, &Identity_inserted_id402_dma_init_in_0_228, 1);


    /* Dma input bandwidth from memory pools: */
    /* npuRAM5 -> 76800 */

    /* Dma output units from cycle: */
    /* Unit= 5 [STREAM_ENG_V2 5] */
    /* Emit conf for STREAM_ENG_V2 node=Identity_inserted_id402 output ports=0 range=1[0,76800] */

    static const LL_Streng_TensorInitTypeDef Identity_inserted_id402_dma_init_out_0_228 = {
      /* to memory canonical from batch=1 */
      .dir = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Transpose_227_out_0_inserted_out402 */
      .offset_start = 0,
      .offset_limit = 76864,
      .frame_count = 0,
      .fwidth = 16,
      .fheight = 20,
      .batch_depth = 2,
      .batch_offset = 80,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 25600,
      .frame_loop_cnt = 20,
      .frame_tot_cnt = 60,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(5, &Identity_inserted_id402_dma_init_out_0_228, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM5 <- 76800 */

    static const LL_Switch_InitTypeDef switch_init_in_228[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 5, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Identity_inserted_id402 OUT: in unit=STREAM_ENG_V2 5 in port=0 out unit=STREAM_ENG_V2 3 out port=0 */
    };


    /* epoch=228 */
    LL_Switch_Init(switch_init_in_228, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_228_all_units[] = {
      { {STRENG, 5} }, /* STREAM_ENG_V2 */
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_228_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x20);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_228[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 5, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 3, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Identity_inserted_id402 OUT: in unit=STREAM_ENG_V2 5 in port=0 out unit=STREAM_ENG_V2 3 out port=0 */
    };


    /* epoch=228 */
    LL_Switch_Deinit(switch_deinit_in_228, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_228_all_units[] = {
      { {STRENG, 5} }, /* STREAM_ENG_V2 */
      { {STRENG, 3} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_228_all_units, 2);

  }
  ec_trace_end_epoch(228);
  ec_trace_end_blob("_ec_blob_weed_detection_227");
}

void trace_ec__ec_blob_weed_detection_238(void) {
  ec_trace_start_blob("_ec_blob_weed_detection_238");
  ec_trace_start_epoch(238);
  {
    /* Unit= 28 [NULL_UNIT 0] */
    /* kind=Reshape node=Reshape_239 */
    /* node=Reshape_239 satisfies input and output adjacency (DMA->DMA) and can be omitted */

    /* Dma inputs units to cycle: */
    /* Unit= 8 [STREAM_ENG_V2 8] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_239 input ports=0 range=1[0,76800] */

    static const LL_Streng_TensorInitTypeDef Reshape_239_dma_init_in_0_238 = {
      /* memory canonical to batch=1 */
      .dir = 0,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Concat_238_out_0 */
      .offset_start = 0,
      .offset_limit = 76864,
      .frame_count = 0,
      .fwidth = 16,
      .fheight = 20,
      .batch_depth = 2,
      .batch_offset = 80,
      .frame_offset = 4,
      .line_offset = 0,
      .loop_offset = 25600,
      .frame_loop_cnt = 20,
      .frame_tot_cnt = 60,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(8, &Reshape_239_dma_init_in_0_238, 1);


    /* Dma input bandwidth from memory pools: */
    /* npuRAM5 -> 76800 */

    /* Dma output units from cycle: */
    /* Unit= 0 [STREAM_ENG_V2 0] */
    /* Emit conf for STREAM_ENG_V2 node=Reshape_239 output ports=0 range=1[76800,153600] */

    static const LL_Streng_TensorInitTypeDef Reshape_239_dma_init_out_0_238 = {
      /* to memory with batch=1 */
      .dir = 1,
      .raw = 1,
      .noblk = 0,
      .align_right = 0,
      .nbits_unsigned = 0,
      .addr_base = {(unsigned char *)(0x342e0000UL) /* Equivalent hex address = 0x342e0000UL */}, /* Reshape_239_out_0 */
      .offset_start = 76800,
      .offset_end = 153600,
      .offset_limit = 153664,
      .frame_count = 0,
      .fwidth = 0,
      .fheight = 0,
      .batch_depth = 0,
      .batch_offset = 0,
      .frame_offset = 76800,
      .line_offset = 0,
      .loop_offset = 0,
      .frame_loop_cnt = 0,
      .frame_tot_cnt = 1,
      .nbits_in = 16,
      .nbits_out = 16,
    };

    /* Unit=STREAM_ENG_V2 */
    LL_Streng_TensorInit(0, &Reshape_239_dma_init_out_0_238, 1);


    /* Dma output bandwidth to memory pools: */
    /* npuRAM5 <- 76800 */

    static const LL_Switch_InitTypeDef switch_init_in_238[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_239 OUT: in unit=STREAM_ENG_V2 0 in port=0 out unit=STREAM_ENG_V2 8 out port=0 */
    };


    /* epoch=238 */
    LL_Switch_Init(switch_init_in_238, 1);

    static const LL_ATON_EnableUnits_InitTypeDef Enable_epoch_238_all_units[] = {
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_EnableUnits_Init(Enable_epoch_238_all_units, 2);

  }

  ec_trace_wait_epoch_end(0x1);

  {
    static const LL_Switch_DeinitTypeDef switch_deinit_in_238[] = {
      { LL_Switch_Init_Dest() = ATONN_DSTPORT(STRSWITCH, 0, STRENG, 0, 0), LL_Switch_Init_Source(0) = ATONN_SRCPORT(STRSWITCH, 0, STRENG, 8, 0), LL_Switch_Init_Context(0) = 1, LL_Switch_Init_Frames(0) = 0, }, /* Reshape_239 OUT: in unit=STREAM_ENG_V2 0 in port=0 out unit=STREAM_ENG_V2 8 out port=0 */
    };


    /* epoch=238 */
    LL_Switch_Deinit(switch_deinit_in_238, 1);

    static const LL_ATON_DisableUnits_InitTypeDef Disable_epoch_238_all_units[] = {
      { {STRENG, 0} }, /* STREAM_ENG_V2 */
      { {STRENG, 8} }, /* STREAM_ENG_V2 */
    };


    LL_ATON_DisableUnits_Init(Disable_epoch_238_all_units, 2);

  }
  ec_trace_end_epoch(238);
  ec_trace_end_blob("_ec_blob_weed_detection_238");
}


int main () {
  ec_trace_init("weed_detection_ecblobs.h", "weed_detection", false);
  trace_ec__ec_blob_weed_detection_1();
  trace_ec__ec_blob_weed_detection_21();
  trace_ec__ec_blob_weed_detection_48();
  trace_ec__ec_blob_weed_detection_82();
  trace_ec__ec_blob_weed_detection_102();
  trace_ec__ec_blob_weed_detection_118();
  trace_ec__ec_blob_weed_detection_125();
  trace_ec__ec_blob_weed_detection_127();
  trace_ec__ec_blob_weed_detection_140();
  trace_ec__ec_blob_weed_detection_147();
  trace_ec__ec_blob_weed_detection_149();
  trace_ec__ec_blob_weed_detection_162();
  trace_ec__ec_blob_weed_detection_170();
  trace_ec__ec_blob_weed_detection_183();
  trace_ec__ec_blob_weed_detection_200();
  trace_ec__ec_blob_weed_detection_213();
  trace_ec__ec_blob_weed_detection_227();
  trace_ec__ec_blob_weed_detection_238();
  ec_trace_all_blobs_done();
}
