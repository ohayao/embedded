# Embedded

## nRF-52832 学习开发
- 拷贝SDK目录（`components config integration modules`）至工程目录
- 拷贝工程目录（`pca10040/s132/config`）放在对应目录下
- 公共类放在 commons
- 项目工程放在 examples (参考官方SDK)
- 默认宏定义
`
BOARD_PCA10040 BSP_DEFINES_ONLY CONFIG_GPIO_AS_PINRESET FLOAT_ABI_HARD NRF52840_XXAA __HEAP_SIZE=8192 __STACK_SIZE=8192
`
- Misc Controls `--reduce_paths`
- Include Paths
`
..\..\..\..\..\commons\led;
..\..\..\..\..\components;
..\..\..\..\..\components\libraries\delay;
..\..\..\..\..\modules\nrfx\hal;
..\..\..\..\..\modules\nrfx;
..\config;
..\..\..\..\..\integration\nrfx;
..\..\..\..\..\components\libraries\util;
..\..\..\..\..\modules\nrfx\drivers;
..\..\..\..\..\components\drivers_nrf\nrf_soc_nosd;
..\..\..\..\..\components\libraries\balloc
`
## 项目
1. 闪灯 `examples/led_blinky`
2. 按键 `examples/buttons`
3. 触摸按键 `examples/touch_button`
4. 蜂鸣器 `examples/beep`
5. GPIOTE 寄存器中断 `examples/gpiote_01`

## GPIOTE 中断模式
### `第一： IN_EVENT`
可以独立配置4个通道，每个通道都有专门的中断标志位，可以任意指管脚和中断触发方式：`上升/下降/翻转`。当检测到对应的电平跳变后，将产生中断，触发`GPIOTE_IRQHandler`函数。
### `第二： PORT_EVENT`
所有GPIO外部中断共用一个中断标志，在GPIOTE模块中，没有多余的参数配置寄存器。要用它实现外部中断，需要在GPIO模块中配置对应的管脚打开SENSE功能，GPIO的这个SENSE功能，是检测GPIO电平，如果满足PIN_CNF[17:16]设置的条件，则将DETECT信号拉高。

这个DETECT信号是内部信号，每个PIN都有一条独立的DETECT信号，而所有的DETECT信号又由系统以[逻辑或]的方式合并为一条通用的DETECT信号，当这条通用的DETECT信号产生上升沿跳变的时候，就会产生一次PORT_EVENT中断。

PORT_EVENT中断方式`功耗极低`，但是却存在多个GPIO冲突的情况，导至中断不能正确地触发。
