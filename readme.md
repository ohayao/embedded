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
..\..\..\..\..\commons\led; //自己编写的类库（commons）
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