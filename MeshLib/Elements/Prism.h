/**
 * \file
 * \author Thomas Fischer
 * \date   Sep 27, 2012
 * \brief  Definition of the Prism class.
 *
 * \copyright
 * Copyright (c) 2013, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#ifndef PRISM_H_
#define PRISM_H_

#include "TemplatePrism.h"

namespace MeshLib {

typedef TemplatePrism<6, CellType::PRISM6> Prism;

}

#endif /* PRISM_H_ */
