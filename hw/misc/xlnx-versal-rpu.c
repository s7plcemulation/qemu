/*
 * QEMU model of the RPU Realtime Processing Unit
 *
 * Copyright (c) 2019 Xilinx Inc.
 *
 * Autogenerated by xregqemu.py 2019-02-15.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"
#include "hw/sysbus.h"
#include "hw/register.h"
#include "qemu/bitops.h"
#include "qemu/log.h"
#include "qapi/error.h"

#include "hw/fdt_generic_util.h"

#ifndef XILINX_VERSAL_RPU_ERR_DEBUG
#define XILINX_VERSAL_RPU_ERR_DEBUG 0
#endif

#define TYPE_XILINX_VERSAL_RPU "xlnx.versal-rpu"

#define XILINX_VERSAL_RPU(obj) \
     OBJECT_CHECK(RPU, (obj), TYPE_XILINX_VERSAL_RPU)

REG32(RPU_GLBL_CNTL, 0x0)
    FIELD(RPU_GLBL_CNTL, GIC_AXPROT, 10, 1)
    FIELD(RPU_GLBL_CNTL, TCM_CLK_CNTL, 8, 1)
    FIELD(RPU_GLBL_CNTL, TCM_WAIT, 7, 1)
    FIELD(RPU_GLBL_CNTL, TCM_COMB, 6, 1)
    FIELD(RPU_GLBL_CNTL, TEINIT, 5, 1)
    FIELD(RPU_GLBL_CNTL, SLCLAMP, 4, 1)
    FIELD(RPU_GLBL_CNTL, SLSPLIT, 3, 1)
    FIELD(RPU_GLBL_CNTL, DBGNOCLKSTOP, 2, 1)
    FIELD(RPU_GLBL_CNTL, CFGIE, 1, 1)
    FIELD(RPU_GLBL_CNTL, CFGEE, 0, 1)
REG32(RPU_GLBL_STATUS, 0x4)
    FIELD(RPU_GLBL_STATUS, DBGNOPWRDWN, 0, 1)
REG32(RPU_ERR_CNTL, 0x8)
    FIELD(RPU_ERR_CNTL, APB_ERR_RES, 0, 1)
REG32(RPU_ERR_INJ, 0x20)
    FIELD(RPU_ERR_INJ, DCCMINP2, 8, 8)
    FIELD(RPU_ERR_INJ, DCCMINP, 0, 8)
REG32(RPU_CCF_MASK, 0x24)
    FIELD(RPU_CCF_MASK, TEST_MBIST_MODE, 7, 1)
    FIELD(RPU_CCF_MASK, TEST_SCAN_MODE_LP, 6, 1)
    FIELD(RPU_CCF_MASK, TEST_SCAN_MODE, 5, 1)
    FIELD(RPU_CCF_MASK, ISO, 4, 1)
    FIELD(RPU_CCF_MASK, PGE, 3, 1)
    FIELD(RPU_CCF_MASK, R50_DBG_RST, 2, 1)
    FIELD(RPU_CCF_MASK, R50_RST, 1, 1)
    FIELD(RPU_CCF_MASK, PGE_RST, 0, 1)
REG32(RPU_INTR_0, 0x28)
REG32(RPU_INTR_1, 0x2c)
REG32(RPU_INTR_2, 0x30)
REG32(RPU_INTR_3, 0x34)
REG32(RPU_INTR_4, 0x38)
REG32(RPU_INTR_MASK_0, 0x40)
REG32(RPU_INTR_MASK_1, 0x44)
REG32(RPU_INTR_MASK_2, 0x48)
REG32(RPU_INTR_MASK_3, 0x4c)
REG32(RPU_INTR_MASK_4, 0x50)
REG32(RPU_CCF_VAL, 0x54)
    FIELD(RPU_CCF_VAL, TEST_MBIST_MODE, 7, 1)
    FIELD(RPU_CCF_VAL, TEST_SCAN_MODE_LP, 6, 1)
    FIELD(RPU_CCF_VAL, TEST_SCAN_MODE, 5, 1)
    FIELD(RPU_CCF_VAL, ISO, 4, 1)
    FIELD(RPU_CCF_VAL, PGE, 3, 1)
    FIELD(RPU_CCF_VAL, R50_DBG_RST, 2, 1)
    FIELD(RPU_CCF_VAL, R50_RST, 1, 1)
    FIELD(RPU_CCF_VAL, PGE_RST, 0, 1)
REG32(RPU_SAFETY_CHK, 0xf0)
REG32(RPU_0_CFG, 0x100)
    FIELD(RPU_0_CFG, CFGNMFI0, 3, 1)
    FIELD(RPU_0_CFG, VINITHI, 2, 1)
    FIELD(RPU_0_CFG, COHERENT, 1, 1)
    FIELD(RPU_0_CFG, NCPUHALT, 0, 1)
REG32(RPU_0_STATUS, 0x104)
    FIELD(RPU_0_STATUS, NVALRESET, 5, 1)
    FIELD(RPU_0_STATUS, NVALIRQ, 4, 1)
    FIELD(RPU_0_STATUS, NVALFIQ, 3, 1)
    FIELD(RPU_0_STATUS, NWFIPIPESTOPPED, 2, 1)
    FIELD(RPU_0_STATUS, NWFEPIPESTOPPED, 1, 1)
    FIELD(RPU_0_STATUS, NCLKSTOPPED, 0, 1)
REG32(RPU_0_PWRDWN, 0x108)
    FIELD(RPU_0_PWRDWN, EN, 0, 1)
REG32(RPU_0_ISR, 0x114)
    FIELD(RPU_0_ISR, FPUFC, 24, 1)
    FIELD(RPU_0_ISR, FPOFC, 23, 1)
    FIELD(RPU_0_ISR, FPIXC, 22, 1)
    FIELD(RPU_0_ISR, FPIOC, 21, 1)
    FIELD(RPU_0_ISR, FPIDC, 20, 1)
    FIELD(RPU_0_ISR, FPDZC, 19, 1)
    FIELD(RPU_0_ISR, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_0_ISR, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_0_ISR, TCM_LST_CE, 16, 1)
    FIELD(RPU_0_ISR, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_0_ISR, B1TCM_CE, 14, 1)
    FIELD(RPU_0_ISR, B0TCM_CE, 13, 1)
    FIELD(RPU_0_ISR, ATCM_CE, 12, 1)
    FIELD(RPU_0_ISR, B1TCM_UE, 11, 1)
    FIELD(RPU_0_ISR, B0TCM_UE, 10, 1)
    FIELD(RPU_0_ISR, ATCM_UE, 9, 1)
    FIELD(RPU_0_ISR, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_0_ISR, DDATA_FAT, 7, 1)
    FIELD(RPU_0_ISR, TCM_LST_FAT, 6, 1)
    FIELD(RPU_0_ISR, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_0_ISR, DDATA_CE, 4, 1)
    FIELD(RPU_0_ISR, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_0_ISR, IDATA_CE, 2, 1)
    FIELD(RPU_0_ISR, ITAG_CE, 1, 1)
    FIELD(RPU_0_ISR, APB_ERR, 0, 1)
REG32(RPU_0_IMR, 0x118)
    FIELD(RPU_0_IMR, FPUFC, 24, 1)
    FIELD(RPU_0_IMR, FPOFC, 23, 1)
    FIELD(RPU_0_IMR, FPIXC, 22, 1)
    FIELD(RPU_0_IMR, FPIOC, 21, 1)
    FIELD(RPU_0_IMR, FPIDC, 20, 1)
    FIELD(RPU_0_IMR, FPDZC, 19, 1)
    FIELD(RPU_0_IMR, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_0_IMR, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_0_IMR, TCM_LST_CE, 16, 1)
    FIELD(RPU_0_IMR, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_0_IMR, B1TCM_CE, 14, 1)
    FIELD(RPU_0_IMR, B0TCM_CE, 13, 1)
    FIELD(RPU_0_IMR, ATCM_CE, 12, 1)
    FIELD(RPU_0_IMR, B1TCM_UE, 11, 1)
    FIELD(RPU_0_IMR, B0TCM_UE, 10, 1)
    FIELD(RPU_0_IMR, ATCM_UE, 9, 1)
    FIELD(RPU_0_IMR, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_0_IMR, DDATA_FAT, 7, 1)
    FIELD(RPU_0_IMR, TCM_LST_FAT, 6, 1)
    FIELD(RPU_0_IMR, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_0_IMR, DDATA_CE, 4, 1)
    FIELD(RPU_0_IMR, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_0_IMR, IDATA_CE, 2, 1)
    FIELD(RPU_0_IMR, ITAG_CE, 1, 1)
    FIELD(RPU_0_IMR, APB_ERR, 0, 1)
REG32(RPU_0_IEN, 0x11c)
    FIELD(RPU_0_IEN, FPUFC, 24, 1)
    FIELD(RPU_0_IEN, FPOFC, 23, 1)
    FIELD(RPU_0_IEN, FPIXC, 22, 1)
    FIELD(RPU_0_IEN, FPIOC, 21, 1)
    FIELD(RPU_0_IEN, FPIDC, 20, 1)
    FIELD(RPU_0_IEN, FPDZC, 19, 1)
    FIELD(RPU_0_IEN, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_0_IEN, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_0_IEN, TCM_LST_CE, 16, 1)
    FIELD(RPU_0_IEN, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_0_IEN, B1TCM_CE, 14, 1)
    FIELD(RPU_0_IEN, B0TCM_CE, 13, 1)
    FIELD(RPU_0_IEN, ATCM_CE, 12, 1)
    FIELD(RPU_0_IEN, B1TCM_UE, 11, 1)
    FIELD(RPU_0_IEN, B0TCM_UE, 10, 1)
    FIELD(RPU_0_IEN, ATCM_UE, 9, 1)
    FIELD(RPU_0_IEN, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_0_IEN, DDATA_FAT, 7, 1)
    FIELD(RPU_0_IEN, TCM_LST_FAT, 6, 1)
    FIELD(RPU_0_IEN, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_0_IEN, DDATA_CE, 4, 1)
    FIELD(RPU_0_IEN, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_0_IEN, IDATA_CE, 2, 1)
    FIELD(RPU_0_IEN, ITAG_CE, 1, 1)
    FIELD(RPU_0_IEN, APB_ERR, 0, 1)
REG32(RPU_0_IDS, 0x120)
    FIELD(RPU_0_IDS, FPUFC, 24, 1)
    FIELD(RPU_0_IDS, FPOFC, 23, 1)
    FIELD(RPU_0_IDS, FPIXC, 22, 1)
    FIELD(RPU_0_IDS, FPIOC, 21, 1)
    FIELD(RPU_0_IDS, FPIDC, 20, 1)
    FIELD(RPU_0_IDS, FPDZC, 19, 1)
    FIELD(RPU_0_IDS, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_0_IDS, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_0_IDS, TCM_LST_CE, 16, 1)
    FIELD(RPU_0_IDS, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_0_IDS, B1TCM_CE, 14, 1)
    FIELD(RPU_0_IDS, B0TCM_CE, 13, 1)
    FIELD(RPU_0_IDS, ATCM_CE, 12, 1)
    FIELD(RPU_0_IDS, B1TCM_UE, 11, 1)
    FIELD(RPU_0_IDS, B0TCM_UE, 10, 1)
    FIELD(RPU_0_IDS, ATCM_UE, 9, 1)
    FIELD(RPU_0_IDS, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_0_IDS, DDATA_FAT, 7, 1)
    FIELD(RPU_0_IDS, TCM_LST_FAT, 6, 1)
    FIELD(RPU_0_IDS, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_0_IDS, DDATA_CE, 4, 1)
    FIELD(RPU_0_IDS, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_0_IDS, IDATA_CE, 2, 1)
    FIELD(RPU_0_IDS, ITAG_CE, 1, 1)
    FIELD(RPU_0_IDS, APB_ERR, 0, 1)
REG32(RPU_0_SLV_BASE, 0x124)
    FIELD(RPU_0_SLV_BASE, ADDR, 0, 8)
REG32(RPU_0_AXI_OVER, 0x128)
    FIELD(RPU_0_AXI_OVER, AWCACHE, 6, 4)
    FIELD(RPU_0_AXI_OVER, ARCACHE, 2, 4)
    FIELD(RPU_0_AXI_OVER, AWCACHE_EN, 1, 1)
    FIELD(RPU_0_AXI_OVER, ARCACHE_EN, 0, 1)
REG32(RPU_1_CFG, 0x200)
    FIELD(RPU_1_CFG, CFGNMFI1, 3, 1)
    FIELD(RPU_1_CFG, VINITHI, 2, 1)
    FIELD(RPU_1_CFG, COHERENT, 1, 1)
    FIELD(RPU_1_CFG, NCPUHALT, 0, 1)
REG32(RPU_1_STATUS, 0x204)
    FIELD(RPU_1_STATUS, NVALRESET, 5, 1)
    FIELD(RPU_1_STATUS, NVALIRQ, 4, 1)
    FIELD(RPU_1_STATUS, NVALFIQ, 3, 1)
    FIELD(RPU_1_STATUS, NWFIPIPESTOPPED, 2, 1)
    FIELD(RPU_1_STATUS, NWFEPIPESTOPPED, 1, 1)
    FIELD(RPU_1_STATUS, NCLKSTOPPED, 0, 1)
REG32(RPU_1_PWRDWN, 0x208)
    FIELD(RPU_1_PWRDWN, EN, 0, 1)
REG32(RPU_1_ISR, 0x214)
    FIELD(RPU_1_ISR, FPUFC, 24, 1)
    FIELD(RPU_1_ISR, FPOFC, 23, 1)
    FIELD(RPU_1_ISR, FPIXC, 22, 1)
    FIELD(RPU_1_ISR, FPIOC, 21, 1)
    FIELD(RPU_1_ISR, FPIDC, 20, 1)
    FIELD(RPU_1_ISR, FPDZC, 19, 1)
    FIELD(RPU_1_ISR, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_1_ISR, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_1_ISR, TCM_LST_CE, 16, 1)
    FIELD(RPU_1_ISR, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_1_ISR, B1TCM_CE, 14, 1)
    FIELD(RPU_1_ISR, B0TCM_CE, 13, 1)
    FIELD(RPU_1_ISR, ATCM_CE, 12, 1)
    FIELD(RPU_1_ISR, B1TCM_UE, 11, 1)
    FIELD(RPU_1_ISR, B0TCM_UE, 10, 1)
    FIELD(RPU_1_ISR, ATCM_UE, 9, 1)
    FIELD(RPU_1_ISR, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_1_ISR, DDATA_FAT, 7, 1)
    FIELD(RPU_1_ISR, TCM_LST_FAT, 6, 1)
    FIELD(RPU_1_ISR, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_1_ISR, DDATA_CE, 4, 1)
    FIELD(RPU_1_ISR, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_1_ISR, IDATA_CE, 2, 1)
    FIELD(RPU_1_ISR, ITAG_CE, 1, 1)
    FIELD(RPU_1_ISR, APB_ERR, 0, 1)
REG32(RPU_1_IMR, 0x218)
    FIELD(RPU_1_IMR, FPUFC, 24, 1)
    FIELD(RPU_1_IMR, FPOFC, 23, 1)
    FIELD(RPU_1_IMR, FPIXC, 22, 1)
    FIELD(RPU_1_IMR, FPIOC, 21, 1)
    FIELD(RPU_1_IMR, FPIDC, 20, 1)
    FIELD(RPU_1_IMR, FPDZC, 19, 1)
    FIELD(RPU_1_IMR, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_1_IMR, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_1_IMR, TCM_LST_CE, 16, 1)
    FIELD(RPU_1_IMR, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_1_IMR, B1TCM_CE, 14, 1)
    FIELD(RPU_1_IMR, B0TCM_CE, 13, 1)
    FIELD(RPU_1_IMR, ATCM_CE, 12, 1)
    FIELD(RPU_1_IMR, B1TCM_UE, 11, 1)
    FIELD(RPU_1_IMR, B0TCM_UE, 10, 1)
    FIELD(RPU_1_IMR, ATCM_UE, 9, 1)
    FIELD(RPU_1_IMR, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_1_IMR, DDATA_FAT, 7, 1)
    FIELD(RPU_1_IMR, TCM_LST_FAT, 6, 1)
    FIELD(RPU_1_IMR, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_1_IMR, DDATA_CE, 4, 1)
    FIELD(RPU_1_IMR, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_1_IMR, IDATA_CE, 2, 1)
    FIELD(RPU_1_IMR, ITAG_CE, 1, 1)
    FIELD(RPU_1_IMR, APB_ERR, 0, 1)
REG32(RPU_1_IEN, 0x21c)
    FIELD(RPU_1_IEN, FPUFC, 24, 1)
    FIELD(RPU_1_IEN, FPOFC, 23, 1)
    FIELD(RPU_1_IEN, FPIXC, 22, 1)
    FIELD(RPU_1_IEN, FPIOC, 21, 1)
    FIELD(RPU_1_IEN, FPIDC, 20, 1)
    FIELD(RPU_1_IEN, FPDZC, 19, 1)
    FIELD(RPU_1_IEN, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_1_IEN, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_1_IEN, TCM_LST_CE, 16, 1)
    FIELD(RPU_1_IEN, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_1_IEN, B1TCM_CE, 14, 1)
    FIELD(RPU_1_IEN, B0TCM_CE, 13, 1)
    FIELD(RPU_1_IEN, ATCM_CE, 12, 1)
    FIELD(RPU_1_IEN, B1TCM_UE, 11, 1)
    FIELD(RPU_1_IEN, B0TCM_UE, 10, 1)
    FIELD(RPU_1_IEN, ATCM_UE, 9, 1)
    FIELD(RPU_1_IEN, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_1_IEN, DDATA_FAT, 7, 1)
    FIELD(RPU_1_IEN, TCM_LST_FAT, 6, 1)
    FIELD(RPU_1_IEN, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_1_IEN, DDATA_CE, 4, 1)
    FIELD(RPU_1_IEN, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_1_IEN, IDATA_CE, 2, 1)
    FIELD(RPU_1_IEN, ITAG_CE, 1, 1)
    FIELD(RPU_1_IEN, APB_ERR, 0, 1)
REG32(RPU_1_IDS, 0x220)
    FIELD(RPU_1_IDS, FPUFC, 24, 1)
    FIELD(RPU_1_IDS, FPOFC, 23, 1)
    FIELD(RPU_1_IDS, FPIXC, 22, 1)
    FIELD(RPU_1_IDS, FPIOC, 21, 1)
    FIELD(RPU_1_IDS, FPIDC, 20, 1)
    FIELD(RPU_1_IDS, FPDZC, 19, 1)
    FIELD(RPU_1_IDS, TCM_ASLV_CE, 18, 1)
    FIELD(RPU_1_IDS, TCM_ASLV_FAT, 17, 1)
    FIELD(RPU_1_IDS, TCM_LST_CE, 16, 1)
    FIELD(RPU_1_IDS, TCM_PREFETCH_CE, 15, 1)
    FIELD(RPU_1_IDS, B1TCM_CE, 14, 1)
    FIELD(RPU_1_IDS, B0TCM_CE, 13, 1)
    FIELD(RPU_1_IDS, ATCM_CE, 12, 1)
    FIELD(RPU_1_IDS, B1TCM_UE, 11, 1)
    FIELD(RPU_1_IDS, B0TCM_UE, 10, 1)
    FIELD(RPU_1_IDS, ATCM_UE, 9, 1)
    FIELD(RPU_1_IDS, DTAG_DIRTY_FAT, 8, 1)
    FIELD(RPU_1_IDS, DDATA_FAT, 7, 1)
    FIELD(RPU_1_IDS, TCM_LST_FAT, 6, 1)
    FIELD(RPU_1_IDS, TCM_PREFETCH_FAT, 5, 1)
    FIELD(RPU_1_IDS, DDATA_CE, 4, 1)
    FIELD(RPU_1_IDS, DTAG_DIRTY_CE, 3, 1)
    FIELD(RPU_1_IDS, IDATA_CE, 2, 1)
    FIELD(RPU_1_IDS, ITAG_CE, 1, 1)
    FIELD(RPU_1_IDS, APB_ERR, 0, 1)
REG32(RPU_1_SLV_BASE, 0x224)
    FIELD(RPU_1_SLV_BASE, ADDR, 0, 8)
REG32(RPU_1_AXI_OVER, 0x228)
    FIELD(RPU_1_AXI_OVER, AWCACHE, 6, 4)
    FIELD(RPU_1_AXI_OVER, ARCACHE, 2, 4)
    FIELD(RPU_1_AXI_OVER, AWCACHE_EN, 1, 1)
    FIELD(RPU_1_AXI_OVER, ARCACHE_EN, 0, 1)

#define RPU_R_MAX (R_RPU_1_AXI_OVER + 1)

typedef struct RPU {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    MemoryRegion mr_R5[2];
    MemoryRegion mr_R5_alias[2];
    MemoryRegion tcm_A[2];
    MemoryRegion tcm_B[2];
    MemoryRegion tcm_A1_alias[2];
    MemoryRegion tcm_B1_alias[2];

    MemoryRegion icache[2];
    MemoryRegion dcache[2];

    qemu_irq irq_rpu_1_imr;
    qemu_irq irq_rpu_0_imr;

    bool r5_rst[2];
    qemu_irq halt[2];
    qemu_irq vinithi[2];

    struct {
        uint32_t tcm_size;
        uint32_t icache_size;
        uint32_t dcache_size;
    } cfg;

    uint32_t regs[RPU_R_MAX];
    RegisterInfo regs_info[RPU_R_MAX];
} RPU;

static void rpu_1_imr_update_irq(RPU *s)
{
    bool pending = s->regs[R_RPU_1_ISR] & ~s->regs[R_RPU_1_IMR];
    qemu_set_irq(s->irq_rpu_1_imr, pending);
}

static void rpu_1_isr_postw(RegisterInfo *reg, uint64_t val64)
{
    RPU *s = XILINX_VERSAL_RPU(reg->opaque);
    rpu_1_imr_update_irq(s);
}

static uint64_t rpu_1_ien_prew(RegisterInfo *reg, uint64_t val64)
{
    RPU *s = XILINX_VERSAL_RPU(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_1_IMR] &= ~val;
    rpu_1_imr_update_irq(s);
    return 0;
}

static uint64_t rpu_1_ids_prew(RegisterInfo *reg, uint64_t val64)
{
    RPU *s = XILINX_VERSAL_RPU(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_1_IMR] |= val;
    rpu_1_imr_update_irq(s);
    return 0;
}

static void rpu_0_imr_update_irq(RPU *s)
{
    bool pending = s->regs[R_RPU_0_ISR] & ~s->regs[R_RPU_0_IMR];
    qemu_set_irq(s->irq_rpu_0_imr, pending);
}

static void rpu_0_isr_postw(RegisterInfo *reg, uint64_t val64)
{
    RPU *s = XILINX_VERSAL_RPU(reg->opaque);
    rpu_0_imr_update_irq(s);
}

static uint64_t rpu_0_ien_prew(RegisterInfo *reg, uint64_t val64)
{
    RPU *s = XILINX_VERSAL_RPU(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_0_IMR] &= ~val;
    rpu_0_imr_update_irq(s);
    return 0;
}

static uint64_t rpu_0_ids_prew(RegisterInfo *reg, uint64_t val64)
{
    RPU *s = XILINX_VERSAL_RPU(reg->opaque);
    uint32_t val = val64;

    s->regs[R_RPU_0_IMR] |= val;
    rpu_0_imr_update_irq(s);
    return 0;
}

static void rpu_setup_tcm(RPU *s)
{
    bool sl_clamp;
    bool sl_split;
    bool tcm_combine;

    /* See page 26 of the DID.  */
    sl_clamp = ARRAY_FIELD_EX32(s->regs, RPU_GLBL_CNTL, SLCLAMP);
    sl_split = ARRAY_FIELD_EX32(s->regs, RPU_GLBL_CNTL, SLSPLIT);
    tcm_combine = ARRAY_FIELD_EX32(s->regs, RPU_GLBL_CNTL, TCM_COMB);

    qemu_log("%s: sl_clamp=%d sl_split=%d tcm_combine=%d\n",
             __func__, sl_clamp, sl_split, tcm_combine);

    if (tcm_combine) {
        memory_region_set_enabled(&s->tcm_A1_alias[0], true);
        memory_region_set_enabled(&s->tcm_A1_alias[1], false);
        memory_region_set_enabled(&s->tcm_B1_alias[0], true);
        memory_region_set_enabled(&s->tcm_B1_alias[1], false);
    } else {
        memory_region_set_enabled(&s->tcm_A1_alias[0], false);
        memory_region_set_enabled(&s->tcm_A1_alias[1], true);
        memory_region_set_enabled(&s->tcm_B1_alias[0], false);
        memory_region_set_enabled(&s->tcm_B1_alias[1], true);
    }

    /* Catch a few invalid combinations.  */
    if (sl_split) {
        if (sl_clamp) {
            qemu_log_mask(LOG_GUEST_ERROR, "slclamp set in split mode!\n");
        }
    } else {
        if (!sl_clamp) {
            qemu_log_mask(LOG_GUEST_ERROR,
                          "slclamp not set in lock-step mode!\n");
        }
    }
}

