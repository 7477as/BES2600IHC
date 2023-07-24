obj-y := stdf_main/ stdf_app/ stdf_bsp/ stdf_hal/ stdf_os/ stdf_sdk/

obj-y += stdf_bsp/key/

#sdk include
subdir-ccflags-y += \
    -Iapps/key \
    -Iplatform/drivers/bt \
    -Iplatform/hal/best1305 \
    -Iservices/app_tws/inc \
    -Iservices/bt_if_enhanced/inc \
    -Iservices/app_ibrt/inc \
    -Iservices/multimedia/audio/codec/sbc/inc \
    -Iservices/nv_section/factory_section \
    -Iservices/tws_ibrt/inc \
    -Iutils/cqueue \
    -Iutils/heap


#stdf include
subdir-ccflags-y += \
    -Iconfig/$(T) \
    -Istdf/stdf_main \
    -Istdf/stdf_app \
    -Istdf/stdf_bsp \
    -Istdf/stdf_bsp/key \
    -Istdf/stdf_hal \
    -Istdf/stdf_os \
    -Istdf/stdf_sdk

