SUMMARY = "rootfs to flash an image"

IMAGE_INSTALL = " \
	base-files \
	base-passwd \
	busybox \
	busybox-mdev \
	curl \
	initscripts \
	mtd-utils-ubifs \
	sysvinit \
	swupdate \
	tinylogin \
	u-boot-env-tools \
"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

PR="r1"

IMAGE_CLASSES += " image_types_uboot"
IMAGE_FSTYPES = "ext2.gz.u-boot"
IMAGE_DEVICE_TABLES = "conf/machine/${MACHINE}/device_table.txt"
IMAGE_ROOTFS_SIZE = "32000"

inherit image

python __anonymous() {
	d.delVarFlag('do_unpack', 'noexec')
}

addtask unpack before do_rootfs

SRC_URI = "file://swupdate"

remove_locale_data_files() {
	printf "Post processing local %s\n" ${IMAGE_ROOTFS}${libdir}/locale
	rm -rf ${IMAGE_ROOTFS}${libdir}/locale
}

add_program_instructions() {
	cp ${WORKDIR}/swupdate ${IMAGE_ROOTFS}${sysconfdir}/init.d
}

# remove unneeded pkg informations
ROOTFS_POSTPROCESS_COMMAND += "remove_packaging_data_files ; add_program_instructions ;"
ROOTFS_POSTPROCESS_COMMAND += "remove_locale_data_files ; "