#define PROPAGATE_GPIO(reg, f, irq) {             \
    bool val = ARRAY_FIELD_EX32(s->regs, reg, f); \
    qemu_set_irq(irq, val);                       \
}

static void rpu_update_gpios(RPU *s)
{
    bool sl_split;
    bool ncpuhalt[2];
    int i;

    sl_split = ARRAY_FIELD_EX32(s->regs, RPU_GLBL_CNTL, SLSPLIT);

    ncpuhalt[0] = ARRAY_FIELD_EX32(s->regs, RPU_0_CFG, NCPUHALT);
    ncpuhalt[1] = ARRAY_FIELD_EX32(s->regs, RPU_1_CFG, NCPUHALT);

    for (i = 0; i < ARRAY_SIZE(ncpuhalt); i++) {
        bool halt;

        /* Sleep if halted or in reset.  */
        halt = !ncpuhalt[i];
        halt |= s->r5_rst[i];

        if (i == 1 && !sl_split) {
            /* In lockstep mode we only run core0.  */
            halt = true;
        }

        qemu_log_mask(CPU_LOG_RESET,
                      "r5 halt[%d]=%d rst=%d ncpuhalt=%d sl_split=%d\n",
                      i, halt, s->r5_rst[i], ncpuhalt[i], sl_split);
        qemu_set_irq(s->halt[i], halt);
    }

    PROPAGATE_GPIO(RPU_0_CFG, VINITHI, s->vinithi[0]);
    PROPAGATE_GPIO(RPU_1_CFG, VINITHI, s->vinithi[1]);
}

