/*****************************************************************************
 *****************************************************************************
 *
 * Logging for the SBjsi JavaScript (ECMAScript) Engine Interface
 *
 *****************************************************************************
 ****************************************************************************/

/****************License************************************************
 * Vocalocity OpenVXI
 * Copyright (C) 2004-2005 by Vocalocity, Inc. All Rights Reserved.
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * Vocalocity, the Vocalocity logo, and VocalOS are trademarks or 
 * registered trademarks of Vocalocity, Inc. 
 * OpenVXI is a trademark of Scansoft, Inc. and used under license 
 * by Vocalocity.
 ***********************************************************************/

#ifndef _SBJSI_LOG_H
#define _SBJSI_LOG_H

#include "VXIlog.h"                     /* Logging interface header */
#ifdef __cplusplus
#include "SBjsiLogger.hpp"             /* Logging base class */
#endif

/* Module names for error logging */
#ifndef MODULE_PREFIX
#define MODULE_PREFIX  COMPANY_DOMAIN L"."
#endif

#ifdef OPENVXI
#define MODULE_SBJSI                  MODULE_PREFIX L"OSBjsi"
#define MODULE_SBJSISE                MODULE_PREFIX L"OSBjsiSe"
#define SBJSI_IMPLEMENTATION_NAME     COMPANY_DOMAIN L".OSBjsi"
#define SBJSISE_IMPLEMENTATION_NAME   COMPANY_DOMAIN L".OSBjsiSE"
#else
#define MODULE_SBJSI                  MODULE_PREFIX L"SBjsi"
#define MODULE_SBJSISE                MODULE_PREFIX L"SBjsiSe"
#define SBJSI_IMPLEMENTATION_NAME     COMPANY_DOMAIN L".SBjsi"
#define SBJSISE_IMPLEMENTATION_NAME   COMPANY_DOMAIN L".OSBjsiSE"
#endif

/* Error codes, module specific, see SBjsiErrors.xml for severity/text */
enum JsiError {
  /* SBjsi defined errors, out of service */
  JSI_ERROR_INIT_FAILED = 100,
  JSI_ERROR_INTERFACE_ALLOC_FAILED,
  JSI_ERROR_NULL_INTERFACE_PTR,
  JSI_ERROR_OUT_OF_MEMORY,

  /* SBjsi defined errors, service affecting */
  JSI_ERROR_INVALID_ARG = 200,
  JSI_ERROR_NOT_INITIALIZED,
  JSI_ERROR_USER_EXCEPTION,

  /* SBjsi defined warnings */
  JSI_WARN_MAX_BRANCHES_EXCEEDED = 300,
  JSI_WARN_MAX_STATEMENTS_EXCEEDED,
  
  /* Errors defined by the ECMA-262 3rd Edition language standard */
  JSI_ERROR_ECMA_ERROR = 400,
  JSI_ERROR_ECMA_SYNTAX_ERROR,
  JSI_ERROR_ECMA_REFERENCE_ERROR,
  JSI_ERROR_ECMA_RANGE_ERROR,
  JSI_ERROR_ECMA_TYPE_ERROR,
  JSI_ERROR_ECMA_EVAL_ERROR,
  JSI_ERROR_ECMA_URI_ERROR,

  /* SpiderMonkey errors/warnings */
  JSI_ERROR_SM_SCRIPT_ERROR = 500,    /* Engine error */
  JSI_ERROR_SM_SCRIPT_EXCEPTION,      /* Engine exception */
  JSI_WARN_SM_SCRIPT_WARNING,        /* Engine warning */
  JSI_WARN_SM_SCRIPT_STRICT,         /* Warning due to strict checks being
					 enabled */

  /* Nombas ScriptEase defined errors */
  JSI_ERROR_SE_CONVERSION_ERROR = 600,
  JSI_ERROR_SE_REGEXP_ERROR,
  JSI_ERROR_SE_INTERNAL_ERROR,
  JSI_ERROR_SE_SOURCE_ERROR,
  JSI_ERROR_SE_MATH_ERROR,
  JSI_ERROR_SE_SECURITY_ERROR,
  JSI_ERROR_SE_MEMORY_ERROR,
  JSI_ERROR_SE_SYSTEM_ERROR,
  JSI_ERROR_SE_DSP_ERROR,
  JSI_ERROR_SE_DEBUGGER_ERROR

};

/* Generic diagnostic log tags */
#define SBJSI_LOG_API             0     /* Log all API calls */
#define SBJSI_LOG_CONTEXT         1     /* Log context diagnostics */
#define SBJSI_LOG_GC              2     /* Log garbage collection */
/* #define SBJSI_                 3        currently unallocated */
#define SBJSI_LOG_SCOPE           4     /* Log scope diagnostics */

/* ScriptEase specific diagnostic log tags */
#define SBJSI_LOG_SE_ERRMSGS    200     /* Log ScriptEase error messages */
#define SBJSI_LOG_SE_DEBUGMSGS  201     /* Log debug log messages */

#endif  /* include guard */
