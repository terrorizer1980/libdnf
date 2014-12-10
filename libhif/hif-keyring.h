/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2013 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU Lesser General Public License Version 2.1
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#if !defined (__LIBHIF_H) && !defined (HIF_COMPILATION)
#error "Only <libhif.h> can be included directly."
#endif

#ifndef __HIF_KEYRING_H
#define __HIF_KEYRING_H

#include <glib.h>

#include <rpm/rpmkeyring.h>

#define HIF_KEYRING_GNUPG_HOME_DIR		"/var/lib/rpm/gnupg"

gboolean	 hif_keyring_add_public_key	(rpmKeyring		 keyring,
						 const gchar		*filename,
						 GError			**error);
gboolean	 hif_keyring_add_public_keys	(rpmKeyring		 keyring,
						 GError			**error);
gboolean	 hif_keyring_check_untrusted_file (rpmKeyring		 keyring,
						 const gchar		*filename,
						 GError			**error);

#endif /* __HIF_KEYRING_H */
