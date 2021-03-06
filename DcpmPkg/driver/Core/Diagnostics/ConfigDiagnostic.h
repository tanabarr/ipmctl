/*
 * Copyright (c) 2018, Intel Corporation.
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CONFIG_DIAGNOSTICS_H_
#define CONFIG_DIAGNOSTICS_H_

#include "CoreDiagnostics.h"

typedef struct _BROKEN_IS
{
  UINT16 InterleaveSetIndex;
  DIMM_UNIQUE_IDENTIFIER MissingDimmIdentifier[MAX_DIMMS];
  UINT16 MissingDimmCount;
} BROKEN_IS;

/**
  Run platform configuration diagnostics for the list of DIMMs, and
  appropriately populate the result messages, and test-state.

  @param[in] ppDimms The DIMM pointers list
  @param[in] DimmCount DIMMs count
  @param[in] DimmIdPreference Preference for Dimm ID display (UID/Handle)
  @param[out] ppResult Pointer to the result string of config diagnostics message
  @param[out] pDiagState Pointer to the config diagnostics test state

  @retval EFI_SUCCESS Test executed correctly
  @retval EFI_INVALID_PARAMETER if any of the parameters is a NULL.
**/
EFI_STATUS
RunConfigDiagnostics(
  IN     DIMM **ppDimms,
  IN     CONST UINT16 DimmCount,
  IN     UINT8 DimmIdPreference,
     OUT CHAR16 **ppResult,
     OUT UINT8 *pDiagState
  );
#endif