static void rpu_update_gpios_pw(RegisterInfo *reg, uint64_t val64)
{
    RPU *s = XILINX_VERSAL_RPU(reg->opaque);
    rpu_update_gpios(s);
}

static void rpu_glbl_cntl_pw(RegisterInfo *reg, uint64_t val64)
{
    RPU *s = XILINX_VERSAL_RPU(reg->opaque);

    rpu_setup_tcm(s);
    rpu_update_gpios(s);
}

static const RegisterAccessInfo rpu_regs_info[] = {
    {   .name = "RPU_GLBL_CNTL",  .addr = A_RPU_GLBL_CNTL,
        .reset = 0x50,
        .rsvd = 0xfffffa00,
        .post_write = rpu_glbl_cntl_pw,
    },{ .name = "RPU_GLBL_STATUS",  .addr = A_RPU_GLBL_STATUS,
        .rsvd = 0xfffffffe,
        .ro = 0x1,
    },{ .name = "RPU_ERR_CNTL",  .addr = A_RPU_ERR_CNTL,
        .rsvd = 0xfffffffe,
    },{ .name = "RPU_ERR_INJ",  .addr = A_RPU_ERR_INJ,
        .rsvd = 0xffff0000,
    },{ .name = "RPU_CCF_MASK",  .addr = A_RPU_CCF_MASK,
        .rsvd = 0xffffff00,
    },{ .name = "RPU_INTR_0",  .addr = A_RPU_INTR_0,
    },{ .name = "RPU_INTR_1",  .addr = A_RPU_INTR_1,
    },{ .name = "RPU_INTR_2",  .addr = A_RPU_INTR_2,
    },{ .name = "RPU_INTR_3",  .addr = A_RPU_INTR_3,
    },{ .name = "RPU_INTR_4",  .addr = A_RPU_INTR_4,
    },{ .name = "RPU_INTR_MASK_0",  .addr = A_RPU_INTR_MASK_0,
    },{ .name = "RPU_INTR_MASK_1",  .addr = A_RPU_INTR_MASK_1,
    },{ .name = "RPU_INTR_MASK_2",  .addr = A_RPU_INTR_MASK_2,
    },{ .name = "RPU_INTR_MASK_3",  .addr = A_RPU_INTR_MASK_3,
    },{ .name = "RPU_INTR_MASK_4",  .addr = A_RPU_INTR_MASK_4,
    },{ .name = "RPU_CCF_VAL",  .addr = A_RPU_CCF_VAL,
        .reset = 0x7,
        .rsvd = 0xffffff00,
    },{ .name = "RPU_SAFETY_CHK",  .addr = A_RPU_SAFETY_CHK,
    },{ .name = "RPU_0_CFG",  .addr = A_RPU_0_CFG,
        .reset = 0x5,
        .rsvd = 0xfffffff0,
        .post_write = rpu_update_gpios_pw,
    },{ .name = "RPU_0_STATUS",  .addr = A_RPU_0_STATUS,
        .reset = 0x3f,
        .rsvd = 0xffffffc0,
        .ro = 0x3f,
    },{ .name = "RPU_0_PWRDWN",  .addr = A_RPU_0_PWRDWN,
        .rsvd = 0xfffffffe,
    },{ .name = "RPU_0_ISR",  .addr = A_RPU_0_ISR,
        .rsvd = 0xfe000000,
        .w1c = 0x1ffffff,
        .post_write = rpu_0_isr_postw,
    },{ .name = "RPU_0_IMR",  .addr = A_RPU_0_IMR,
        .reset = 0x1ffffff,
        .rsvd = 0xfe000000,
        .ro = 0x1ffffff,
    },{ .name = "RPU_0_IEN",  .addr = A_RPU_0_IEN,
        .rsvd = 0xfe000000,
        .pre_write = rpu_0_ien_prew,
    },{ .name = "RPU_0_IDS",  .addr = A_RPU_0_IDS,
        .rsvd = 0xfe000000,
        .pre_write = rpu_0_ids_prew,
    },{ .name = "RPU_0_SLV_BASE",  .addr = A_RPU_0_SLV_BASE,
        .rsvd = 0xffffff00,
    },{ .name = "RPU_0_AXI_OVER",  .addr = A_RPU_0_AXI_OVER,
        .rsvd = 0xfffffc00,
    },{ .name = "RPU_1_CFG",  .addr = A_RPU_1_CFG,
        .reset = 0x5,
        .rsvd = 0xfffffff0,
        .post_write = rpu_update_gpios_pw,
    },{ .name = "RPU_1_STATUS",  .addr = A_RPU_1_STATUS,
        .reset = 0x3f,
        .rsvd = 0xffffffc0,
        .ro = 0x3f,
    },{ .name = "RPU_1_PWRDWN",  .addr = A_RPU_1_PWRDWN,
        .rsvd = 0xfffffffe,
    },{ .name = "RPU_1_ISR",  .addr = A_RPU_1_ISR,
        .rsvd = 0xfe000000,
        .w1c = 0x1ffffff,
        .post_write = rpu_1_isr_postw,
    },{ .name = "RPU_1_IMR",  .addr = A_RPU_1_IMR,
        .reset = 0x1ffffff,
        .rsvd = 0xfe000000,
        .ro = 0x1ffffff,
    },{ .name = "RPU_1_IEN",  .addr = A_RPU_1_IEN,
        .rsvd = 0xfe000000,
        .pre_write = rpu_1_ien_prew,
    },{ .name = "RPU_1_IDS",  .addr = A_RPU_1_IDS,
        .rsvd = 0xfe000000,
        .pre_write = rpu_1_ids_prew,
    },{ .name = "RPU_1_SLV_BASE",  .addr = A_RPU_1_SLV_BASE,
        .rsvd = 0xffffff00,
    },{ .name = "RPU_1_AXI_OVER",  .addr = A_RPU_1_AXI_OVER,
        .rsvd = 0xfffffc00,
    }
};

