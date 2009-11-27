// -*-Mode: C++;-*-

// * BeginRiceCopyright *****************************************************
//
// $HeadURL$
// $Id$
//
// -----------------------------------
// Part of HPCToolkit (hpctoolkit.org)
// -----------------------------------
// 
// Copyright ((c)) 2002-2009, Rice University 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// 
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
// 
// * Neither the name of Rice University (RICE) nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
// 
// This software is provided by RICE and contributors "as is" and any
// express or implied warranties, including, but not limited to, the
// implied warranties of merchantability and fitness for a particular
// purpose are disclaimed. In no event shall RICE or contributors be
// liable for any direct, indirect, incidental, special, exemplary, or
// consequential damages (including, but not limited to, procurement of
// substitute goods or services; loss of use, data, or profits; or
// business interruption) however caused and on any theory of liability,
// whether in contract, strict liability, or tort (including negligence
// or otherwise) arising in any way out of the use of this software, even
// if advised of the possibility of such damage. 
// 
// ******************************************************* EndRiceCopyright *

//***************************************************************************
//
// File:
//   $HeadURL$
//
// Purpose:
//   [The purpose of this file]
//
// Description:
//   [The set of functions, macros, etc. defined in the file]
//
//***************************************************************************

//************************* System Include Files ****************************

#include <iostream>

#include <string>
using std::string;

#include <typeinfo>

//*************************** User Include Files ****************************

#include <include/uint.h>

#include "Metric-ADesc.hpp"

#include <lib/support/diagnostics.h>
#include <lib/support/StrUtil.hpp>

//*************************** Forward Declarations **************************


//***************************************************************************

namespace Prof {
namespace Metric {


//***************************************************************************
// ADesc
//***************************************************************************

std::string
ADesc::toString() const
{
  return name();

  //std::ostringstream os;
  //dump(os);
  //return os.str();
}


std::ostream&
ADesc::dumpMe(std::ostream& os) const
{
  os << toString();
  return os;
}


void
ADesc::ddump() const
{
  dump(std::cerr);
  std::cerr.flush();
}


//***************************************************************************
// SampledDesc
//***************************************************************************

std::string
SampledDesc::toString() const
{
  string units = isUnitsEvents() ? " [events]" : " [samples]";
  string xtra = " {" + description() + ":" + StrUtil::toStr(period()) + " ev/smpl}";
  string str = ADesc::toString() + units + xtra;
  return str;
}


std::ostream&
SampledDesc::dumpMe(std::ostream& os) const
{
  os << toString();
  return os;
}


//***************************************************************************
// DerivedDesc
//***************************************************************************

std::string
DerivedDesc::toString() const
{
  string str = ADesc::toString() + " {" + m_expr->toString() + "}";
  return str;
}


std::ostream&
DerivedDesc::dumpMe(std::ostream& os) const
{
  os << toString();
  return os;
}


//***************************************************************************
// DerivedItrvDesc
//***************************************************************************

std::string
DerivedItrvDesc::toString() const
{
  string str = ADesc::toString() + " {" + m_expr->toString() + "}";
  return str;
}


std::ostream&
DerivedItrvDesc::dumpMe(std::ostream& os) const
{
  os << toString();
  return os;
}


//***************************************************************************

} // namespace Metric
} // namespace Prof

