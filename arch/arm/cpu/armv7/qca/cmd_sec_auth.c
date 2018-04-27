/*
 * Copyright (c) 2018 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <common.h>
#include <asm/arch-ipq40xx/scm.h>

int is_sec_boot_enabled(void)
{
	int ret;
	char buf;

	ret = scm_call(SCM_SVC_FUSE, QFPROM_IS_AUTHENTICATE_CMD, NULL, 0,
				&buf, sizeof(char));

	if (ret == 0 && buf == 1) {
		printf("secure boot fuse is enabled\n");
		return 1;
	}
	else {
		printf("secure boot fuse is not enabled\n");
		return 0;
	}
}

U_BOOT_CMD(is_sec_boot_enabled, 1, 0, is_sec_boot_enabled,
		"check secure boot fuse is enabled or not\n",
		"is_sec_boot_enabled - check secure boot fuse is enabled or not\n");
