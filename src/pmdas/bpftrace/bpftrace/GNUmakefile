#
# Copyright (c) 2019-2020 Red Hat.
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#

TOPDIR = ../../../..
include $(TOPDIR)/src/include/builddefs

IAM       = bpftrace
PYSCRIPTS = $(shell echo *.py)

MODULEDIR = $(PCP_PMDASADM_DIR)/$(IAM)/bpftrace
MODULETMPDIR = $(PCP_PMDAS_DIR)/$(IAM)/bpftrace

include $(BUILDRULES)

default_pcp default:	$(SUBDIRS)
	$(SUBDIRS_MAKERULE)

install_pcp install:	default $(SUBDIRS)
	$(SUBDIRS_MAKERULE)
	$(INSTALL) -m 755 -d $(MODULEDIR)
	$(INSTALL) -m 755 -d $(MODULETMPDIR)
	$(INSTALL) -m 644 -t $(MODULETMPDIR) $(PYSCRIPTS) $(MODULEDIR)

#check:: $(PYSCRIPTS)
#	$(PYLINT) $^
