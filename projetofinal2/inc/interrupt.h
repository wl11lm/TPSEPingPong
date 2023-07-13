#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "gpio.h"
#include "timer.h"

typedef enum _endnameInterrupt{
	A,
	B
}endnameInterrupt;

#define INTCPS                 0x48200000
#define INTC_REVISION          0x0
#define INTC_SYSCONFIG         0x10
#define INTC_SYSSTATUS         0x14
#define INTC_SIR_IRQ           0x40
#define INTC_SIR_FIQ           0x44
#define INTC_CONTROL           0x48
#define INTC_PROTECTION        0x4C
#define INTC_IDLE              0x50
#define INTC_IRQ_PRIORITY      0x60
#define INTC_FIQ_PRIORITY      0x64
#define INTC_THRESHOLD         0x68
#define INTC_ITR0              0x80
#define INTC_MIR0              0x84
#define INTC_MIR_CLEAR0        0x88
#define INTC_MIR_SET0          0x8C
#define INTC_ISR_SET0          0x90
#define INTC_ISR_CLEAR0        0x94
#define INTC_PENDING_IRQ0      0x98
#define INTC_PENDING_FIQ0      0x9C
#define INTC_ITR1              0xA0
#define INTC_MIR1              0xA4
#define INTC_MIR_CLEAR1        0xA8
#define INTC_MIR_SET1          0xAC
#define INTC_ISR_SET1          0xB0
#define INTC_ISR_CLEAR1        0xB4
#define INTC_PENDING_IRQ1      0xB8
#define INTC_PENDING_FIQ1      0xBC
#define INTC_ITR2              0xC0
#define INTC_MIR2              0xC4
#define INTC_MIR_CLEAR2        0xC8
#define INTC_MIR_SET2          0xCC
#define INTC_ISR_SET2          0xD0
#define INTC_ISR_CLEAR2        0xD4
#define INTC_PENDING_IRQ2      0xD8
#define INTC_PENDING_FIQ2      0xDC
#define INTC_ITR3              0xE0
#define INTC_MIR3              0xE4
#define INTC_MIR_CLEAR3        0xE8
#define INTC_MIR_SET3          0xEC
#define INTC_ISR_SET3          0xF0
#define INTC_ISR_CLEAR3        0xF4
#define INTC_PENDING_IRQ3      0xF8
#define INTC_PENDING_FIQ3      0xFC

#define INTC_ILR_0     0x100
#define INTC_ILR_1     0x104
#define INTC_ILR_2     0x108
#define INTC_ILR_3     0x10C
#define INTC_ILR_4     0x110
#define INTC_ILR_5     0x114
#define INTC_ILR_6     0x118
#define INTC_ILR_7     0x11C
#define INTC_ILR_8     0x120
#define INTC_ILR_9     0x124
#define INTC_ILR_10    0x128
#define INTC_ILR_11    0x12C
#define INTC_ILR_12    0x130
#define INTC_ILR_13    0x134
#define INTC_ILR_14    0x138
#define INTC_ILR_15    0x13C
#define INTC_ILR_16    0x140
#define INTC_ILR_17    0x144
#define INTC_ILR_18    0x148
#define INTC_ILR_19    0x14C
#define INTC_ILR_20    0x150
#define INTC_ILR_21    0x154
#define INTC_ILR_22    0x158
#define INTC_ILR_23    0x15C
#define INTC_ILR_24    0x160
#define INTC_ILR_25    0x164
#define INTC_ILR_26    0x168
#define INTC_ILR_27    0x16C
#define INTC_ILR_28    0x170
#define INTC_ILR_29    0x174
#define INTC_ILR_30    0x178
#define INTC_ILR_31    0x17C
#define INTC_ILR_32    0x180
#define INTC_ILR_33    0x184
#define INTC_ILR_34    0x188
#define INTC_ILR_35    0x18C
#define INTC_ILR_36    0x190
#define INTC_ILR_37    0x194
#define INTC_ILR_38    0x198
#define INTC_ILR_39    0x19C
#define INTC_ILR_40    0x1A0
#define INTC_ILR_41    0x1A4
#define INTC_ILR_42    0x1A8
#define INTC_ILR_43    0x1AC
#define INTC_ILR_44    0x1B0
#define INTC_ILR_45    0x1B4
#define INTC_ILR_46    0x1B8
#define INTC_ILR_47    0x1BC
#define INTC_ILR_48    0x1C0
#define INTC_ILR_49    0x1C4
#define INTC_ILR_50    0x1C8
#define INTC_ILR_51    0x1CC
#define INTC_ILR_52    0x1D0
#define INTC_ILR_53    0x1D4
#define INTC_ILR_54    0x1D8
#define INTC_ILR_55    0x1DC
#define INTC_ILR_56    0x1E0
#define INTC_ILR_57    0x1E4
#define INTC_ILR_58    0x1E8
#define INTC_ILR_59    0x1EC
#define INTC_ILR_60    0x1F0
#define INTC_ILR_61    0x1F4
#define INTC_ILR_62    0x1F8
#define INTC_ILR_63    0x1FC
#define INTC_ILR_64    0x200
#define INTC_ILR_65    0x204
#define INTC_ILR_66    0x208
#define INTC_ILR_67    0x20C
#define INTC_ILR_68    0x210
#define INTC_ILR_69    0x214
#define INTC_ILR_70    0x218
#define INTC_ILR_71    0x21C
#define INTC_ILR_72    0x220
#define INTC_ILR_73    0x224
#define INTC_ILR_74    0x228
#define INTC_ILR_75    0x22C
#define INTC_ILR_76    0x230
#define INTC_ILR_77    0x234
#define INTC_ILR_78    0x238
#define INTC_ILR_79    0x23C
#define INTC_ILR_80    0x240
#define INTC_ILR_81    0x244
#define INTC_ILR_82    0x248
#define INTC_ILR_83    0x24C
#define INTC_ILR_84    0x250
#define INTC_ILR_85    0x254
#define INTC_ILR_86    0x258
#define INTC_ILR_87    0x25C
#define INTC_ILR_88    0x260
#define INTC_ILR_89    0x264
#define INTC_ILR_90    0x268
#define INTC_ILR_91    0x26C
#define INTC_ILR_92    0x270
#define INTC_ILR_93    0x274
#define INTC_ILR_94    0x278
#define INTC_ILR_95    0x27C
#define INTC_ILR_96    0x280
#define INTC_ILR_97    0x284
#define INTC_ILR_98    0x288
#define INTC_ILR_99    0x28C
#define INTC_ILR_100   0x290
#define INTC_ILR_101   0x294
#define INTC_ILR_102   0x298
#define INTC_ILR_103   0x29C
#define INTC_ILR_104   0x2A0
#define INTC_ILR_105   0x2A4
#define INTC_ILR_106   0x2A8
#define INTC_ILR_107   0x2AC
#define INTC_ILR_108   0x2B0
#define INTC_ILR_109   0x2B4
#define INTC_ILR_110   0x2B8
#define INTC_ILR_111   0x2BC
#define INTC_ILR_112   0x2C0
#define INTC_ILR_113   0x2C4
#define INTC_ILR_114   0x2C8
#define INTC_ILR_115   0x2CC
#define INTC_ILR_116   0x2D0
#define INTC_ILR_117   0x2D4
#define INTC_ILR_118   0x2D8
#define INTC_ILR_119   0x2DC
#define INTC_ILR_120   0x2E0
#define INTC_ILR_121   0x2E4
#define INTC_ILR_122   0x2E8
#define INTC_ILR_123   0x2EC
#define INTC_ILR_124   0x2F0
#define INTC_ILR_125   0x2F4
#define INTC_ILR_126   0x2F8
#define INTC_ILR_127   0x2FC

