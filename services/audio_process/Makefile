
cur_dir := $(dir $(lastword $(MAKEFILE_LIST)))

obj_s := $(patsubst $(cur_dir)%,%,$(wildcard $(cur_dir)*.s))
obj_c := $(patsubst $(cur_dir)%,%,$(wildcard $(cur_dir)*.c))
obj_cpp := $(patsubst $(cur_dir)%,%,$(wildcard $(cur_dir)*.cpp))

obj-y := $(obj_c:.c=.o) $(obj_s:.S=.o) $(obj_cpp:.cpp=.o)

ccflags-y := \
	-Iservices/multimedia/audio/process/filters/include \
	-Iservices/multimedia/audio/process/common/include \
	-Iservices/multimedia/audio/process/drc/include \
	-Iservices/multimedia/audio/process/limiter/include \
	-Iservices/multimedia/speech/inc \
	-Iservices/audio_dump/include \
	-Iservices/nv_section/aud_section \
	-Iservices/nv_section/include \
	-Iutils/heap/ \
	-Iinclude/cmsis_dsp \
	-Iapps/audioplayers \
	-Iutils/crc32

ifeq ($(HW_FIR_EQ_PROCESS),1)
ccflags-y += -D__HW_FIR_EQ_PROCESS__
endif

ifeq ($(HW_IIR_EQ_PROCESS),1)
ccflags-y += -D__HW_IIR_EQ_PROCESS__
endif

ifeq ($(SW_IIR_EQ_PROCESS),1)
ccflags-y += -D__SW_IIR_EQ_PROCESS__
endif

ifeq ($(AUDIO_DRC),1)
ccflags-y += -D__AUDIO_DRC__
endif

ifeq ($(AUDIO_LIMITER),1)
ccflags-y += -D__AUDIO_LIMITER__
endif

ifeq ($(AUDIO_DRC2),1)
ccflags-y += -D__AUDIO_DRC2__
endif

ifeq ($(AUDIO_RESAMPLE),1)
ccflags-y += -D__AUDIO_RESAMPLE__
endif

ifeq ($(HW_DAC_IIR_EQ_PROCESS),1)
ccflags-y += -D__HW_DAC_IIR_EQ_PROCESS__
ifneq ($(filter best2300p best1400 best3001 best2300 best2000 best1000,$(CHIP)),)
ifneq ($(CHIP_SUBTYPE),best1402)
ifeq ($(ANC_APP),1)
$(error "error: ANC and Hardware codec iir can't be used in the same")
endif
endif
endif
endif

ifeq ($(FIR_HIGHSPEED),1)
ccflags-y += -DFIR_HIGHSPEED
endif

ifeq ($(PC_CMD_UART),1)
CFLAGS_audio_process.o += -D__PC_CMD_UART__
endif

ifeq ($(TOTA_EQ_TUNING), 1)
CFLAGS_audio_process.o += -DTOTA_EQ_TUNING
CFLAGS_audio_cfg.o += -DSPEECH_RX_EQ
endif

ifeq ($(SPEECH_LIB),1)
CFLAGS_audio_spectrum.o += -DSPEECH_LIB
endif

ifeq ($(USB_EQ_TUNING), 1)
ccflags-y += -DUSB_EQ_TUNING
endif

CFLAGS_audio_spectrum.o += -DUSE_MED_MALLOC

ifeq ($(AUDIO_DYNAMIC_BOOST),1)
CFLAGS_audio_process.o += -D__AUDIO_DYNAMIC_BOOST__
endif

ifeq ($(AUDIO_OUTPUT_SW_GAIN),1)
CFLAGS_audio_process.o += -DAUDIO_OUTPUT_SW_GAIN
endif

ifeq ($(AUDIO_OUTPUT_SW_GAIN_BEFORE_DRC),1)
CFLAGS_audio_process.o += -DAUDIO_OUTPUT_SW_GAIN_BEFORE_DRC
endif
