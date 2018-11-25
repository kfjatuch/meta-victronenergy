SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

inherit kernel

COMPATIBLE_MACHINE = "sunxi"

RDEPENDS_kernel-base += "kernel-devicetree"

KERNEL_CONFIG_COMMAND = "oe_runmake -C ${S} O=${B} sunxi_victron_defconfig"

SRC_URI = "https://github.com/victronenergy/linux/archive/v${PV}.tar.gz"
SRC_URI[md5sum] = "1a1db564d21f9170a6e92d672a93f8e4"
SRC_URI[sha256sum] = "0dfceedd005b9f48fc6a728304c84e1f082ec88953d1dcd949c750264707155c"

S = "${WORKDIR}/linux-${PV}"
