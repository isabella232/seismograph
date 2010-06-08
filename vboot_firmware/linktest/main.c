#include <stdio.h>

#include "cgptlib.h"
#include "firmware_image_fw.h"
#include "kernel_image_fw.h"
#include "load_firmware_fw.h"
#include "load_kernel_fw.h"
#include "rollback_index.h"
#include "tlcl.h"

int main(void)
{
  uint16_t x, y;

  // cgptlib.h
  GptInit(0);
  GptNextKernelEntry(0, 0, 0);
  GptUpdateKernelEntry(0, 0);

  // firmware_image_fw.h
  VerifyFirmwareHeader(0, 0, 0, 0);
  VerifyFirmwarePreamble(0, 0, 0, 0);
  VerifyFirmwareData(0, 0, 0, 0, 0);
  VerifyFirmware(0, 0, 0);
  GetLogicalFirmwareVersion(0);
  VerifyFirmwareDriver_f(0, 0, 0, 0, 0);

  // kernel_image_fw.h
  VerifyKernelKeyHeader(0, 0, 0, 0, 0, 0);
  VerifyKernelPreamble(0, 0, 0, 0);
  VerifyKernelData(0, 0, 0, 0, 0);
  VerifyKernelHeader(0, 0, 0, 0, 0, 0);
  VerifyKernel(0, 0, 0);
  GetLogicalKernelVersion(0);

  // load_firmware_fw.h
  UpdateFirmwareBodyHash(0, 0);
  LoadFirmware(0);

  // load_kernel_fw.h
  LoadKernel(0);

  // rollback_index.h
  SetupTPM();
  GetStoredVersions(0, &x, &y);
  WriteStoredVersions(0, 0, 0);
  LockFirmwareVersions();
  LockKernelVersionsByLockingPP();

  // tlcl.h
  TlclLibinit();
  TlclStartup();
  TlclSelftestfull();
  TlclDefineSpace(0, 0, 0);
  TlclWrite(0, 0, 0);
  TlclRead(0, 0, 0);
  TlclWriteLock(0);
  TlclReadLock(0);
  TlclAssertPhysicalPresence();
  TlclSetNvLocked();
  TlclIsOwned();
  TlclForceClear();
  TlclSetEnable();
  TlclSetDeactivated(0);
  TlclGetFlags(0, 0);

  return 0;
}
