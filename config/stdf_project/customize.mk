## framework define
export __STDF__ ?= 1
ifeq ($(__STDF__),1)
KBUILD_CPPFLAGS += -D__STDF__
endif

## general infomation define
export STDF_SW_VERSION ?= 0.0.0.5
export STDF_HW_VERSION ?= 1.0