#define GPIOINT0A       96u
#define GPIOINT0B       97u

#define GPIOINT1A       98u
#define GPIOINT1B       99u

#define GPIOINT2A       32u
#define GPIOINT2B       33u

#define GPIOINT3A       62u
#define GPIOINT3B       63u

void gpioInterruptInit(gpioMod gpio, ucPinNumber pin, endnameInterrupt name);
void gpioIrqInitBtn(gpioMod gpio, ucPinNumber pin);
void gpioIsrConfig(gpioMod mod, endnameInterrupt name);
void gpioSetInterrupt(gpioMod gpio, ucPinNumber pin);
void gpioEnableInterrupt(gpioMod gpio, ucPinNumber pin);
void gpioIsrHandler(gpioMod mod, ucPinNumber pin);
void ISR_Handler();
bool flagGet(gpioMod mod, ucPinNumber pin);
void flagSetFalse(gpioMod mod, ucPinNumber pin);

//TIMER BELOW
// #define TIMER_1MS_COUNT         0x5DC0u
// #define TIMER_OVERFLOW          0xFFFFFFFFu
// #define SOC_DMTIMER_7_REGS      0x4804A000

#define TIDR                    0x0
#define TIOCP_CFG               0x10
#define IRQ_EOI                 0x20
#define IRQSTATUS_RAW           0x24
#define IRQSTATUS               0x28
#define IRQENABLE_SET           0x2C
#define IRQENABLE_CLR           0x30
#define IRQWAKEEN               0x34
#define TCLR                    0x38
#define TCRR                    0x3C
#define TLDR                    0x40
#define TTGR                    0x44
#define TWPS                    0x48
#define TMAR                    0x4C
#define TCAR1                   0x50
#define TSICR                   0x54
#define TCAR2                   0x58



void timerIrqHandler(void);


/*#define EMUINT 0x0
#define COMMTX 0x1
#define COMMRX 0x2
#define BENCH 0x3
#define ELM_IRQ 0x4
#define SSM_WFI_IRQ 0x5
#define Reserved_6 0x6
#define SSM_IRQ 0x7
#define NMI 0x8
#define SEC_EVNT 0x9
#define Reserved_10 0xA
#define PRCMINT 0xB
#define EDMACOMPINT 0xC
#define EDMAMPERR 0xD
#define EDMAERRINT 0xE
#define WDT0INT 0xF
#define Reserved_16 0x10
#define ADC_TSC_GENINT 0x11
#define USBSSINT 0x12
#define USBINT0 0x13
#define USBINT1 0x14
#define PRU_ICSS_EVTOUT0 0x15
#define PRU_ICSS_EVTOUT1 0x16
#define PRU_ICSS_EVTOUT2 0x17
#define PRU_ICSS_EVTOUT3 0x18
#define PRU_ICSS_EVTOUT4 0x19
#define PRU_ICSS_EVTOUT5 0x1A
#define PRU_ICSS_EVTOUT6 0x1B
#define PRU_ICSS_EVTOUT7 0x1C
#define MMCSD1INT 0x1D*/



/*#define INTC_BASE       						0x48200000
#define INTC_SIR_IRQ    						0x48200040
#define INTC_CONTROL    						0x48200048
#define INTC_ILR        						0x48200100
#define INTC_MIR_CLEAR2 						0x482000C8
#define INTC_MIR_CLEAR3 						0x482000E8
#define INTC_SYSCONFIG							0x48200010
#define INTC_SYSSTATUS							0x48200014
#define INTC_THRESHOLD							0x48200068*/

#endif // _INTERRUPT_H_
