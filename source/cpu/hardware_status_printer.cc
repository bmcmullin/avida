//////////////////////////////////////////////////////////////////////////////
// Copyright (C) 1993 - 2004 California Institute of Technology             //
//                                                                          //
// Read the COPYING and README files, or contact 'avida@alife.org',         //
// before continuing.  SOME RESTRICTIONS MAY APPLY TO USE OF THIS FILE.     //
//////////////////////////////////////////////////////////////////////////////

#include "head_cpu.hh"
#include "cHardware4Stack.h"
#include "cHardwareBase.h"
#include "cHardwareCPU.h"
#include "hardware_status_printer.hh"
#include "inst_set.hh"
#include "organism.hh"
#include "string.hh"
#include "string_util.hh"

#include <fstream>

cHardwareStatusPrinter::cHardwareStatusPrinter(ostream &trace_fp)
: m_trace_fp(trace_fp)
{}

const cString & cHardwareStatusPrinter::GetNextInstName(
  cHardwareCPU &hardware
){
  return hardware.GetInstSet().GetName(hardware.IP().GetInst());
}

const cString & cHardwareStatusPrinter::GetNextInstName(
  cHardware4Stack &hardware
){
  return hardware.GetInstSet().GetName(hardware.IP().GetInst());
}

cString cHardwareStatusPrinter::Bonus(const cString &next_name){
  return cStringUtil::Stringf("%s (bonus instruction)", next_name());
}

void cHardwareStatusPrinter::PrintStatus(
  cHardwareBase &hardware,
  const cString &next_name
){
  cOrganism *organism = hardware.GetOrganism();
  if(organism) organism->PrintStatus(m_trace_fp, next_name);
}

void cHardwareStatusPrinter::TraceHardware_CPU(cHardwareCPU &hardware){
  PrintStatus(hardware, GetNextInstName(hardware));
}
void cHardwareStatusPrinter::TraceHardware_4Stack(cHardware4Stack &hardware){
  PrintStatus(hardware, GetNextInstName(hardware));
}
void cHardwareStatusPrinter::TraceHardware_CPUBonus(cHardwareCPU &hardware){
  PrintStatus(hardware, Bonus(GetNextInstName(hardware)));
}
void cHardwareStatusPrinter::TraceHardware_4StackBonus(cHardware4Stack &hardware){
  PrintStatus(hardware, Bonus(GetNextInstName(hardware)));
}
void cHardwareStatusPrinter::TraceHardware_TestCPU(
  int time_used,
  int time_allocated,
  int size,
  const cString &final_memory,
  const cString &child_memory
){
  if (time_used == time_allocated) {
    m_trace_fp << endl << "# TIMEOUT: No offspring produced." << endl;
  }
  else if (size == 0) {
    m_trace_fp << endl << "# ORGANISM DEATH: No offspring produced." << endl;
  }
  else {
    m_trace_fp
    << endl << "# Final Memory: " << final_memory
    << endl << "# Child Memory: " << child_memory << endl;
  }
}
