cur_dir := $(dir $(lastword $(MAKEFILE_LIST)))

obj-y := $(patsubst $(cur_dir)%,%,$(wildcard $(cur_dir)*.c $(cur_dir)*.cpp $(cur_dir)*.S))
obj-y := $(obj-y:.c=.o)
obj-y := $(obj-y:.cpp=.o)
obj-y := $(obj-y:.S=.o)

subdir-ccflags-y += \
    -Iplatform/drivers/ana \
    -Iservices/ibrt_ui/inc \
    -Iservices/ibrt_core/inc\
    -Iinclude
ifeq ($(NO_WDT),1)
CFLAGS_app_watchdog.o += -DNO_WDT
endif
