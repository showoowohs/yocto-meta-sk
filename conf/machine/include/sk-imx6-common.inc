# common settings for starterkit imx6 boards
# 2015 macros64@gmail.com

include conf/machine/include/tune-cortexa9.inc

#
# linux kernel
#
PREFERRED_PROVIDER_virtual/kernel = "linux-yocto-sk"
PREFERRED_VERSION_linux-yocto-sk = "3.10"
KERNEL_IMAGETYPE = "zImage"


#
# bootloader
#
PREFERRED_PROVIDER_virtual/bootloader = "u-boot-sk"
PREFERRED_PROVIDER_u-boot = "u-boot-sk"
PREFERRED_VERSION_u-boot-sk = "2014.04%"
UBOOT_SUFFIX = "imx"


# this is default value
#UBOOT_ENTRYPOINT = "0x80008000"
UBOOT_LOADADDRESS = "0x12000000"
UBOOT_LOCALVERSION = "-starterkit"

#
# filesystem image
#
IMAGE_BOOTLOADER = "u-boot-sk"
IMAGE_CLASSES += "image_types_fsl"
SDCARD_ROOTFS = "${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.ext3"
IMAGE_FSTYPES += "tar.bz2 ext3 sdcard"

#
# other settings
#
PREFERRED_PROVIDER_virtual/xserver ?= "xserver-xorg"
XSERVER ?= "xserver-xorg \
           xf86-input-evdev \
           xf86-input-mouse \
           xf86-video-omapfb \
           xf86-input-keyboard"

# Ship all kernel modules by default
MACHINE_EXTRA_RRECOMMENDS = " kernel-modules"
MACHINE_FEATURES = "usbgadget usbhost vfat alsa"

SERIAL_CONSOLE = "115200 ttymxc0"