static void rpu_reset(DeviceState *dev)
{
    RPU *s = XILINX_VERSAL_RPU(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    rpu_1_imr_update_irq(s);
    rpu_0_imr_update_irq(s);

    rpu_update_gpios(s);
}

static void rpu_handle_gpio_in(void *opaque, int irq, int level)
{
    RPU *s = XILINX_VERSAL_RPU(opaque);

    switch (irq) {
    case 0 ... 1:
        s->r5_rst[irq] = level;
        break;
    case 2:
        ARRAY_FIELD_DP32(s->regs, RPU_0_STATUS, NWFIPIPESTOPPED, !level);
        break;
    case 3:
        ARRAY_FIELD_DP32(s->regs, RPU_1_STATUS, NWFIPIPESTOPPED, !level);
        break;
    default:
        g_assert_not_reached();
    }
    rpu_update_gpios(s);
}

static const MemoryRegionOps rpu_ops = {
    .read = register_read_memory,
    .write = register_write_memory,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void rpu_realize(DeviceState *dev, Error **errp)
{
    RPU *s = XILINX_VERSAL_RPU(dev);
    char *name;
    int i;

    /* There's two R5 views we need to construct here.
     * R5_0 and R5_1.
     *
     * Each R5 has two TCM's, A and B. When TCM combine
     * is off, they both see their own respective A
     * and B TCM's with a hole in between. When combined
     * the full 256KB is accessible to R5_0 contigously.
     *
     * R5_0 (non-combined):
     * 0x00000 - 0x10000  ATCM0
     * 0x10000 - 0x20000  N/A
     * 0x20000 - 0x30000  BTCM0
     * 0x30000 - 0x50000  N/A
     *
     * R5_1 (non-combined):
     * 0x00000 - 0x10000  ATCM1
     * 0x10000 - 0x20000  N/A
     * 0x20000 - 0x30000  BTCM1
     * 0x30000 - 0x50000  N/A
     *
     * R5_0 (combined):
     * 0x00000 - 0x10000  ATCM0
     * 0x10000 - 0x20000  ATCM1
     * 0x20000 - 0x30000  BTCM0
     * 0x30000 - 0x40000  BTCM1
     *
     * R5_1 (combined):
     * 0x00000 - 0x10000  N/A
     * 0x10000 - 0x20000  N/A
     * 0x20000 - 0x30000  N/A
     * 0x30000 - 0x40000  N/A
     *
     */


    for (i = 0; i < ARRAY_SIZE(s->tcm_A); i++) {
        name = g_strdup_printf("mr-R5_%d", i);
        memory_region_init(&s->mr_R5[i], OBJECT(dev),
                           name,
                           s->cfg.tcm_size * 6);
        g_free(name);

        name = g_strdup_printf("tcm_A%d", i);
        memory_region_init_ram(&s->tcm_A[i], OBJECT(dev),
                               name, s->cfg.tcm_size, &error_fatal);
        g_free(name);

        name = g_strdup_printf("tcm_B%d", i);
        memory_region_init_ram(&s->tcm_B[i], OBJECT(dev),
                               name, s->cfg.tcm_size, &error_fatal);
        g_free(name);

        name = g_strdup_printf("icache%d", i);
        memory_region_init_ram(&s->icache[i], OBJECT(dev),
                               name, s->cfg.icache_size, &error_fatal);
        g_free(name);

        name = g_strdup_printf("dcache%d", i);
        memory_region_init_ram(&s->dcache[i], OBJECT(dev),
                               name, s->cfg.dcache_size, &error_fatal);
        g_free(name);

        name = g_strdup_printf("mr-R5_%d-alias", i);
        memory_region_init_alias(&s->mr_R5_alias[i], OBJECT(dev),
                                 name, &s->mr_R5[i], 0x0, s->cfg.tcm_size * 6);
        g_free(name);

        sysbus_init_mmio(SYS_BUS_DEVICE(dev), &s->mr_R5[i]);
        sysbus_init_mmio(SYS_BUS_DEVICE(dev), &s->mr_R5_alias[i]);
    }

    for (i = 0; i < ARRAY_SIZE(s->tcm_A1_alias); i++) {
        name = g_strdup_printf("tcm_A1-%d-alias", i);
        memory_region_init_alias(&s->tcm_A1_alias[i], OBJECT(dev),
                                 name, &s->tcm_A[1], 0x0, s->cfg.tcm_size);
        g_free(name);

        name = g_strdup_printf("tcm_B1-%d-alias", i);
        memory_region_init_alias(&s->tcm_B1_alias[i], OBJECT(dev),
                                 name, &s->tcm_B[1], 0x0, s->cfg.tcm_size);
        g_free(name);
    }

    /* See page 28 of the DID.  */
    memory_region_add_subregion_overlap(&s->mr_R5[0], 0x0,
                                        &s->tcm_A[0], 0);
    memory_region_add_subregion_overlap(&s->mr_R5[0], s->cfg.tcm_size * 1,
                                        &s->tcm_A1_alias[0], 0);
    memory_region_add_subregion_overlap(&s->mr_R5[0], s->cfg.tcm_size * 2,
                                        &s->tcm_B[0], 0);
    memory_region_add_subregion_overlap(&s->mr_R5[0], s->cfg.tcm_size * 3,
                                        &s->tcm_B1_alias[0], 0);
    memory_region_add_subregion_overlap(&s->mr_R5[0], s->cfg.tcm_size * 4,
                                        &s->icache[0], 0);
    memory_region_add_subregion_overlap(&s->mr_R5[0], s->cfg.tcm_size * 5,
                                        &s->dcache[0], 0);

    memory_region_add_subregion_overlap(&s->mr_R5[1], 0x0,
                                        &s->tcm_A1_alias[1], 0);
    memory_region_add_subregion_overlap(&s->mr_R5[1], s->cfg.tcm_size * 2,
                                        &s->tcm_B1_alias[1], 0);
    memory_region_add_subregion_overlap(&s->mr_R5[1], s->cfg.tcm_size * 4,
                                        &s->icache[1], 0);
    memory_region_add_subregion_overlap(&s->mr_R5[1], s->cfg.tcm_size * 5,
                                        &s->dcache[1], 0);
}

static void rpu_init(Object *obj)
{
    RPU *s = XILINX_VERSAL_RPU(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;

    memory_region_init(&s->iomem, obj, TYPE_XILINX_VERSAL_RPU, RPU_R_MAX * 4);
    reg_array =
        register_init_block32(DEVICE(obj), rpu_regs_info,
                              ARRAY_SIZE(rpu_regs_info),
                              s->regs_info, s->regs,
                              &rpu_ops,
                              XILINX_VERSAL_RPU_ERR_DEBUG,
                              RPU_R_MAX * 4);
    memory_region_add_subregion(&s->iomem,
                                0x0,
                                &reg_array->mem);
    sysbus_init_mmio(sbd, &s->iomem);

    sysbus_init_irq(sbd, &s->irq_rpu_1_imr);
    sysbus_init_irq(sbd, &s->irq_rpu_0_imr);

    qdev_init_gpio_out_named(DEVICE(obj), s->halt, "halt", 2);
    qdev_init_gpio_in(DEVICE(obj), rpu_handle_gpio_in, 4);
}

static const VMStateDescription vmstate_rpu = {
    .name = TYPE_XILINX_VERSAL_RPU,
    .version_id = 1,
    .minimum_version_id = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, RPU, RPU_R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static const FDTGenericGPIOSet crl_gpios[] = {
    {
      .names = &fdt_generic_gpio_name_set_gpio,
      .gpios = (FDTGenericGPIOConnection[]) {
        { .name = "halt", .fdt_index = 0, .range = 2 },
        { },
      },
    },
    { },
};

static Property rpu_properties[] = {
    DEFINE_PROP_UINT32("tcm-size", RPU, cfg.tcm_size, 64 * 1024),
    DEFINE_PROP_UINT32("icache-size", RPU, cfg.icache_size, 64 * 1024),
    DEFINE_PROP_UINT32("dcache-size", RPU, cfg.dcache_size, 64 * 1024),
    DEFINE_PROP_END_OF_LIST(),
};

static void rpu_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    FDTGenericGPIOClass *fggc = FDT_GENERIC_GPIO_CLASS(klass);

    dc->reset = rpu_reset;
    dc->realize = rpu_realize;
    dc->vmsd = &vmstate_rpu;
    dc->props = rpu_properties;
    fggc->controller_gpios = crl_gpios;
}

static const TypeInfo rpu_info = {
    .name          = TYPE_XILINX_VERSAL_RPU,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(RPU),
    .class_init    = rpu_class_init,
    .instance_init = rpu_init,
    .interfaces = (InterfaceInfo[]) {
        { TYPE_FDT_GENERIC_GPIO },
        { }
    },
};

static void rpu_register_types(void)
{
    type_register_static(&rpu_info);
}

type_init(rpu_register_types)
