SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_spi

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_DRIVERS = st7789_spi # rectangular display
# QUANTUM_PAINTER_DRIVERS = gc9a01_spi # round display

SRC += lvgl_helpers.c \
	   display.c
